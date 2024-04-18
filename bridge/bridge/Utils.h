#ifndef BRIDGE_UTILS_H
#define BRIDGE_UTILS_H

#include <iostream>
#include <cstdlib>
#include <ctime>

namespace bridge {
	class Utils {
	public:
		std::ostream& printSpace(int n, std::ostream& os = std::cout);
	};


	/// <summary>
	/// requrired method for type:
	/// rule of three
	/// </summary>
	/// <typeparam name="type"></typeparam>
	/// <param name="A"></param>
	/// <param name="B"></param>
	/// <returns>referenca of A</returns>
	template<typename type>
	type& swap(type& A, type& B) {
		type temp = A;
		A = B;
		B = temp;
		return A;
	}
	/// <summary>
	/// type should support operator> and rule of three
	/// </summary>
	/// <typeparam name="type"></typeparam>
	/// <param name="array"></param>
	/// <param name="size"></param>
	template<typename type>
	void sortarray(type arr[], int size) {
		for (int i = 1; i < size; i++) {
			type key = arr[i];
			int j = i - 1;
			while (j >= 0 && arr[j] > key) {
				arr[j + 1] = arr[j];
				j = j - 1;	
			}
			arr[j + 1] = key;
		}
	}
	/// <summary>
	/// type has to support rule of three
	/// </summary>
	/// <typeparam name="type"></typeparam>
	/// <param name="arr"></param>
	/// <param name="size"></param>
	template<typename type>
	void shuffleArr(type arr[], int size) {
		srand(static_cast<unsigned int>(time(0)));
		for (int i = 0; i <size; i++) {
			int j = rand() % size;
			swap<type>(arr[i], arr[j]);
		}
	}
	extern Utils U;
}

#endif  //!BRIDGE_UTILS_H