#include "ContactsBook.h"
#include <fstream>
#include <iostream>
#include <string>

ContactsBook::ContactsBook(int size_of_list) {
	this->contacts_list = new Contact[size_of_list];
	this->size_of_contacts = size_of_list;
	this->contacts_count = 0;
	
}

void ContactsBook::add_contact(Contact& contact) {
	if (this->full()) {
		this->resize_list();
	}
	this->contacts_list[this->contacts_count] = contact;
	contacts_count++;
}

int ContactsBook::total_contacts() {
	return contacts_count;
}

bool ContactsBook::full() {
	if (this->contacts_count == this->size_of_contacts) {
		return true;
	}
	else
		return false;
}

void ContactsBook::resize_list()
{
	Contact* contact = new Contact[2 * this->size_of_contacts];
	for (int i = 0; i < contacts_count; i++) {
		contact[i] = this->contacts_list[i];
	}
	delete[] contacts_list;
	contacts_list = contact;
	this->size_of_contacts *= 2;
}



Contact ContactsBook::search_contact(std::string String)
{
	
	for (int i = 0; i < this->contacts_count; i++) {
		int count = 0;
		std::string windows[5];
		windows[0] = this->contacts_list[i].get_first_name() + contacts_list[i].get_last_name();
		windows[1] = this->contacts_list[i].get_address()->get_city();
		windows[2] = this->contacts_list[i].get_email_address();
		windows[3] = this->contacts_list[i].get_mobile_number();
		windows[4] = this->contacts_list[i].GetId();
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < windows[j].size(); k++) {
				if (String[count] == windows[j][k]) {
					count++;
				}
				if (count == String.size()) {
					contacts_list[i].IncrementSearchCount();
					contacts_list[i].SetSearchTime();
					return this->contacts_list[i];
				}	
			}
		}
		std::string search_phone = contacts_list[i].get_mobile_number();
		std::string search_email = contacts_list[i].get_address()->get_house();
		std::string f_name = contacts_list[i].get_first_name();
		std::string l_name = contacts_list[i].get_last_name();
		std::string search_id = contacts_list[i].GetId();
		if (search_phone == String || search_email == String || search_id == String || f_name == String || l_name == String) {
			contacts_list[i].IncrementSearchCount();
			contacts_list[i].SetSearchTime();
			return contacts_list[i];
		}
		
	}	
}



void ContactsBook::print_contacts_sorted(std::string choice)
{
	Contact* contacts = ContactsBook::copy(*this->contacts_list);
	ContactsBook::sort_contacts_list(contacts, choice);

	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << contacts[i].GetId() << " " << contacts[i].get_first_name() << " " << contacts[i].get_last_name() << " ";
		std::cout << std::endl;
	}
}

Contact* ContactsBook::copy(Contact contact_list) 
{
	Contact* copy_contacts_list = new Contact[contacts_count];
	for (int i = 0; i < contacts_count; i++) 
	{
		copy_contacts_list[i] = contacts_list[i];
	}
	return copy_contacts_list;
}

int compare(Contact* contacts1, Contact* contacts2, std::string choice) {
	if (choice == "first_name") {
		return contacts1->get_first_name() <= contacts2->get_first_name() ? 1 : -1;
	}
	else if (choice == "last_name") {
		return contacts1->get_last_name() <= contacts2->get_last_name() ? 1 : -1;
	}
	else if (choice == "ID" || choice == "id") {
		contacts1->GetId() <= contacts2->GetId() ? 1 : -1;
	}
}

void ContactsBook::sort_contacts_list(Contact* contacts_list, std::string choice) {
	for (int i = 0; i <= contacts_count; i++) {
		for (int j = i + 1; j < contacts_count; j++) {
			Contact temp;
			if (compare(&contacts_list[j], &contacts_list[i], choice) == 1) {
				temp = contacts_list[j];
				contacts_list[j] = contacts_list[i];
				contacts_list[i] = temp;
			}
		}
	}
}

void ContactsBook::merge_duplicates() {
	int end_count = contacts_count;
	for (int i = 0; i < end_count; i++) {
		for (int j = i + 1; j < end_count;) {
			if (this->contacts_list[i] == this->contacts_list[j]) {
				for (int k = j; k < end_count - 1; k++) {
					this->contacts_list[k] = this->contacts_list[k + 1];
				}
				end_count--;
			}
			else 
			{
				j++;
			}
		}
	}

	for (int i = 0; i < end_count; i++) {
		std::cout << this->contacts_list[i].get_first_name() << " " << this->contacts_list[i].get_last_name() << " " << this->contacts_list[i].get_email_address() << std::endl;
		this->contacts_list[i].get_address()->print_address();
		std::cout << std::endl;
	}
	std::cout << "Merged Contacts: " << contacts_count - end_count << std::endl;
}

void ContactsBook::save_to_file(std::string file_name) {
	std::ofstream file;
	file.open(file_name);

	if (!file.is_open())
		std::cout << "Error! File cannot open" << std::endl;
	else {
		file << this->size_of_contacts << std::endl;
		file << this->contacts_count << std::endl;
		for (int i = 0; i < contacts_count; i++) {
			file << this->contacts_list[i];
		}
		std::cout << "Contacts saved in file" << std::endl;
	}
	file.close();
}

void ContactsBook::load_from_file(std::string file_name) {
	std::ifstream file;
	file.open(file_name);

	if (file.is_open()) {
		int size_of_contacts, contacts_count, count;
		file >> size_of_contacts;
		file >> count;

		Contact contact;
		Address address;

		std::string first_name;
		std::string last_name;
		std::string mobile_number;
		std::string email_address;
		std::string house;
		std::string street;
		std::string city;
		std::string country;

		for (int i = 0; i < count; i++) {

			getline(file, first_name, ',');
			getline(file, last_name, ',');
			getline(file, mobile_number, ',');
			getline(file, email_address);
			getline(file, house, ',');
			getline(file, street, ',');
			getline(file, city, ',');
			getline(file, country);

			contact.set_first_name(first_name);
			contact.set_last_name(last_name);
			contact.set_mobile_number(mobile_number);
			contact.set_email_address(email_address);

			address.set_house(house);
			address.set_street(street);
			address.set_city(city);
			address.set_country(country);

			contact.set_address(&address);

			this->add_contact(contact);
		}
	}
	else {
		std::cout << "ERR: file not open" << std::endl;
	}
}

ContactsBook::ContactsBook() {}

ContactsBook& ContactsBook::operator = (const ContactsBook& contacts_book) {
	if (this != &contacts_book) {
		this->size_of_contacts = contacts_book.size_of_contacts;
		this->contacts_count = contacts_book.contacts_count;
		for (int i = 0; i < contacts_count; i++) {
			this->contacts_list[i] = contacts_book.contacts_list[i];
		}
	}
	return *this;
}

std::ostream& operator <<(std::ostream& cout, ContactsBook& contacts_book) {
	for (int i = 0; i < contacts_book.contacts_count; i++) 
	{
		std::cout << contacts_book.contacts_list[i];
	}
	return cout;
}

Contact* ContactsBook::get_contact_list() {
	return contacts_list;
}

void ContactsBook::frequentlySearched() {

	Contact* contacts = ContactsBook::copy(*this->contacts_list);
	for (int i = 0; i < this->contacts_count-1; i++) {
		for (int j = 0; j < this->contacts_count - i - 1; j++) {
			if (contacts[j].GetSearchCount() < contacts[j+1].GetSearchCount()) {
				Contact temp = contacts[j];
				contacts[j + 1] = contacts[j];
				contacts[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++) {
		std::cout << contacts[i] << std::endl;
	}

}
ContactsBook ContactsBook::Remove_contact(Contact searched) {
	int end_count = contacts_count;
	for (int i = 0; i < end_count;) {
		if (this->contacts_list[i] == searched)
		{
			for (int j = i; j < end_count - 1; j++) {
				contacts_list[i] = contacts_list[i + 1];
			}
			end_count--;
			this->contacts_count--;
		}
		else i++;
	}
	this->save_to_file("Updated_file");
	return *this;
}


void ContactsBook :: ViewDetails(std::string input) {
	Contact obj = this->search_contact(input);
	system("cls");
	std::cout << obj.GetId() << " " << obj.get_first_name() << " " << obj.get_last_name() << " " << obj.get_address() << std::endl << obj.get_mobile_number() << " " << obj.get_email_address()<<std::endl;
	system("cls");
	std::cout << "------Menu-----" <<std:: endl;
	std::cout << "1.Update\n2.Delete\n" << std::endl;
	int option;
	std::cin >> option;
	switch (option) {
	case 1:
	{
		std::string first_name, last_name, mobile_number, email_address, city, country, street, house, file_name;
		std::cin >> file_name;
		Contact contact;
		Address address;
		std::cout << "House ";
		std::cin.ignore();
		std::getline(std::cin, house);
		std::cin.ignore();
		address.set_house(house);

		std::cin.ignore();
		std::cout << "Street: ";
		std::getline(std::cin, street);
		address.set_street(street);

		std::cout << "City: ";
		std::getline(std::cin, city);
		address.set_city(city);

		std::cout << "Country: ";
		std::getline(std::cin, country);
		address.set_country(country);


		std::cout << "First Name: ";
		std::getline(std::cin, first_name);
		contact.set_first_name(first_name);

		std::cout << "Last Name: ";
		std::getline(std::cin, last_name);
		contact.set_last_name(last_name);

		std::cout << "Mobile Number: ";
		std::getline(std::cin, mobile_number);
		contact.set_mobile_number(mobile_number);

		std::cout << "Email Address: ";
		std::getline(std::cin, email_address);
		contact.set_email_address(email_address);

		contact.set_address(&address);

		
		obj.Update(contact);
		this->save_to_file(file_name);

	}
	case 2:
	{
		std::string input;
		std::cout << "Enter a string to delete" << std::endl;
		std::cin >> input;
		Contact obj = this->search_contact(input);
		this->Remove_contact(obj);
	}
    }

}

