
#include <iostream>
#include "Deck.h"

namespace bridge {
	Deck::Deck(){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				m_cards[i * 4 + j] = Card(i * 4 + j);
			}
		}
	}
	Deck::Deck(const Deck& rhs): m_numCard(rhs.m_numCard){
		for (int i = 0; i < 52; i++) {
			m_cards[i] = rhs.m_cards[i];
		}

	}
}
