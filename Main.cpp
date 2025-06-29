#include <iostream>
#include "ContactsBook.h"
using namespace std;
int main()
{
	int choice, choice_2, count = 0, num_contact, ind = 0, user_contact_choice, group_id, id_in_group, del_grp, search_grp;
	Contact* found, new_contact;
	Address new_contact_add;
	string new_contact_info, new_contact_address, file_name, first, last, phone, house, street, city, country, group_name;
	cout << "Enter Number of Contacts you want: ";
	cin >> num_contact;
	ContactsBook Contact_list(num_contact);
	while (true)
	{
		system("cls");
		cout <<"0.To print total number of contacts\n" "1. Add New Contact\n2. Merge Duplicates\n"
			<< "3. Store To file (input file name)\n4. Load from file\n"
			<< "5. Print Contacts Sorted(by first_name, last_name)\n"
			<< "6. Print Contacts Unsorted\n7. Search Contacts\n"
			<< "8. Display Count of Contacts\n9. Manage Contacts\n10. View Search History\n11. Manage Groups\n12. Exit\nEnter Your Choice: ";
		cin >> choice;
		cin.ignore();
		switch (choice)
		{
		case 0:
			cout << "Total number of Contacts are : " << Contact_list.total_contacts() << '\n';
			break;
		case 1:
			cout << "Enter First Name of Contact: ";
			getline(cin, new_contact_info);
			new_contact.set_first_name(new_contact_info);
			cout << "Enter Last Name of Contact: ";
			getline(cin, new_contact_info);
			new_contact.set_last_name(new_contact_info);
			cout << "Enter Mobile Number(11 digits): ";
			getline(cin, new_contact_info);
			new_contact.set_mobile_number(new_contact_info);
			cout << "Enter Email Address of Contact: ";
			getline(cin, new_contact_info);
			new_contact.set_email_address(new_contact_info);
			cout << "Address:\n";
			cout << "Enter House: ";
			getline(cin, new_contact_address);
			new_contact_add.set_house(new_contact_address);
			cout << "Enter Street: ";
			getline(cin, new_contact_address);
			new_contact_add.set_street(new_contact_address);
			cout << "Enter City: ";
			getline(cin, new_contact_address);
			new_contact_add.set_city(new_contact_address);
			cout << "Enter Country: ";
			getline(cin, new_contact_address);
			new_contact_add.set_country(new_contact_address);
			new_contact.set_address(new_contact_add);
			Contact_list.add_contact(new_contact);
			break;
		case 2:
			Contact_list.merge_duplicates();
			break;
		case 3:
			cout << "Enter File Name: ";
			getline(cin, file_name);
			Contact_list.save_to_file(file_name);
			break;
		case 4:
			cout << "Enter File Name: ";
			getline(cin, file_name);
			Contact_list.load_from_file(file_name);
			break;
		case 5:
			int choice_sort;
			cout << "Want to sort By\n";
			cout << "1. First Name\t2. Last Name";
			while (1)
			{
				cout << "\nEnter you choice(1/2): ";
				cin >> choice_sort;
				if (choice_sort)
				{
					Contact_list.print_contacts_sorted("first name");
					break;
				}
				else if (choice_sort == 2)
				{
					Contact_list.print_contacts_sorted("last name");
					break;
				}
				else
					cout << "Wrong Input, Enter Again: ";
			}
			break;
		case 6:
			Contact_list.print_contacts();
			break;
		case 7:
			cout << "Enter a string: ";
			getline(cin, first);
			found = Contact_list.search_contact(first, ind);
			if (found == nullptr)
				cout << "Contact Not Found!\n";
			else
			{
				for (int i = 0; i < ind; i++) {
					cout << "[ " << found[i].get_first_name() << " ]";
					cout << "[ " << found[i].get_last_name() << " ] ";
					cout << "[ " << found[i].get_mobile_number() << " ] ";
					cout << "[ " << found[i].get_email_address() << " ] ";
					cout << std::endl;
					cout << "[ ";
					found[i].get_address()->print_address();
					cout << " ]\n";
				}
			}
			break;
		case 8:
			cout << "Number of contacts: " << Contact_list.total_contacts() << endl;
			break;
		case 9:
			Contact_list.print_name_of_contacts();
			cout << "Enter ID of contact to show all information: ";
			cin >> user_contact_choice;
			Contact_list.manage_contacts(user_contact_choice);
			break;
		case 10:
			cout << "1. Print all string searched\n2. Print top 5 searched contacts\n";
			cout << "Enter Your Choice: ";
			cin >> choice;
			if (choice == 1)
				Contact_list.print_search_history();
			else if (choice == 2)
				Contact_list.view_top_search();
			else
				cout << "Wrong Input!\n";
			break;
		case 11:
			cout << "1. Create a group\n2. Available Groups\n"
				<< "3. Add id in Group\n4. Delete ID from group\n5. Print All Contacts in Group\n"
				<< "6. Delete a Group\n7. Search In a group\n";
			cout << "Enter Your Choice: ";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "Enter Name of group: ";
				cin.ignore();
				getline(cin, group_name);
				Contact_list.create_group(group_name);
				break;
			case 2:
				if (Contact_list.get_group_count() == 0)
					cout << "No Group Found!\n";
				else {
					Contact_list.print_groups();
				}
				break;
			case 3:
				if (Contact_list.get_group_count() == 0)
					cout << "No Group Found!\n";
				else
				{
					Contact_list.print_groups();
					cout << "In which Group You want to add Contact: ";
					cin >> group_id;
					cout << "Available Contacts:\n";
					Contact_list.print_name_of_contacts();
					cout << "Which ID you want to add in Group: ";
					cin >> id_in_group;
					if (Contact_list.total_contacts() < id_in_group)
						cout << "ID not Found!\n";
					else
						Contact_list.add_group(group_id - 1, id_in_group - 1);
				}
				break;
			case 4:
				if (Contact_list.get_group_count() == 0)
					cout << "No Group Found!\n";
				else {
					Contact_list.print_groups();
					cout << "In which Group You want to Delete Contact: ";
					cin >> group_id;

					Contact_list.print_cont_grps(group_id);
					cout << "Enter ID of Contact You want to delete: ";
					cin >> id_in_group;
					if (Contact_list.total_contacts() < id_in_group)
						cout << "ID not Found!\n";
					else
						Contact_list.remove_contact(group_id - 1, id_in_group - 1);
				}
				break;
			case 5:
				if (Contact_list.get_group_count() == 0)
					cout << "No Group Found!\n";
				else
				{
					Contact_list.print_groups();
					cout << "Enter ID of group whose contacts you want to see: ";
					cin >> group_id;
					Contact_list.print_cont_grps(group_id);
				}
				break;
			case 6:
				if (Contact_list.get_group_count() == 0)
					cout << "No Group Found!\n";
				else
				{
					Contact_list.print_groups();
					cout << "Which Group You want to Delete: ";
					cin >> del_grp;
					Contact_list.remove_group(del_grp);
				}
				break;
			case 7:
				Contact_list.print_name_of_contacts();
				cout << "Enter ID you want to search in all groups: ";
				cin >> search_grp;
				Contact_list.search_group(search_grp);
				break;

			default:
				cout << "Wrong Input!\n";
				break;
			}
			break;
		case 12:
			exit(0);
			break;
		default:
			cout << "Wrong Input, Enter Again!\n";
		}
		system("pause");
	}
}