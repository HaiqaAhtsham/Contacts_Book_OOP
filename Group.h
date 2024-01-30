#include"ContactsBook.h"
#include"Contact.h"
class Group {
private:
	std::string group_name;
	ContactsBook *list;
	
public:
	static int group_count;
	Group();
	Group(std::string G_name, int size);
	void Display_group_members();
	std::string GetGroupName();
	void add_in_group();
	Contact search_in_group(std::string contact);
	void remove_a_contact(std::string contact);
	int operator !=(Group obj);
};
