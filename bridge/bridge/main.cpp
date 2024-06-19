#include<iostream>
#include "Play.h"

using namespace std;
using namespace bridge;

int main(){
	//int result;
	/*Board d;
	cout << d.generate();*/
	//result= d.analyse();
	//cout << result;

	Play p;
	Board* b= &p;
	cout << *b;
	cout << p.analyse();
	return 0;
}
