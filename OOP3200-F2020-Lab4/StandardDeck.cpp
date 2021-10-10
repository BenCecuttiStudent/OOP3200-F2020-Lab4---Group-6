// Name: Lab 4 - Collections
// Authors: Alexus Girotto(100727793) & 
//          Ben Cecutti(100754039)
// Date: October 10th 2021
#include "StandardDeck.h"
#include <iostream>
#include <algorithm>
StandardDeck::StandardDeck()
{
	m_deck.begin();
	Initialize();
}

void StandardDeck::Initialize()
{
	// If the deck isn't empty clear it
	if(!m_deck.empty())
	{
		m_deck.clear();
		for (int suit = 0; suit <= 3; suit++)
		{
			for (int rank = 1; rank <= 13; rank++)
			{
				auto tempCard = new PlayingCard;
				tempCard->SetSuit(suit);
				tempCard->SetRank(rank);
				m_deck.push_back(*tempCard);
				
			}
		}
	}
	else
	{
		for (int suit = 0; suit <= 3; suit++)
		{
			for (int rank = 1; rank <= 13; rank++)
			{
				auto tempCard = new PlayingCard;
				tempCard->SetSuit(suit);
				tempCard->SetRank(rank);
				m_deck.push_back(*tempCard);
			}
		}
	}
}

StandardDeck::~StandardDeck()
= default;

StandardDeck::StandardDeck(const StandardDeck& deck2)
{
	for (int i = 0; i < deck2.m_deck.size(); i++)
	{
		m_deck.push_back(m_deck[i]);
	}
}

StandardDeck& StandardDeck::operator=(const StandardDeck& deck2)
{
	for (int i = 0; i < deck2.m_deck.size(); i++)
	{
		m_deck.push_back(m_deck[i]);
	}
	return *this;
}


int StandardDeck::CardsRemaining() const
{
	return m_deck.size();
}

PlayingCard StandardDeck::DrawNextCard()
{
	// Deal the top card & get rid of it from the deck
	PlayingCard tempCard = m_deck.at(0);
	ShowCard(tempCard);
	m_deck.erase(m_deck.begin());
	return tempCard;
}

PlayingCard StandardDeck::DrawRandomCard()
{
	// Deal a random card & get rid of it from the deck
	const int num = rand() % m_deck.size();
	PlayingCard tempCard = m_deck[num];
	ShowCard(tempCard);
	m_deck.erase(m_deck.begin()+num);
	return tempCard;
}

// Last thing that needs to be done //
void StandardDeck::Shuffle()
{
	for (int x = 0; x <= this->CardsRemaining(); x++)
	{
		const int num = rand() % m_deck.size();
		std::cout << x << ": ";
		PlayingCard tempCard = m_deck[num];
		ShowCard(tempCard);
	}
}

// Output card info neatly
void StandardDeck::ShowCard(const PlayingCard card)
{
	std::cout << card.GetRank() << " of " << card.GetSuit() << std::endl;
}