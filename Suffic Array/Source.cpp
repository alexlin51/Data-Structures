#include <iostream>
#include <cstdlib>

#include "Suffix.h"

using namespace std;

int main() {

	suffix test("tehresqbajsdgiqbasdaljs");
	vector<string> Suffix;

	test.findLongest(Suffix);

	for (int i = 0; i != Suffix.size(); i++) {
		cout << Suffix[i] << endl;
	}

	return 0;
}