#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>


void interleavehelp(CardDeck interleaved,CardDeck left, CardDeck right, int i, int j, int k)
{
  //terminating conditions.
  if (k == interleaved.size) {
    printDeck(interleaved);
    return;
  }
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

void shuffle(CardDeck origDeck, int round)
{
  int posbNumD = origDeck.size - 1;
  CardDeck * ldk = malloc(posbNumD * sizeof(CardDeck));
  CardDeck * rdk = malloc(posbNumD * sizeof(CardDeck));
  divide(origDeck, ldk, rdk);
  for (int ind = 0; ind < posbNumD; ind++) {
    interleave(ldk[ind], rdk[ind]);
  }
  free(ldk);
  free(rdk);
}
