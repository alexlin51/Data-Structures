#include <iostream>
#include "List.h"

using namespace std;

int main(){
	
	List test;

	test.AddEnd(3);
	test.AddEnd(4);
	test.AddEnd(5);
	test.AddEnd(6);
	test.AddEnd(7);
	test.AddEnd(8);
	test.DelEnd();
	test.DelEnd();
	test.AddEnd(8);
	test.InsertNode(7, 3);
	test.ViewList();

}