#include "Address.h"
#include <iostream>

Address::Address(std::string house, std::string street, std::string city, std::string country) {
	if (house.length() > 0)
		this->house = house;

	if (street.length() > 0)
		this->street = street;

	if (city.length() > 0)
		this->city = city;

	if (country.length() > 0)
		this->country = country;
}

void Address::set_house(std::string house) {
	if (house.length() > 0)
		this->house = house;
}
void Address::set_street(std::string street) {
	if (street.length() > 0)
		this->street = street;
}
void Address::set_city(std::string city) {
	//if (sizeof(city) > 0)
		this->city = city;
}
void Address::set_country(std::string country) {
	//if (country.length() > 0)
		this->country = country;
}

std::string Address::get_house() {
	return this->house;
}
std::string Address::get_street() {
	return this->street;
}

std::string Address::get_city() {
	return this->city;
}
std::string Address::get_country() {
	return this->country;
}


bool Address::equals(const Address& address) {
	if (this->house != address.house || this->street != address.street || this->city != address.city ||
		this->house != address.city) {
		return false;
	}
	return true;
}

bool Address::operator==(Address address) {
	if (this->house == address.house && this->street == address.street && this->city == address.city &&
		this->country == address.country) {
		return true;
	}
	return false;
}


std::ostream& operator <<(std::ostream& Cout, Address& address) {
	Cout << address.house << "," << address.street << "," << address.city << "," << address.country << std::endl;
	return Cout;
};


Address& Address::operator = (const Address& address) {
	if (this != &address) {
		this->house = address.house;
		this->street = address.street;
		this->city = address.city;
		this->country = address.country;
	}
	else
		return *this;
};

void Address::print_address()
{

	std::cout << this->house << " " << this->street << " " << this->city << " " <<
		this->country << std::endl;
}

Address Address::copy_address() {
	Address* add = new Address;
	add->set_house(this->house);
	add->set_street(this->street);
	add->set_city(this->city);
	add->set_country(this->country);
	return *add;
}