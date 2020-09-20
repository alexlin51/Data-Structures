#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include "Suffix.h"

using namespace std;

int suffix::compare(string current, string next) {
	int count = 0;
	int i = 0;
	while (current[i] == next[i]) {
		count++;
		i++;
	}

	return count;
}

void suffix::createList() {
	// we want to pushback the longest suffix, for the case where there are multiple, we will push back several of them.
	// we want to create the comparison array
	comparison.push_back(0);
	for (int i = 0; i != suffixList.size() - 1; i++) {
		string current = recreate(suffixList[i]);
		string next = recreate(suffixList[i + 1]);

		// we need to compare how long the current similar values are.
		int similar = compare(current, next);
		comparison.push_back(similar);
	}

}

suffix::suffix(string input) {
	// we need to inialize the suffixList
	given = input;
	// lets first generate a vector that holds the actual listing of ordered suffix
	vector<string> StringSuf;

	int size = input.size();

	for (int i = 0; i != size; i++) {
		string base = "";
		for (int j = size; j != i; j--) {
			base.push_back(input[i + size - j]);
		}
		StringSuf.push_back(base);
	}

	// we have now generated the list, we need to place in order!
	sort(StringSuf.begin(), StringSuf.end());


	// now that we have generated the list, lets create the append on the order for the suffixList;
	for (int i = 0; i != StringSuf.size(); i++) {
		string current = StringSuf[i];
		int currentSize = current.size();
		int startIndex = size - currentSize;
		
		suffixList.push_back(startIndex);
	}

	// generated the list!
	createList();
}

void suffix::showSufIndex() {
	for (int i = 0; i != suffixList.size(); i++) {
		cout << suffixList[i] << " ";
	}
}

string suffix::recreate(int index) {
	string create;
	for (int i = 0; i != given.size() - (index); i++) {
		create.push_back(given[index + i]);
	}

	return create;
}

void suffix::showComList() {
	for (int i = 0; i != comparison.size(); i++) {
		cout << comparison[i] << " ";
	}
}

string suffix::returnOriginal() {
	return given;
}

void suffix::findLongest(vector<string> &List) {
	int tracker = 0;
	for (int i = 0; i != comparison.size(); i++) {
		if (comparison[i] > tracker) {
			tracker = comparison[i];
		}
	}

	// we have the longest now
	for (int i = 0; i != comparison.size(); i++) {
		if (comparison[i] == tracker) {
			// we need to pull the similar and push into the list
			string base = "";
			for (int j = 0; j != tracker; j++) {
				base.push_back(recreate(suffixList[i - 1])[j]);
			}
			// we now have a base with the part; we should run through list and input if not existing
			int exists = 0;
			for (int t = 0; t != List.size(); t++) {
				if (List[t] == base) {
					exists++;
				}
			}
			if (exists == 0) {
				List.push_back(base);
			}
		}
	}
}