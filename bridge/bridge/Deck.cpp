#include <iostream>
#include "Deck.h"

namespace bridge {
	Deck::Deck(){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				m_cards[i * 13 + j] = Card(i * 13 + j);
			}
		}
	}
	Deck::Deck(const Deck& rhs){
		for (int i = 0; i < 52; i++) {
			m_cards[i] = rhs.m_cards[i];
		}

	}
	Deck& Deck::operator=(const Deck& rhs)
	{
		if (this != &rhs) {
			for (int i = 0; i < 52; i++) {
				m_cards[i] = rhs.m_cards[i];
			}
		}
		return *this;
	}
	std::ostream& Deck::display(std::ostream& os)const {
		for (int i = 0; i < 52; i++) {
			m_cards[i].display();
		}
		return os;
	}
	std::ostream& operator<<(std::ostream& os, const Deck& deck) {
		return deck.display(os);
	}
}
