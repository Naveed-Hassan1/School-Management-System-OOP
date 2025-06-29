#pragma once
#include "Address.h"
#include "Contact.h"
#include "contact_history.h"
#include"groups.h"
#ifndef BASIC_LIB
#define BASIC_LIB
#include <iostream>
#include <string>
#endif // !BASIC_LIB

class ContactsBook
{
private:
	groups* groups_obj;
	Contact* contacts_list; // array of contacts
	int size_of_contacts;   // storage limit
	int contacts_count;     // total contacts currently stored, next contact will be 
	contact_history* history;// stored at this count plus 1 index
	int group_count;
public:
	void add_contact(const Contact& contact);
	int total_contacts();
	void search_group(int);
	int get_group_count();
	void print_groups();
	void create_group(string);
	void add_group(int, int);
	void print_cont_grps(int);
	Contact* search_contact(std::string user_input, int&);
	void print_search_history();
	ContactsBook(int size_of_list);
	void print_by_id(int);
	void print_name_of_contacts();
	void manage_contacts(int);
	void edit_contact(int, Contact*);
	void print_contacts();
	void remove_contact(int, int);
	void remove_group(int);
	void print_contacts_sorted(std::string choice); // Only two choices first_name or last_name
	void merge_duplicates(); // Implement this function that finds and merges all the duplicates
	// Duplicate means exact equal, this means if
	void view_top_search();
	Contact* copy_contact();
	/*
	*  This function loads contacts from the given file (see details in ContactsBook.cpp)
	*/
	void load_from_file(std::string file_name);
	void save_to_file(std::string file_name);

private:
	bool full();
	void resize_list();
	void sort_contacts_list(Contact* contacts_list, std::string choice);
};
