#include <iostream>
#include <sstream>
#include <string>

#include "isBounded.h"	

using namespace std;

int main() {

	string test = "}{[]][())(";


	bool answer = isBounded(test);

	if (answer == true) {
		cout << "true";
	}
	else {
		cout << "false";
	}

}