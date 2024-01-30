
#pragma once
#include "Address.h"
#include "Contact.h"

#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif
class ContactsBook {
private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, std::string choice);
	Contact* contacts_list;
	int size_of_contacts;
	int contacts_count;

public:

	void add_contact(Contact& contact);
	int total_contacts();
	
	
	Contact* get_contact_list();
	Contact search_contact( std::string String );
	
	ContactsBook(int size_of_list);

	void print_contacts_sorted(std::string choice);
	Contact* copy(Contact contact);
	
	void merge_duplicates();

	void save_to_file(std::string file_name);

	void load_from_file(std::string file_name);

	ContactsBook& operator = (const ContactsBook& contacts_book);
	friend std::ostream& operator <<(std::ostream& COUT, ContactsBook& contact);

	ContactsBook();
	void ViewDetails(std::string input);
	void frequentlySearched();
	ContactsBook Remove_contact(Contact contact);


};