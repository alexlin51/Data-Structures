#include <iostream>
#include "List.h"

using namespace std;

int main() {

	List test;

	test.AddEnd(1);
	test.AddEnd(2);
	test.AddEnd(3);
	test.AddEnd(4);
	test.AddEnd(5);
	
	//test.DelEnd();
	//test.InsertNode();		Edge cases tested!
	//test.PullNode();			Edge cases tested!

	test.ViewList();
	
	cout << " | ";
	cout << test.DataPos(3);

}