
#pragma once
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#include<ctime>
#endif 

#include "Address.h"
#include"ContactsBook.h"

class Contact{
private:
	int search_count;	
	time_t current_time;
    std::string id;
	std::string first_name;
	std::string last_name;
	std::string mobile_number;
	std::string email_address;
	Address* address;

public:
	Contact();
	bool equals(Contact contact);
	Contact* copy_contact();
	void set_id(std::string id);
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_mobile_number(std::string mobile_number);
	void set_email_address(std::string email_address);
	void set_address(Address* address);
	void SetSearchTime();

	time_t GetSearchTime();
	int GetSearchCount();
	std::string GetId();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_mobile_number();
	std::string get_email_address();
	Address* get_address();
	void IncrementSearchCount();

	bool operator ==(Contact contact);
	friend std::ostream& operator <<(std::ostream& COUT, Contact& contact);
	Contact& operator = (const Contact& contact);
	void Update(Contact contact);

	Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address, Address* address);
};


