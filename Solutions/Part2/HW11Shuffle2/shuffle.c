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

int power(int base, int power)
{
  for (size_t i = 0; i < power - 2; i++) {
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

void interleavehelp(CardDeck interleaved,CardDeck left, CardDeck right, int i, int j, int k)
{
  //terminating conditions.
  /*  unnecessary.
  if (k == interleaved.size) {
    printDeck(interleaved);
    return;
  }*/
  if (i == left.size) {
    for (; k < interleaved.size; k++){
      interleaved.cards[k] = right.cards[j];
      j++;
    }
    printDeck(interleaved);
    return;
  }
  if (j == right.size) {
    for (; k < interleaved.size; k++) {
      interleaved.cards[k] = left.cards[i];
      i++;
    }
    printDeck(interleaved);
    return;
  }
  //choose one card from the left deck.
  interleaved.cards[k] = left.cards[i];
  interleavehelp(interleaved, left, right, (i + 1), j, (k + 1));
  //choose one card from the right deck.
  interleaved.cards[k] = right.cards[j];
  interleavehelp(interleaved, left, right, i, (j + 1), (k + 1));

}

void interleave(CardDeck leftDeck, CardDeck rightDeck)
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
  interleavehelp(interleavedDeck, leftDeck, rightDeck, 0, 0, 0);

}
void shuffleHelp(CardDeck origDeck, int round, CardDeck ** ldkptr, CardDeck ** rdkptr, CardDeck ** output, int posbWay, int posbNumD, int index)
{
    ldkptr[index] = malloc(posbNumD * sizeof(CardDeck));
    rdkptr[index] = malloc(posbNumD * sizeof(CardDeck));
    output[index] = malloc(posbWay * sizeof(CardDeck));
    divide(origDeck, *ldkptr[index], *rdkptr[index]);
    for (size_t ind = 0; ind < posbNumD; ind++) {
      interleave(ldkptr[index][ind], rdkptr[index][ind], &output[index][ind]);
    }
    for (size_t ind = 0; ind < posbWay; ind++) {
      shuffleHelp(output[index][ind], round, ldkptr, rdkptr, output, index + 1);
    }
    free(ldkptr[index]);
    free(rdkptr[index]);
    free(output[index]);
    //NEED TO DO: ADD A ARGUMRNT TO INTERLEAVE.   
}
void shuffle(CardDeck origDeck, int round)
{
  int posbNumD = origDeck.size - 1;
  int posbWay = power(2, origDeck.size) - 2;
  CardDeck ** ldkptr;
  CardDeck ** rdkptr;
  CardDeck ** output;
  shuffleHelp(origDeck, round, ldkptr, rdkptr, output, 0);

}
