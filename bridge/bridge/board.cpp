
#include "board.h"
#include "Utils.h"
#define DISPLAYWIDTH 20
using namespace std;


namespace bridge{
	const char seats[4] = { 'N','E','S','W' };
	bool showCount = true;
	Board::Board():Deck(){	
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				m_hands[i][j] = i * 13 + j;
			}
		}
		handEvaluate();
	}

	Board::Board(const Board& rhs): Deck(rhs){
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				m_hands[i][j] = rhs.m_hands[i][j];
			}
			m_hcp[i] = rhs.m_hcp[i];
			for (int j = 0; j < 4; j++) {
				m_suitCount[i][j] = rhs.m_suitCount[i][j];
			}
		}
	}

	Board& Board::generate(){
		shuffling();
		for (int i = 0; i < 4; i++) {
			sortarray(&m_hands[i][0],13);
		}
		return this->handEvaluate();
	}

	Board& Board::handEvaluate(){
		for (int i = 0; i < 4; i++) {
			m_hcp[i] = 0;
			for (int j = 0; j < 4; j++) {
				m_suitCount[i][j] = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				m_suitCount[i][m_hands[i][j]/13]++;
				int hcp = m_hands[i][j] % 13 - 8;
				m_hcp[i] += (hcp > 0 ? hcp : 0);
			}
		}
		return *this;
	}
	
	Board& Board::shuffling(){
		int* indexArr = new int[52];

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				indexArr[i * 13 + j] = m_hands[i][j];
			}
		}
		shuffleArr(&indexArr[0], 52);
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 13; j++) {
				m_hands[i][j] = indexArr[i * 13 + j];
			}
		}
		delete[] indexArr;
		return *this;
	}

	int Board::hcp(int position) const{
		return m_hcp[position];
	}
	int Board::suitCount(int position,int suit) const {
		return m_suitCount[position][suit];
	}

	std::ostream& Board::printSuit(int position, int suitIndex, std::ostream& os) const{
		int i = 12;
		int counter = 0;
		os << suits[suitIndex]<<" ";
		while (i >= 0 && m_hands[position][i] >= (suitIndex + 1) * 13) {
			i--;
		}
		while (i >=0 && m_hands[position][i] >= suitIndex  * 13) {
			os << rank[m_hands[position][i] % 13];
			i--;
			counter++;
		}
		os.width(DISPLAYWIDTH - 1 - counter);
		return os << ' ';
	}

	std::ostream& Board::printEvaluation(int position, std::ostream& os) const{
		int counter{};
		os << "hcp:";
		os.width(2);
		os<<m_hcp[position] << " ";

		for (int i = 0; i < 4; i++) {
			os << m_suitCount[position][i];
			if (m_suitCount[position][i] > 10)
				counter++;
		}
		os.width(DISPLAYWIDTH - 12-counter);
		os << " ";
		return os;
	}

	ostream& Board::display(ostream& os) const{
		//print North
		os.width(DISPLAYWIDTH);
		os << ' ';
		os << seats[0] << ".";
		if (showCount) {
			printEvaluation(0, os);
		}
		os << endl;
		for (int i = 0; i < 4; i++) {
			os.width(DISPLAYWIDTH);
			os<< ' ';
			printSuit(0, i, os) << endl;
		}
		//Print W-E
		os << seats[3] << ".";
		if (showCount) {
			printEvaluation(3, os);
		}
		else {
			os.width(DISPLAYWIDTH);
			os << ' ';
		}
		os.width(DISPLAYWIDTH);
		os << ' ';
		cout<< seats[1] << ".";
		if (showCount) {
			printEvaluation(1, os);
		}
		os << endl;
		for (int i = 0; i < 4; i++) {
			printSuit(3, i);
			os.width(DISPLAYWIDTH);
			os << ' ';
			printSuit(1, i) << endl;
		}
		os << endl;
		///print South
		os.width(DISPLAYWIDTH);
		os << ' ';
		os << seats[2] << ".";
		if (showCount) {
			printEvaluation(2,os);
		}
		os << endl;
		for (int i = 0; i < 4; i++) {
			os.width(DISPLAYWIDTH) ;
			os<<' ';
			printSuit(2, i, os) << endl;
		}
		return os;
	}

}