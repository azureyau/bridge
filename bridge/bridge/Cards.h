#ifndef BRIDGE_CARD_H
#define BRIDGE_CARD_H

namespace bridge {
	const char suits[4]{ 'S','H','D','C' };
	const char rank[13]{ '2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	class Card {
		int m_index{};
		bool m_played{ false };
		Card() = default; 
		Card(int index, bool played = false);
		friend class Deck;
	public:
		char suit() const;
		int suitInt() const;
		char value() const;
		operator int() const;
		operator bool() const;
		bool operator>(Card& rhs);
		Card& play();
		Card& operator=(const Card& rhs);
		std::ostream& display(std::ostream& os = std::cout) const;
	};
	std::ostream& operator<<(std::ostream& os, const Card& card);
}
#endif //!BRIDGE_CARD_H