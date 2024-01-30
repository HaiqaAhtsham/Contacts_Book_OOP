#pragma once
#include"ContactsBook.h"
#include"Contact.h"
#include"Address.h"
#include<ctime>
class SearchHistory {
 time_t current_time;
 std::string Input;
public:
	void SetSearchTime();
	time_t GetSearchTime();
	void SetInputString(std::string input);
	std::string GetInputString();
};
