#pragma once
#include<iostream>
using namespace std;
class groups
{
	string group_name;
	int* contact_id;
	int id_size;
	int id_count;
public:
	groups();
	void set_id_size(int);
	void set_contact_id(int);
	void set_group_name(string);
	string get_group_name() const;
	int get_count() const;
	void remove_id(int);
	void resize_list();
	int get_contact_id(int);
};