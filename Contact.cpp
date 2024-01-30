#include "Contact.h"
#include <string>

Contact::Contact(){
	address = new Address;
	this->search_count = 0;
}

Contact::Contact(std::string first_name, std::string last_name, std::string mobile_number, std::string email_address,
	Address* address) {
	if (first_name.length() > 0)
		this->first_name = first_name;
	else
		std::cout << "wrong input\n";

	if (last_name.length())
		this->last_name = last_name;
	else
		std::cout << "wrong input\n";

	if (mobile_number.length() == 11)
		this->mobile_number = mobile_number;
	else
		std::cout << "wrong input\n";

	if (email_address.length() > 0)
		this->email_address = email_address;
	else
		std::cout << "wrong input\n";

	this->address = address;

	this->search_count = 0;
}

void Contact::set_id(std::string id) {
	if (id.length()> 0)
		this->id = id;
}
void Contact::set_first_name(std::string first_name) {
	if (first_name.length() > 0)
		this->first_name = first_name;
}
void Contact::set_last_name(std::string last_name) {
	if (last_name.length() > 0)
		this->last_name = last_name;
}
void Contact::set_mobile_number(std::string mobile_number) {
	if (mobile_number.length() == 11)
		this->mobile_number = mobile_number;
}
void Contact::set_email_address(std::string email_address) {
	if (email_address.length() > 0)
		this->email_address = email_address;
}
void Contact::set_address(Address* address) {
	*this->address = address->copy_address();
}
void Contact::SetSearchTime() {
	this->current_time = time(0);
   // convert now to string form
   //char* dt = ctime(&current_time);

}

time_t Contact:: GetSearchTime() {
	
	return this->current_time;
}

int Contact::GetSearchCount() {
	return this->search_count;
}
std::string Contact::GetId() {
	return this->id;
}

std::string Contact::get_first_name() {
	return this->first_name;
};
std::string Contact::get_last_name() {
	return this->last_name;
};
std::string Contact::get_mobile_number() {
	return this->mobile_number;
};
std::string Contact::get_email_address() {
	return this->email_address;
};
Address* Contact::get_address() {
	return this->address;
};

void Contact::IncrementSearchCount() {
	this->search_count++;
}

bool Contact::equals(Contact contact) {
	if (this->first_name == contact.first_name && this->last_name == contact.last_name &&
		this->mobile_number == contact.mobile_number && this->email_address == contact.email_address &&
		this->address->equals(*contact.address)&&this->id==contact.id) {
		return true;
	}
	else {
		return false;
	}
}

Contact* Contact::copy_contact() {
	Contact* contact = new Contact;
	contact->id = this->id;
	contact->first_name = this->first_name;
	contact->last_name = this->last_name;
	contact->mobile_number = this->mobile_number;
	contact->email_address = this->email_address;
	contact->address = this->address;
	return contact;
}

bool Contact::operator ==(Contact contact) {
	if (this->first_name == contact.first_name && this->id==contact.id &&
		this->last_name == contact.last_name &&
		this->email_address == contact.email_address &&
		this->mobile_number == contact.mobile_number &&
		this->address == contact.address) {
		return true;
	}
	return false;
}

std::ostream& operator <<(std::ostream& Cout, Contact& contact) {
	Cout << contact.id<<"," << contact.first_name << "," << contact.last_name
		<< "," << contact.mobile_number << "," << contact.email_address << std::endl;
	Cout << *contact.address;
	return Cout;
}

Contact& Contact::operator = (const Contact& contact) {
	if (this != &contact) {
		this->id = contact.id;
		this->first_name = contact.first_name;
		this->last_name = contact.last_name;
		this->mobile_number = contact.mobile_number;
		this->email_address = contact.email_address;
		this->address = contact.address;
	}
	else
		return *this;
}

void  Contact::Update(Contact searched) {

	*this = searched;

}
