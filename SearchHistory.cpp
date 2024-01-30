#include"ContactsBook.h"
#include"SearchHistory.h"
#include<fstream>
#include<ctime>
void SearchHistory::SetSearchTime(){
	this->current_time = time(0);
// convert now to string form
//char* dt = ctime(&current_time);

}
time_t SearchHistory::GetSearchTime()
{
	return current_time;
}
std::string SearchHistory::GetInputString()
{
	return this->Input;
}
void SearchHistory::SetInputString(std::string input) 
{
	this->Input = input;
}
