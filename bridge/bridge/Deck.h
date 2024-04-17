#ifndef BRIDGE_DECK_H
#define BRIDGE_DECK_H

#include <iostream>
#include "Cards.h"

namespace bridge {
	class Deck {

	protected:
		Card m_cards[52];
		Deck();
		Deck(const Deck& rhs);
	public:
		Deck& operator=(const Deck& rhs);
		virtual ~Deck() = default;
		virtual std::ostream& display(std::ostream& os = std::cout)const;
	};
	std::ostream& operator<<(std::ostream& os, const Deck& deck);
}
#endif