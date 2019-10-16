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

void interleavehelp(CardDeck interleaved,CardDeck left, CardDeck right, int round, int i, int j, int k)
{
  //terminating conditions.
  if (i == left.size) {
    for (; k < interleaved.size; k++){
      interleaved.cards[k] = right.cards[j];
      j++;
    }
    printDeck(interleaved);
    shuffle(interleaved, round - 1);
    return;
  }
  if (j == right.size) {
    for (; k < interleaved.size; k++) {
      interleaved.cards[k] = left.cards[i];
      i++;
    }
    printDeck(interleaved);
    shuffle(interleaved, round -1);
    return;
  }
  //choose one card from the left deck.
  interleaved.cards[k] = left.cards[i];
  interleavehelp(interleaved, left, right, round, (i + 1), j, (k + 1));
  //choose one card from the right deck.
  interleaved.cards[k] = right.cards[j];
  interleavehelp(interleaved, left, right, round, i, (j + 1), (k + 1));

}
void interleave(CardDeck leftDeck, CardDeck rightDeck, int round)
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
  interleavehelp(interleavedDeck, leftDeck, rightDeck, round, 0, 0, 0);

}

// The shuffle function has the following steps:

// 1. calculate the number of possible left and right decks. It is
// the number of cards - 1 because the left deck may have 1, 2,...,
// #cards - 1 cards.
//
// 2. allocate memory to store these possible pairs of left and right
// decks.
//
// 3. send each pair to the interleave function
//
// 4. release allocated memory
//
void shuffle(CardDeck origDeck, int round)
{
  if (round == 0) {
    return;
  }
  int posbNumD = origDeck.size - 1;
  CardDeck * ldk = malloc(posbNumD * sizeof(CardDeck));
  CardDeck * rdk = malloc(posbNumD * sizeof(CardDeck));
  divide(origDeck, ldk, rdk);
  for (int ind = 0; ind < posbNumD; ind++) {
    interleave(ldk[ind], rdk[ind], round);
  }
  free(ldk);
  free(rdk);
}
