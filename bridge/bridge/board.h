#ifndef BRIDGE_BOARD_H
#define BRIDGE_BOARD_H

#include <array>
#include"Deck.h"

namespace bridge {
	extern const char seats[4];
	extern bool showCount;
	class Board: public Deck{
	protected:
		int m_hands[4][13];
	private:
		int m_suitCount[4][4];
		std::array<int, 4> m_hcp{};
	public:
		Board();
		virtual ~Board() = default;
		Board(const Board& rhs);
		Board& generate();
		Board& handEvaluate();
		Board& shuffling();
		int hcp(int position)const;
		int suitCount(int position,int suit) const;
		std::ostream& printSuit(int position, int suitIndex, std::ostream& os = std::cout) const;
		std::ostream& printEvaluation(int position, std::ostream& os = std::cout)const;
		virtual std::ostream& display(std::ostream& os) const;
	};
}
#endif //!BRIDGE_BOARD_H