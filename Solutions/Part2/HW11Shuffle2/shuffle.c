#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

static int power(int base, int power)
{
  for (size_t ind = 0; ind < (power - 2); ind++) {
    base = base * base;
  }
  return base;
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  for (int ind = 0; ind < origDeck.size - 1; ind++) {
    leftDeck[ind].size = ind + 1;
    memcpy(leftDeck[ind].cards, origDeck.cards, leftDeck[ind].size * sizeof(origDeck.cards[0]));
    rightDeck[ind].size = origDeck.size - leftDeck[ind].size;
    memcpy(rightDeck[ind].cards, &origDeck.cards[ind + 1], rightDeck[ind].size * sizeof(origDeck.cards[0]));
  }
  return;
}

int interleavehelp(CardDeck interleaved, CardDeck left, CardDeck right, CardDeck * output, int * index, int i, int j, int k)
{
  //terminating conditions.
  if (i == left.size) {
    for (; k < interleaved.size; k++){
      interleaved.cards[k] = right.cards[j];
      j++;
    }
    memcpy(output[*index].cards, interleaved.cards, interleaved.size * sizeof(interleaved.cards[0]));
    printDeck(interleaved);
    (*index) ++;
    return (*index);
  }
  if (j == right.size) {
    for (; k < interleaved.size; k++) {
      interleaved.cards[k] = left.cards[i];
      i++;
    }
    memcpy(output[*index].cards, interleaved.cards, interleaved.size * sizeof(interleaved.cards[0]));
    printDeck(interleaved);
    (*index) ++;
    return (*index);
  }
  //choose one card from the left deck.
  interleaved.cards[k] = left.cards[i];
  interleavehelp(interleaved, left, right, output, index, (i + 1), j, (k + 1));
  //choose one card from the right deck.
  interleaved.cards[k] = right.cards[j];
  interleavehelp(interleaved, left, right, output, index, i, (j + 1), (k + 1));
  return (*index);
}
void interleave(CardDeck leftDeck, CardDeck rightDeck, CardDeck * output)
{
  //the argument are a pair of element in ldk and rdk.
  //they contain the info about the size of each deck,
  //and the card in decks.
  //for example, ldk.size and ldk.cards = {A, 2}
  CardDeck interleavedDeck =
  {
    .size = leftDeck.size + rightDeck.size,
    .cards = {0}
  };
  int index = interleavehelp(interleavedDeck, leftDeck, rightDeck, output, &index, 0, 0, 0);

}
// about shuffle:
// 1. shuffle for the first turn.
// 2. divide the card deck from the 1st shuffle.

//    because the number of card dosnot change,
//    posbNumD does not change.
//    only the order of origDeck changes (shuffleOut)

//    because divide need a "origDeck" input, so there should be a place
//    storing the output from the last shuffle (shuffleOut).

// if there are k cards, there are 2^k - 2 kinds interleaved decks.
// (the size of shuffleOut)

// because there is a need of interleave output, add a new * argument.

// 3. interleave using the updated ldk and rdk.
//    because there is a posibility that no change made on origDeck
//    all the possible shuffle output can appear in the next shuffle.
//    hence, don't worry about the previous output.

// 4. take the outcome from the interleave function as the input of next shuffle.
//
void shuffleHelp(CardDeck origDeck, int round, int posbNumD, int num, int ind)
{
  if (ind == round) {
    return ;
  }
  CardDeck * ldk = malloc(posbNumD * sizeof(CardDeck));
  CardDeck * rdk = malloc(posbNumD * sizeof(CardDeck));
  CardDeck * shuffleOut = malloc(num * sizeof(CardDeck));
  divide(origDeck, ldk, rdk);
  for (size_t i = 0; i < posbNumD; i++) {
    // need add an argumrnt in "interleave" to write the output to an array.
    interleave(ldk[i], rdk[i], shuffleOut);
  }
  for (size_t i = 0; i < posbNumD; i++) {
    shuffleHelp(shuffleOut[i], round, posbNumD, num, ind + 1);
  }
  free(ldk);
  free(rdk);
  free(shuffleOut);
}

void shuffle(CardDeck origDeck, int round)
{
  int posbNumD = origDeck.size - 1;
  int num = power(2, origDeck.size) - 2;
  shuffleHelp(origDeck, round, posbNumD, num, 0);
}
