#include <cstdlib>
#include <iostream>
#include <map> 
#include <cstring>

#include "isBounded.h"	

using namespace std;

bool isBounded(std::string input) {
	Stack boundPile;

	// emptry string does nothing, also normal characters dont mean anything to this program
	int length = input.length();
	if (length == 0) {
		return true;
	}



	// iterate through string 
	for (int i = 0; i != length; i++) {
		// if it is one of the three left, we need to push a node stack;
		if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
			switch (input[i]) {
				case '(':
					boundPile.push("(");
					break;

				case '[':
					boundPile.push("[");
					break;

				case '{':
					boundPile.push("{");
					break;
				
				default:
					break;
			}
		}
		// if we meet the other side, we need to pop up the recent one only if the recent one is the same
		else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
			switch (input[i]) {
			case ')':
				if (boundPile.stackSize() != 0) {
					if (boundPile.peek() == "(") {
						boundPile.pop();
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}

			case ']':
				if (boundPile.stackSize() != 0) {
					if (boundPile.peek() == "[") {
						boundPile.pop();
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}

			case '}':
				if (boundPile.stackSize() != 0) {
					if (boundPile.peek() == "{") {
						boundPile.pop();
					}
					else {
						return false;
					}
				}
				else {
					return false;
				}

			default:
				break;
			}
		}
	}


	if (boundPile.stackSize() == 0) {
		return true;
	}
	else {
		return false;
	}

}

