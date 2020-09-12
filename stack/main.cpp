#include <iostream>
#include "stack.h"

using namespace std;

int main() {

	string teststr1 = "[[{taco}({[test]})]]";
	string teststr2 = "[({]";
	string teststr3 = "))()";
	string teststr4 = "()c()[]";

	bool isSyntax = EndCheck(teststr1);
	cout << isSyntax;
	cout << "\n";
	bool isSyntax = stackTest(teststr2);
	cout << isSyntax;
	cout << "\n";
	bool isSyntax = stackTest(teststr3);
	cout << isSyntax;
	cout << "\n";
	bool isSyntax = stackTest(teststr4);
	cout << isSyntax;
	cout << "\n";
}