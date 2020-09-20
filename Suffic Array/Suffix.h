#ifndef SUFFIX_H
#define SUFFIX_H

#include <string>
#include <vector>
#include <iostream>

class suffix {

private:

	std::string given;
	std::vector<int> suffixList;
	std::vector<int> comparison;

	std::string recreate(int index);
	void createList();
	int compare(std::string current, std::string next);

public:
	suffix(std::string input);
	void showSufIndex();
	void showComList();
	std::string returnOriginal();
	void findLongest(std::vector<std::string> &list);

};

#endif