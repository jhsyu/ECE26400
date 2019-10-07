// ***
// *** DO NOT modify this file
// ***

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "shuffle.h"

int main(int argc, char ** argv)
{
  char deck[MAX_SIZE] =
    {'A', '2', '3', '4', '5', '6', '7',
     '8', '9', 'T', 'J', 'Q', 'K'};

  if (argc != 2)
    {
      return EXIT_FAILURE;
    }

  //convert the string argv[1] to a number.
  //argv[1] is the number of the cards.

  //strtol convert the everynumber in a string
  //to a part of the number converted,
  //untill there is a non-number character.
  int size = (int) strtol(argv[1], NULL, 10);

  if ((size <= 0) || (size > MAX_SIZE))
    {
      return EXIT_FAILURE;
    }

  CardDeck origDeck = // one method to initialize attributes
    {
      .size = MAX_SIZE,
      .cards = {0} // set everything to zero right now
    };

  // another way to initialize attribute is
  // origDeck.size = MAX_SIZE;

  origDeck.size = size;

  //apply the real situation to the array cards.
  //origDeck.cards is the address of the array.
  //void * memcpy(void *to, const void *from, size_t numBytes);
  memcpy(origDeck.cards, deck, MAX_SIZE * sizeof(origDeck.cards[0]));

  shuffle(origDeck);

  return EXIT_SUCCESS;
}
