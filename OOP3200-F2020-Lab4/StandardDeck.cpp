#include "StandardDeck.h"

StandardDeck::StandardDeck()
{
	m_deck.push_back(0);
	Initialize();
}

void StandardDeck::Initialize()
{
	for(int suit = 0; suit < 3; suit++)
	{
		for(int rank = 0; rank < 13; rank++)
		{
			PlayingCard* tempCard;
			tempCard->SetSuit(suit);
			tempCard->SetRank(rank);

			m_deck.push_back(tempCard);
		}
	}

}

StandardDeck::~StandardDeck()
= default;

StandardDeck::StandardDeck(const StandardDeck& deck2)
{
	// SetDeck(deck2.GetDeck);
	// Have to find a way to set up vector getters and setters
}

StandardDeck& StandardDeck::operator=(const StandardDeck& deck2)
{
	// SetDeck(deck2.GetDeck);
	// return *this;
}


int StandardDeck::CardsRemaining()
{
	return m_deck.size();
}

PlayingCard StandardDeck::DrawNextCard()
{

}

PlayingCard StandardDeck::DrawRandomCard()
{
	int randNum;
	randNum = rand() % this->CardsRemaining() + 1;

	PlayingCard tempCard;
	tempCard = m_deck[randNum];
	m_deck.erase(m_deck.begin()+randNum);

	return tempCard;
}


void StandardDeck::Shuffle()
{
	for (int x = this->CardsRemaining(); x > 1; x--) // might have to make sure this loop is looping correctly
	{
		m_deck.push_back(this->DrawRandomCard());
	}
}
