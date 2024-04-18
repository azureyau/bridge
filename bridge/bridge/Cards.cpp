#include <iostream>
#include "Cards.h"

namespace bridge {
	Card::Card(int index, bool played):m_suit{ suits[int(index/13)]}, m_value{index%13}, m_index{index}, m_played(played) {}

	Card& Card::operator=(const Card& rhs){
		if (this != &rhs) {
			m_suit = rhs.m_suit;
			m_value = rhs.m_value;
			m_index = rhs.m_index;
			m_played = rhs.m_played;
		}
		return *this;
	}

	char Card::suit() const{
		return m_suit;
	}

	int Card::suitInt() const{
		return static_cast<int>(m_index/4);
	}

	char Card::value() const{
		return m_value;
	}

	Card::operator int() const{
		return m_index;
	}

	Card::operator bool(){
		return m_played;
	}

	bool Card::operator>(Card& rhs){
		return m_value>rhs.m_value;
	}

	Card& Card::play(){
		m_played = true;
		return *this;
	}

	std::ostream& Card::display(std::ostream& os) const{
		return os << m_suit << rank[m_value]<<' ';
	}

	std::ostream& operator<<(std::ostream& os, const Card& card){
		return card.display(os);
	}

}
