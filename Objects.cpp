#pragma warning(disable : 4996)
#include"Objects.h"
#include<ctime>

Objects::Objects() {
	history_limit = 10;
	history_list = new SearchHistory[history_limit];
	history_count++;
 }
SearchHistory* Objects:: GetSearchHistory() {
	return this->history_list;
}
void Objects::PrintSearchHistory() {
	for (int i = this->history_limit; i >0 ; i--)
	{
		std::cout << this->GetSearchHistory()->GetInputString() << " ";
	time_t current_time = this->GetSearchHistory()->GetSearchTime();
	// convert searched time to string form
    char* dt = ctime(&current_time);
     std::cout << dt;
	}
}
SearchHistory Objects::resize_history_list()
{
	SearchHistory *history_list_2;
	history_list_2 = new SearchHistory[history_limit*2];
	for (int i = 0; i < history_limit; i++)
	{
		history_list_2[i] = history_list[i];
	}
	delete [] history_list;
	history_list = history_list_2;
	return *history_list_2;
}