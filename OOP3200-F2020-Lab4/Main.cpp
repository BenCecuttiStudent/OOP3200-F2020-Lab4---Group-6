// Name: Lab 4 - Collections
// Authors: Alexus Girotto(100727793) & 
//          Ben Cecutti(100754039)
// Date: October 10th 2021

#include <ctime>
#include <iostream>
#include "StandardDeck.h"

int main()
{
	/*	Your main() function should demonstrate each of the features of the StandardDeck class*/
	srand(time(nullptr));

	// Create a deck
	std::cout << "  Playing Cards Simulator      "
			  << "\n---------------------------" << std::endl;

	// Show the deck created & show how many cards in a normal deck
	StandardDeck* deck1 = new StandardDeck;
	std::cout << "Deck of " << deck1->CardsRemaining() <<  " cards created\n" << std::endl;

	// Draw the next card and show it
	std::cout << "First Card is a: ";
	deck1->DrawNextCard();

	// Draw a random card and show it
	std::cout << "Random Card is a: ";
	deck1->DrawRandomCard();

	// Show the deck with the remaining cards
	std::cout << "There are " << deck1->CardsRemaining() << " cards remaining" << std::endl;
	
	// Shuffle the deck and show the result
	std::cout << "\nDeck Shuffled!" << std::endl;
	deck1->Shuffle();

	// Show the first card on the shuffled deck
	std::cout << "First Card is a: ";
	deck1->DrawNextCard();

	// Reset the deck and show the result
	deck1->Initialize();
	std::cout << "\nDeck of " << deck1->CardsRemaining() << " cards has been reset" << std::endl;
}