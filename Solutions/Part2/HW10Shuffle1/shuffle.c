// ***
// *** You must modify this file
// ***

#include "shuffle.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// do not modify this function
static void printDeck(CardDeck deck)
{
  int ind;
  for (ind = 0; ind < deck.size; ind ++)
    {
      printf("%c ", deck.cards[ind]);
    }
  printf("\n");
}

#ifdef TEST_DIVIDE
// leftDeck and rightDeck are arrays of CardDeck
// This function creates pairs of left and right decks
// Each pair divides the original deck into two non-overlapping decks and
// together they form the original deck.
//
// You can think of the left deck held by the left hand taking some
// cards (at least one) from the top of the original deck.
//
// The right deck is held by the right hand taking some (at least one)
// cards from the bottom of the original deck.
void dividehelp(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck, int * sign, int i, int j, int k)
{
  if (k == origDeck.size) {
    for (int ind = k; ind < origDeck.size; ind--) {
      if (sign[ind] == 0) {
        leftDeck->cards[ind]
      }
    }
  }
}

void divide(CardDeck origDeck, CardDeck * leftDeck, CardDeck * rightDeck)
{
  //creatre a sign aray and initialize it to zero.
  //zero is unchosen, -1 is left, 1 is right.
  int * sign = malloc(sizeof(int) * origDeck.size);
  sign = {0};
  for (int ind = 0; i < count; i++) {
    /* code */
  }

}
#endif

#ifdef TEST_INTERLEAVE

// Interleave two decks to generate all possible results.
//
// If the leftDeck is {'A'} and the right deck is {'2', '3'}, this
// function prints
// A 2 3
// 2 A 3
// 2 3 A
//
// If the leftDeck is {'A', '2'} and the right deck is {'3', '4'}, this
// function prints
// 3 4 A 2
// 3 A 4 2
// A 3 4 2
// 3 A 2 4
// A 3 2 4
// A 2 3 4
//
// Please notice the space does not matter because grading will use
// diff -w
//
// How to generate all possible interleaves?

// Understand that a card at a particular position can come from
// either left or right (two options). The following uses left for
// explanation but it is equally applicable to the right.
//
// After taking one card from the left deck, the left deck has one
// fewer card. Now, the problem is the same as the earlier problem
// (thus, this problem can be solved by using recursion), excecpt one
// left card has been taken. Again, the next card can come from left
// or right.
//
// This process continues until either the left deck or the right deck
// runs out of cards. The remaining cards are added to the result.
//
// It is very likely that you want to create a "helper" function that
// can keep track of some more arguments.  If you create a helper
// function, please keep it inside #ifdef TEST_INTERLEAVE and #endif
// so that the function can be removed for grading other parts of the
// program.
void interleavehelp(CardDeck interleaved,CardDeck left, CardDeck right, int i, int j, int k)
{
  //terminating conditions.
  if (k == interleaved.size {
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
    .size = leftDeck.size + rightDeck.size;
    .cards = {0};
  }
  interleavehelp(interleavedDeck, leftDeck, rightDeck, 0, 0, 0);

}
#endif

#ifdef TEST_SHUFFLE
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
void shuffle(CardDeck origDeck)
{
  int posbNumD = origDeck.size - 1;
  int * ldk = malloc(posbNumD * sizeof(CardDeck));
  int * rdk = malloc(posbNumD * sizeof(CardDeck));
  divide(origDeck, ldk, rdk);
  for (int ind = 0; i < posbNumD; i++) {
    interleave(ldk[ind], rdk[ind]);
  }
  free(ldk);
  free(rdk);
}
#endif
