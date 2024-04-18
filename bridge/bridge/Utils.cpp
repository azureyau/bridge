#include "Utils.h"

namespace bridge {
	std::ostream& Utils::printSpace(int n, std::ostream& os){
		for (int i = 0; i < n; i++) {
			os << ' ';
		}
		return os;
	}
	
}