#pragma warning(disable : 4996)
#include "ContactsBook.h"
#include "Contact.h"
#include "Address.h"
#include"Group.h"
#include"Objects.h"
#include <iostream>
#include<string>
#include <fstream>
#include<exception>
using namespace std;
class Exception : public exception
{
public:
	void what()
	{
		std::cout << "404 error... Exception occured!" << std::endl;
	}
};
int main()
{
	Exception e;
	int size;
	std::cout << "Size: ";
	try {
		std::cin >> size;
		if (std::cin.fail())
			throw size;
	}
	catch (int size_entered) {
		e.what();
		std::wcout << "Enter an integer value" << std::endl;
		std::cin.clear();
		std::cin.ignore();
		std::cin >> size;
	}

	ContactsBook contact_book(size);
	Exception e;
	int option;
	std::string first_name, last_name, mobile_number, email_address, city, country, street, house, file_name, choice;

	std::cout << "File Name: ";
	std::cin.ignore();
	std::getline(std::cin, file_name);

	do
	{
		std::cout << "1.Create a contacts list " << std::endl;
		std::cout << "2.Add New Contact" << std::endl;
		std::cout << "3.Merge Duplicates" << std::endl;
		std::cout << "4.Store To File" << std::endl;
		std::cout << "5.Load From File" << std::endl;
		std::cout << "6.Print Contacts Sorted or view details of a contact" << std::endl;
		std::cout << "7.Print Contacts" << std::endl;
		std::cout << "8.Search contacts" << std::endl;
		std::cout << "9.Display Count of Contacts" << std::endl;
		std::cout << "10. Display Group Features" << std::endl;
		std::cout << "11.Exit" << std::endl;

		std::cin >> option;
		switch (option)
		{
		case 1: {
			int size, press;

			std::cout << "Contacts list is already created! if you want to create again press 1 or 0: ";
			std::cin >> press;

			if (press == 1) {
				try {
					std::cout << "Size: ";
					std::cin.ignore();
					std::cin >> size;
					if (std::cin.fail())
						throw size;
				}
				catch (int size_value) {
					e.what();
					std::cout << "Enter an integer value" << std::endl;
					std::cin.clear();
					std::cin.ignore();
					std::cin >> size;
				}

				ContactsBook obj1(size);
				break;
			}
			else break;
			break;
		}
		case 2:
		{
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

			contact_book.add_contact(contact);
			contact_book.save_to_file(file_name);

			break;
		}
		case 3:
		{
			contact_book.merge_duplicates();
			break;
		}
		case 4: {
			contact_book.save_to_file(file_name);
			break;
		}
		case 5: {
			contact_book.load_from_file(file_name);
			break;
		}
		case 6: {
			std::cout << "Choice: ";
			std::cin.ignore();
			std::getline(std::cin, choice);
			contact_book.print_contacts_sorted(choice);
			std::cout << "\n\nEnter any contact to view details" << std::endl;
			std::string contact;
			std::cin >> contact;
			contact_book.ViewDetails(contact);

			break;
		}
		case 7: {
			int total_contacts = contact_book.total_contacts();
			Contact* contacts_list = contact_book.get_contact_list();
			for (int i = 0; i < total_contacts; i++) {
				std::cout << contacts_list[i];
			}
			break;
		}
		case 8: {
			std::string search;
			std::cout << "Enter a string to search: " << std::endl;
			std::cin >> search;
			ContactsBook obj;
			std::cout << obj.search_contact(search).GetId() << " ";
			std::cout << obj.search_contact(search).get_first_name() << " ";
			std::cout << obj.search_contact(search).get_last_name() << " " << std::endl;
		}
		case 9: {
			std::cout << "Count of Contacts: ";
			std::cout << contact_book.total_contacts() << std::endl;
			break;
		}
		case 10: {
			Group* groups = new Group[10];

			std::cout << "1.make a group\n 2.Add a contact\n3.Remove a Contact\n4.Search in Group\n5.Display Group Contacts\n6.Delete a Group" << std::endl;
			int choice;
			cin >> choice;
			switch (choice) {
			case 1:
			{

				std::string group_name;
				std::cout << "enter Name of group: " << std::endl;
				std::cin >> group_name;
				std::cout << "enter Size of group: " << std::endl;
				int size;
				std::cin >> size;

				Group obj(group_name, size);
				for (int i = 0; i < Group::group_count;)
				{
					if (groups[i] != obj)
					{
						std::cout << "Group already exists" << std::endl;
						i++;
					}
					else {
						groups[i] = obj;
					}
				}
				break;
			}
			case 2:
			{
				int opt;
				std::cout << "1.add in available groups\n2.Make a new group\n";
				std::cin >> opt;
				switch (opt)
				{
				case 1:
				{
					std::cout << "----Available Groups----" << std::endl;

					for (int i = 0; i < Group::group_count; i++)
					{
						std::cout << groups[i].GetGroupName() << std::endl;
					}
					std::cout << "Select a Group " << std::endl;
					std::string select_name;
					std::cin >> select_name;
					for (int i = 0; i < Group::group_count; i++)
					{
						if (select_name == groups[i].GetGroupName())
							groups[i].add_in_group();
					}
					break;
				}
				case 2:
				{
					system("cls");
					std::string group_name;
					std::cout << "enter Name of group: " << std::endl;
					std::cin >> group_name;
					std::cout << "enter Size of group: " << std::endl;
					int size;
					std::cin >> size;
					Group obj(group_name, size);
					for (int i = 0; i < Group::group_count;)
					{
						if (groups[i] != obj)
						{
							i++;
						}
						else
						{
							groups[i] = obj;
							groups[i].add_in_group();
						}
					}
					break;
				}
				default:break;
				}
			case 3: {
				std::cout << "----Available Groups----" << std::endl;

				for (int i = 0; i < Group::group_count; i++)
				{
					std::cout << groups[i].GetGroupName() << std::endl;
				}
				std::cout << "Select a Group " << std::endl;
				std::string select_name;
				std::cin >> select_name;
				std::string select_contact;
				std::cout << "Enter a Contact to Remove" << std::endl;
				std::cin >> select_contact;
				for (int i = 0; i < Group::group_count; i++)
				{
					if (select_name == groups[i].GetGroupName())
						groups[i].remove_a_contact(select_contact);
				}
				break;
			}
			case 4: {
				std::cout << "Enter a Contact Id to search" << std::endl;
				std::string contact;
				std::cin >> contact;
				for (int i = 0; i < Group::group_count; i++)
				{
					Contact searched = groups[i].search_in_group(contact);
					if (searched.GetId() == contact)
						std::cout << searched << std::endl << "This Contact is a member of " << groups[i].GetGroupName() << std::endl;
				}
				break;
			}case 5:
			{
				std::string group_name;
				std::cout << "Enter Group Name " << std::endl;
				std::cin >> group_name;
				for (int i = 0; i < Group::group_count; i++)
				{
					if (groups[i].GetGroupName() == group_name) {
						system("cls");
						std::cout << "------" << groups[i].GetGroupName() << "-------\n\n";
						groups[i].Display_group_members();
					}
					else
						std::cout << "\n**No Such Group exists**\n";

				}
				break;
			}
			case 6:
			{

				std::cout << "----Available Groups----" << std::endl;

				for (int i = 0; i < Group::group_count; i++)
				{
					std::cout << groups[i].GetGroupName() << std::endl;
				}
				std::cout << "Select a Group " << std::endl;
				std::string select_name;
				std::cin >> select_name;
				int end_count = Group::group_count;
				for (int i = 0; i < Group::group_count; i++)
				{
					if (select_name == groups[i].GetGroupName()) {
						for (int j = i; j < end_count; j++)
						{
							groups[j] = groups[j + 1];
						}
						std::cout << "Contact removed Successfully" << std::endl;
						Group::group_count--;
						end_count--;
					}
					else
						i++;
				}

				break;
			}
			default:break; }//group switch ends
			}//case 10 ends
		case 11: {
			return;

		default:
			break;
		}
		}
		}

	} while (option != 11); //do while ends
	system("pause");
	return 0;
}			   //main ends