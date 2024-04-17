#ifndef BRIDGE_CARD_H
#define BRIDGE_CARD_H

namespace bridge {
	const char suits[4]{ 'S','H','D','C' };
	const char rank[13]{ '2','3','4','5','6','7','8','9','T','J','Q','K','A'};
	class Card {
		char m_suit{};
		int m_value{};
		int m_index{};
		bool m_played{ false };
		Card() = default; 
		Card(int index, bool played = false);
		friend class Deck;
		Card& operator=(const Card& rhs);
	public:
		char suit() const;
		char value() const;
		operator int() const;
		operator bool();
		bool operator>(Card& rhs);
		Card& play();
		std::ostream& display(std::ostream& os = std::cout) const;
	};
	std::ostream& operator>>(std::ostream& os, const Card& card);
}
#endif //!BRIDGE_CARD_H