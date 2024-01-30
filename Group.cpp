#include"Group.h"
#include"Contact.h"

Group::Group() {
	this->group_count++;
}

Group::Group(std::string g_name,int size) {
	this->list = new ContactsBook(size);
	this->group_name = g_name;
	this->group_count++;
}

std::string Group::GetGroupName() {
	return group_name;
}

void Group::add_in_group()
{
	std::string contact_string;
	system("cls");
	std::cout << "---------Contacts List---------\n" << std::endl;
	list->print_contacts_sorted("first_name");
	std::cout << "\nSelect a contact" << std::endl;
	std::cin>> contact_string;
	Contact obj=list->search_contact(contact_string);
	list->add_contact(obj);
	list->save_to_file(this->group_name);
}

void Group::remove_a_contact(std::string contact) {
	Contact obj=list->search_contact(contact);
	int end_count = list->total_contacts();
	for (int i = 0; i < end_count; ) {
		if (obj.GetId() == list->search_contact(contact).GetId()) {
			for (int j = i; j < end_count; j++) {
				list->get_contact_list()[j] = list->get_contact_list()[j + 1];
			}
			std::cout << "Contact removed Successfully" << std::endl;
			end_count--;
		}
		else i++;
	
	}
	
}

void Group::Display_group_members()
{
	this->list->print_contacts_sorted("first_name");
}

Contact Group::search_in_group(std::string contact) {
	Contact searched = this->list->search_contact(contact);
	return searched;
}

int Group:: operator!=(Group obj) {
	if (this->group_name == obj.group_name)
		return -1;
	else 
		return 1;
}
