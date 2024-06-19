#ifndef BRIDGE_PLAY_H
#define BRIDGE_PLAY_H
#include "Board.h"
namespace bridge {
	class Play : public Board {
		std::array<int, 52> m_playSeq{};
		int m_trump{-1};
		int m_playPo{ 3};
		int m_leadPo{3};
		int m_numCardPlayed{};
		int m_trickNS{};

	public:
		virtual ~Play() = default;
		Play();
		Play(const Play& rhs);
		Play& playCard(int i);
		int analyse();
		bool eqCard(int position, int handarr[], int current_index) const;
		bool card1win(const Card& card1, const Card& card2, char currentSuit)const;
		Play& determineTrick();
		bool cardLegal(Card& card);
		std::ostream& display(std::ostream& os = std::cout)const;
		int trickNo() const;
	};
}

#endif BRIDGE_PLAY_H