#include <iostream>
#include <cstdlib>
#include <string>

#include "hashtable.h"

using namespace std;

int main() {

	hashtable Hashy;

	Hashy.addItem("Paul", "Green");
	Hashy.addItem("Kim", "Blue");
	Hashy.addItem("Emma", "Pink");
	Hashy.addItem("Annie", "Orange");
	Hashy.addItem("Sarah", "Red");
	Hashy.addItem("Pepper", "Yellow");
	Hashy.addItem("Mike", "Blue");
	Hashy.addItem("Steve", "Orange");
	Hashy.addItem("Bill", "Light-Pink");
	Hashy.addItem("Marie", "Purple");
	Hashy.addItem("Susan", "Light-Green");
	Hashy.addItem("Joe", "Teal");

	Hashy.remove("Kim");
	Hashy.remove("Steve");

	Hashy.printTable();

	Hashy.printItemsinIndex(8);

	string search = Hashy.findPair("Bill");

	cout << search << endl;

	return 0;
}