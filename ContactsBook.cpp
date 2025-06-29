#include "ContactsBook.h"
#include<string>
#include<fstream>
void ContactsBook::add_contact(const Contact& contact)
{
	/*
		- Check if the list is full, if it is full call the resize function
		- If list is not full add the contact to the end of the array
		- (end means the place where last contact was inserted)
		- At start it will be 0th index as no contact has been inserted before so
		- count is zero (contacts_count member)
		- Increment the count
		- As inserted successfully, return 1
	*/
	if (full())
	{
		resize_list();
	}
	contacts_list[contacts_count] = contact;
	contacts_count++;
}

int ContactsBook::total_contacts()
{
	return contacts_count;
}

bool ContactsBook::full()
{
	/*
	* Return true if list is full, false otherwise
	*/
	if (size_of_contacts == contacts_count)
		return true;
	return false;
}

void ContactsBook::resize_list()
{
	/*
	*	Here you will resize the contact list, see example code given in lab manual to see how to resize arrays
	*	You will allocate a temporary new array of double the current size and copy the contacts from
	*       previous array to this array one by one, get the copy of each contact using copy_contact
	*       function of Contact class
	*	Delete the previous array
	*	Assign the new temporary array to the contacts_list pointer
	*	Updated the this->size_of_contacts with new size
	*/
	int temp_size = size_of_contacts * 2;
	Contact* new_contacts_list = new Contact[temp_size];
	for (int i = 0; i < size_of_contacts; i++)
	{
		new_contacts_list[i] = contacts_list[i];
	}
	delete[] contacts_list;
	contacts_list = new_contacts_list;
	size_of_contacts = temp_size;
}
void ContactsBook::view_top_search()
{
	int top_times, top_index[5], count_var = 0;
	bool flag;
	for (int i = 0; i < contacts_count; i++)
	{
		flag = false;
		if (count_var == 5)
		{
			break;
		}
		for (int j = 0; j < count_var; j++)
		{
			if (i == top_index[j])
			{
				flag = true;
				break;
			}
		}
		if (flag == false)
		{
			if (contacts_list[i].get_search_times() != 0)
			{
				top_times = contacts_list[i].get_search_times();
				top_index[count_var] = i;
			}
			else
			{
				continue;
			}
		}
		else
		{
			continue;
		}
		for (int j = 0; j < contacts_count; j++)
		{
			flag = false;
			if (top_times < contacts_list[j].get_search_times())
			{
				for (int k = 0; k < count_var; k++)
				{
					if (j == top_index[k])
					{
						flag = true;
						break;
					}
				}
				if (flag == false)
				{
					top_times = contacts_list[j].get_search_times();
					top_index[count_var] = j;
				}
			}
		}
		count_var++;
	}
	if (count_var == 0)
	{
		std::cout << "No searched contact! \n";
	}
	else
	{
		std::cout << "Top " << count_var << " searched contacts are: \n";
		for (int i = 0; i < count_var; i++)
		{
			std::cout << "[ " << contacts_list[i].get_first_name() << " ]";
			std::cout << "[ " << contacts_list[i].get_last_name() << " ] ";
			std::cout << "[ " << contacts_list[i].get_mobile_number() << " ] ";
			std::cout << "[ " << contacts_list[i].get_email_address() << " ] ";
			std::cout << std::endl;
			std::cout << "[ ";
			contacts_list[i].get_address()->print_address();
			std::cout << " ]\n";
			std::cout << "Searched Count: " << contacts_list[i].get_search_times() << endl;
		}
	}
}

void ContactsBook::print_search_history()
{
	if (history->get_search_count() < 0)
	{
		cout << "No History Found!\n";
	}
	for (int i = history->get_search_count() - 1; i >= 0; i--)
	{
		history->get_history(i);
	}
}
Contact* ContactsBook::search_contact(std::string user_input, int& ind)
{
	/*
	*	In all search functions perform the searching according the given parameter and return a copy of the contact using copy func
	*	Remove this return nullptr; before writing your code
	*/
	history->input_history(user_input);
	ind = 0;
	Contact* ptr = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++)
	{
		if (contacts_list[i].get_first_name().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_last_name().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_mobile_number().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_email_address().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_address()->get_house().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_address()->get_street().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_address()->get_city().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
		else if (contacts_list[i].get_address()->get_country().find(user_input) != std::string::npos)
		{
			ptr[ind] = contacts_list[i];
			contacts_list[i].inc_search_count();
			ind++;
		}
	}
	if (ind == 0)
		return nullptr;
	else
	{
		return ptr;
	}
}

ContactsBook::ContactsBook(int size_of_list) :size_of_contacts(size_of_list), contacts_count(0)
{
	/*
	*	Initialize the contacts_list array, also initialize the size and count members accordingly
	*/
	contacts_list = new Contact[size_of_contacts];
	history = new contact_history(size_of_contacts);
	groups_obj = nullptr;
	group_count = 0;
}

void ContactsBook::print_name_of_contacts()
{
	std::string user_contact_choice;
	bool contact_found{ true };
	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << i + 1 << ". [ " << contacts_list[i].get_first_name() << " ]";
		std::cout << "[ " << contacts_list[i].get_last_name() << " ] ";
		std::cout << std::endl;
	}
}

void ContactsBook::manage_contacts(int user_choice)
{
	user_choice--;
	print_by_id(user_choice);
	int choice;
	std::string new_contact_info, new_contact_address;
	Contact edited_contact;
	Address edited_contact_add;
	std::cout << "1. to edit contact" << std::endl;
	std::cout << "2. to delete contact" << std::endl;
	std::cout << "3. to exit" << std::endl;
	std::cout << "Your choice: ";
	std::cin >> choice;
	switch (choice)
	{
	case 1:
	{
		std::cout << "Enter First Name of Contact: ";
		std::cin.ignore();
		getline(std::cin, new_contact_info);
		edited_contact.set_first_name(new_contact_info);
		std::cout << "Enter Last Name of Contact: ";
		getline(std::cin, new_contact_info);
		edited_contact.set_last_name(new_contact_info);
		std::cout << "Enter Mobile Number(11 digits): ";
		getline(std::cin, new_contact_info);
		edited_contact.set_mobile_number(new_contact_info);
		std::cout << "Enter Email Address of Contact: ";
		getline(std::cin, new_contact_info);
		edited_contact.set_email_address(new_contact_info);
		std::cout << "Address: ";
		std::cout << "Enter House: ";
		getline(std::cin, new_contact_address);
		edited_contact_add.set_house(new_contact_address);
		std::cout << "Enter Street: ";
		getline(std::cin, new_contact_address);
		edited_contact_add.set_street(new_contact_address);
		std::cout << "Enter City: ";
		getline(std::cin, new_contact_address);
		edited_contact_add.set_city(new_contact_address);
		std::cout << "Enter Country: ";
		getline(std::cin, new_contact_address);
		edited_contact_add.set_country(new_contact_address);
		edited_contact.set_address(edited_contact_add);
		contacts_list[user_choice] = edited_contact;
		break;
	}
	case 2:
	{
		Address obj;
		if (!(user_choice == contacts_count - 1)) {
			for (int k = user_choice + 1; k < contacts_count; k++)
			{
				contacts_list[k - 1] = contacts_list[k];
			}
		}
		contacts_list[contacts_count - 1].set_first_name("");
		contacts_list[contacts_count - 1].set_last_name("");
		contacts_list[contacts_count - 1].set_email_address("");
		contacts_list[contacts_count - 1].set_mobile_number("");
		contacts_list[contacts_count - 1].set_address(obj);
		contacts_count--;
		break;
	}
	case 3:
	{
		break;
	}
	default: {
		std::cout << "Wrong input!";
		break;
	}
	}
}
int ContactsBook::get_group_count()
{
	return group_count;
}
void ContactsBook::search_group(int id)
{
	id--;
	bool flag = false;
	for (int i = 0; i < group_count; i++)
	{
		for (int j = 0; j < groups_obj[i].get_count(); j++)
		{
			if (id == groups_obj[j].get_contact_id(j))
			{
				cout << "Found in Group " << i + 1;
				print_by_id(groups_obj[j].get_contact_id(j));
				flag = true;
			}
		}
	}
	if (!flag)
		cout << "No such Contact Found in group!\n";
}
void ContactsBook::remove_group(int group_number)
{
	for (int i = group_number - 1; i < group_count - 1; i++)
	{
		groups_obj[i] = groups_obj[i + 1];
	}
	group_count--;
	std::cout << "Group removed! \n";
}
void ContactsBook::print_groups()
{
	cout << "Available Groups:\n";
	for (int i = 0; i < group_count; i++)
	{
		cout << i + 1 << ". " << groups_obj[i].get_group_name() << endl;
	}
	cout << "\n";
}
void ContactsBook::remove_contact(int group_id, int contact_ind)
{
	groups_obj[group_id].remove_id(contact_ind);
}
void ContactsBook::create_group(string name)
{
	if (group_count == 0)
	{
		groups_obj = new groups[group_count + 1];
		groups_obj->set_group_name(name);
		groups_obj->set_id_size(size_of_contacts);
		group_count++;
	}
	else
	{
		groups* temp_obj = new groups[group_count];
		for (int i = 0; i < group_count; i++)
		{
			temp_obj[i] = groups_obj[i];
		}
		delete[] groups_obj;
		groups_obj = nullptr;
		groups_obj = new groups[group_count + 1];
		for (int i = 0; i < group_count; i++)
		{
			groups_obj[i] = temp_obj[i];
		}
		delete[] temp_obj;
		temp_obj = nullptr;
		groups_obj[group_count].set_group_name(name);
		groups_obj[group_count].set_id_size(size_of_contacts);
		group_count++;
	}
}
void ContactsBook::add_group(int group_id, int contact_ind)
{
	groups_obj[group_id].set_contact_id(contact_ind);
}
void ContactsBook::print_cont_grps(int group_id)
{
	for (int i = 0; i < groups_obj[group_id - 1].get_count(); i++)
	{
		int id_index = groups_obj[group_id - 1].get_contact_id(i);
		std::cout << "Contact " << i + 1 << ":\n";
		print_by_id(id_index);
	}
}
void ContactsBook::print_contacts()
{
	for (int i = 0; i < contacts_count; i++)
	{
		std::cout << "[ " << contacts_list[i].get_first_name() << " ]";
		std::cout << "[ " << contacts_list[i].get_last_name() << " ] ";
		std::cout << "[ " << contacts_list[i].get_mobile_number() << " ] ";
		std::cout << "[ " << contacts_list[i].get_email_address() << " ] ";
		std::cout << std::endl;
		std::cout << "[ ";
		contacts_list[i].get_address()->print_address();
		std::cout << " ]\n";
	}
}
void ContactsBook::print_by_id(int user_choice)
{
	std::cout << "[ " << contacts_list[user_choice].get_first_name() << " ]";
	std::cout << "[ " << contacts_list[user_choice].get_last_name() << " ] ";
	std::cout << "[ " << contacts_list[user_choice].get_mobile_number() << " ] ";
	std::cout << "[ " << contacts_list[user_choice].get_email_address() << " ] ";
	std::cout << std::endl;
	std::cout << "[ ";
	contacts_list[user_choice].get_address()->print_address();
	std::cout << " ]\n";
}
void ContactsBook::print_contacts_sorted(std::string choice)
{
	/*
	*	Create a copy of this->contacts_list array here (do it by creating a new function that returns copy)
	*	Call the sort function sort_contacts_list to sort the newly created copy
	*	This copy is created to avoid changing the original insertion order of contact list
	*	Then print the contacts in following format:
	*	[First Name] [Last Name] [Mobile] [Email]
	*	Call the address print function to print address on next line
	*/
	Contact* new_contact_list = copy_contact();
	sort_contacts_list(new_contact_list, choice);
	for (int i = 0; i < size_of_contacts; i++)
	{
		if (new_contact_list[i].get_address() == nullptr)
		{
			continue;
		}
		std::cout << "[ " << new_contact_list[i].get_first_name() << " ]";
		std::cout << "[ " << new_contact_list[i].get_last_name() << " ] ";
		std::cout << "[ " << new_contact_list[i].get_mobile_number() << " ] ";
		std::cout << "[ " << new_contact_list[i].get_email_address() << " ] ";
		std::cout << std::endl;
		std::cout << "[ ";
		new_contact_list[i].get_address()->print_address();
		std::cout << " ]\n";
	}
}

Contact* ContactsBook::copy_contact()
{
	Contact* new_contact_list = new Contact[size_of_contacts];
	for (int i = 0; i < contacts_count; i++)
	{
		new_contact_list[i] = contacts_list[i];
	}
	return new_contact_list;
}
void ContactsBook::sort_contacts_list(Contact* contacts_list, std::string choice)
{
	/*
		You should not duplicate the code to sort based on choices
		Follow the strategy provided in manual/tutorial to avoid duplicating the code (Section B & E only)
		Sort by the fist letter of first name or last name as given in choice
	*/
	if (choice == "First Name" || choice == "first name")
	{
		for (int i = 0; i < size_of_contacts - 1; i++)
		{
			for (int j = i + 1; j < size_of_contacts; j++)
			{
				if (contacts_list[i].get_first_name() > contacts_list[j].get_first_name())
				{
					Contact temp = contacts_list[i];
					contacts_list[i] = contacts_list[j];
					contacts_list[j] = temp;
				}
			}
		}
	}
	if (choice == "Last Name" || choice == "last name")
	{
		for (int i = 0; i < size_of_contacts - 1; i++)
		{
			for (int j = i + 1; j < size_of_contacts; j++)
			{
				if (contacts_list[i].get_last_name() > contacts_list[j].get_last_name())
				{
					Contact temp = contacts_list[i];
					contacts_list[i] = contacts_list[j];
					contacts_list[j] = temp;
				}
			}
		}
	}
}
void ContactsBook::merge_duplicates()
{
	// Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal
	// If there are three copies of a Contact, then only one should remain
	// For example: If total contact are 10, and 2 contacts are same, after removing duplicates
	// 9 contacts will be left; and the this->contacts_count of list will 9
	// At the end display contacts mernged, and count of merged contact
	// Iterate through the contacts list to merge duplicates
	Address obj;
	int merged_contacts = 0;
	for (int i = 0; i < contacts_count; i++)
	{
		for (int j = i + 1; j < contacts_count; j++)
		{
			if (contacts_list[i].equals(contacts_list[j]))
			{
				for (int k = j + 1; k < contacts_count; k++)
				{
					contacts_list[k - 1] = contacts_list[k];
					contacts_list[k].set_first_name("");
					contacts_list[k].set_last_name("");
					contacts_list[k].set_email_address("");
					contacts_list[k].set_mobile_number("");
					contacts_list[k].set_address(obj);
				}
				contacts_count--;
				++merged_contacts;
			}
		}
	}
	cout << "Merged contacts are : " << merged_contacts << '\n';
}
void ContactsBook::load_from_file(std::string file_name)
{
	/*
	Read contacts back from file in the same format
	Read the contacts_count, and run a loop for this contacts_count and read the
	*	contacts in the same format as you stored
	*	Add them to contact book (this.add_contact function can be used)
	*	Finally, close the file
	*/
	std::ifstream input;
	input.open(file_name);
	if (!input)
		std::cout << "Error in opening file\n";
	else
	{
		std::string str_1, str_2, str_3, str_4, str_5, str_6, str_7;
		input >> this->contacts_count;
		for (int i = 0; i < contacts_count; i++)
		{
			input >> str_1 >> str_2 >> str_3 >> str_4 >> str_5 >> str_6 >> str_7;
			contacts_list[i].set_first_name(str_1);
			contacts_list[i].set_last_name(str_3);
			contacts_list[i].set_mobile_number(str_5);
			contacts_list[i].set_email_address(str_7);
			input >> str_1 >> str_2 >> str_3 >> str_4 >> str_5 >> str_6 >> str_7;
			contacts_list[i].get_address()->set_house(str_1);
			contacts_list[i].get_address()->set_street(str_3);
			contacts_list[i].get_address()->set_city(str_5);
			contacts_list[i].get_address()->set_country(str_7);
		}
	}
	input.close();
}
void ContactsBook::save_to_file(std::string file_name)
{
	/*
	*	In this function you will store all the contacts to a file
	*	On first line store contacts_count
	*	On next lines store contacts in the following format:
	*       2 lines for each contact
	*       On oneline write contact attributes(except address) in comma separated format. On second line
	*	store address atributes in the same format
	*	first_name,last_name,mobile_number,email_address
	*	house,street,city,country
	*	Close the file
	*/
	std::ofstream output1;
	output1.open(file_name, std::ios::app);
	if (!output1)
		std::cout << "Error !" << std::endl;
	else
	{
		Address* obj;
		output1 << contacts_count << std::endl;
		for (int i = 0; i < contacts_count; i++)
		{
			obj = contacts_list[i].get_address();
			output1 << contacts_list[i].get_first_name() << " , " << contacts_list[i].get_last_name() << " , " << contacts_list[i].get_mobile_number() << " , " << contacts_list[i].get_email_address() << std::endl;
			output1 << obj->get_house() << " , " << obj->get_street() << " , " << obj->get_city() << " , " << obj->get_country() << std::endl;
		}
	}
	output1.close();
}