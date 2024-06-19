#include <iostream>
#include "Cards.h"

namespace bridge {
	Card::Card(int index, bool played): m_index{index}, m_played(played) {}

	Card& Card::operator=(const Card& rhs){
		if (this != &rhs) {
			m_index = rhs.m_index;
			m_played = rhs.m_played;
		}
		return *this;
	}


	char Card::suit() const{
		return suits[m_index/13];
	}

	int Card::suitInt() const{
		return static_cast<int>(m_index/13);
	}

	char Card::value() const{
		return m_index % 13;
	}

	Card::operator int() const{
		return m_index;
	}

	Card::operator bool() const{
		return m_played;
	}

	bool Card::operator>(Card& rhs){
		return m_index > rhs.m_index;
	}

	Card& Card::play(){
		m_played = true;
		return *this;
	}

	

	std::ostream& Card::display(std::ostream& os) const{
		return os << suit() << rank[m_index % 13] << ' ';
	}

	std::ostream& operator<<(std::ostream& os, const Card& card){
		return card.display(os);
	}


}
