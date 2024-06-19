#include "play.h"

namespace bridge {
	Play::Play():Board() {
		generate();
	}

	Play::Play(const Play& rhs) : Board(rhs),
		m_leadPo(rhs.m_leadPo), m_playPo(rhs.m_playPo), m_numCardPlayed(rhs.m_numCardPlayed), m_trickNS(rhs.m_trickNS) {
		m_playSeq = rhs.m_playSeq;

	}

	Play& Play::playCard(int index) {
		m_cards[index].play();
		m_playSeq[(m_numCardPlayed++)] = index;
		m_playPo++;
		m_playPo %= 4;
		if (m_numCardPlayed % 4 == 0) {
			determineTrick();
		}

		////debug output
		//display();
		//std::cin.ignore();

		////
		return *this;
	}

	int Play::analyse() {
		int tempresult, result = -1;
		if (m_numCardPlayed == 52) {
			return m_trickNS;
		}
		for (int i = 0; i < 13; i++) {
			if (!m_cards[m_hands[m_playPo][i]] &&
				cardLegal(m_cards[m_hands[m_playPo][i]])
				&& !eqCard(m_playPo, m_hands[m_playPo],i)) 
			{
				Play temp = *this;
				tempresult = temp.playCard(m_hands[m_playPo][i]).analyse();
				if (result == -1 || (tempresult > result && m_playPo % 2 == 0) || (tempresult < result && m_playPo % 2 == 1)) {
					result = tempresult;
					std::cout << result;////debug output
				}
			}
		}
		//std::cin.ignore();
		return result;
	}

	bool Play::eqCard(int position, int handArr[],int index) const {///////////////////////////TBD
		//find the index of the one upper unplayed card of the same player
		int unplayedIndex{-1};
		std::cout << "in eqCard";
		for (int i = index; i >= 0 && unplayedIndex==-1; i--) {
			if (!m_cards[handArr[i]]) {
				std::cout << "unplayedIndex= " << handArr[i]<<std::endl;//////////debug output
				unplayedIndex = handArr[i];
			}
		}
		if (unplayedIndex == -1) { 
			return false; 
		}
		//check if any card is unplayed between the current card and upper card
		if (m_cards[unplayedIndex].suit() == m_cards[handArr[index]].suit()) {
			for (int i = unplayedIndex + 1; i < handArr[index]; i++) {
				std::cout << i<<' ';
				if (!m_cards[i]) {
					return false;
				}
			}
		}
		std::cout << m_cards[handArr[index]] << "is eq card";
		return true;
		
	}

	bool Play::card1win(const Card& card1, const Card& card2, char currentSuit) const {
		int left{}, right{};
		left += (card1.suitInt() == m_trump ? 100 : 0);
		right += (card2.suitInt() == m_trump ? 100 : 0);

		left += (card1.suit() == currentSuit ? 50 : 0);
		right += (card2.suit() == currentSuit ? 50 : 0);
		left += card1.value();
		right += card2.value();
		return left > right;
	}

	Play& Play::determineTrick() {
		int winner = m_playSeq[m_numCardPlayed - 4];
		int winPo = m_leadPo;
		for (int i = 1; i < 4; i++) {
			if (card1win(m_cards[m_playSeq[m_numCardPlayed - 4 + i]], m_cards[winner], m_cards[winner].suit())) {
				winner = m_playSeq[m_numCardPlayed - 4 + i];
				winPo = (m_leadPo + i) % 4;
			}
		}
		if (winPo % 2 == 0) {
			m_trickNS++;
		}
		m_leadPo = winPo;
		m_playPo = m_leadPo;
		//////debug output
		/*display();
		std::cout << std::endl << "winning:" << m_cards[winner];
		std::cout << std::endl << "by:" << seats[ m_leadPo];
		std::cin.ignore();*/

		/////
		return *this;
	}

	bool Play::cardLegal(Card& card) {

		bool onLead = (m_numCardPlayed % 4 == 0);
		if (onLead)
			return true;
		int leadedSuit = m_cards[m_playSeq[m_numCardPlayed-(m_numCardPlayed%4)]].suitInt();
		return (leadedSuit == card.suitInt() || suitCount(m_playPo, leadedSuit));
	}

	std::ostream& Play::display(std::ostream& os) const{
		Board::display(os);

		for (int i = 0; i < 13; i++) {
			os << i + 1 << " ";
			for (int j = 0; j < 4 && i*4+j< m_numCardPlayed; j++) {
				os << m_cards[m_playSeq[i*4+j]];
			}
			os << std::endl;
		}
		os << std:: endl << "NS took trick:" << m_trickNS;
		return os;
	}

	int Play::trickNo() const{
		return m_numCardPlayed/4;
	}

}
