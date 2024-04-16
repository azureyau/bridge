#ifndef BRIDGE_DECK_H
#define BRIDGE_DECK_H

#include <iostream>
#include "Cards.h"

namespace bridge {
	class Deck {
		Card m_cards[52];
		int m_numCard{ 52 };
	public:
		Deck();
		Deck(const Deck& rhs);
		virtual ~Deck() = default;
	};
}

#endif