#include"groups.h"
groups::groups()
{
	id_size = 0;
	id_count = 0;
	contact_id = nullptr;
}
void groups::set_group_name(string name)
{
	this->group_name = name;
}
int groups::get_contact_id(int index)
{
	return contact_id[index];
}
void groups::set_contact_id(int id)
{
	if (id_count >= id_size)
		resize_list();
	contact_id[id_count] = id;
	id_count++;
}
string groups::get_group_name() const
{
	return group_name;
}
void groups::set_id_size(int size)
{
	this->id_size = size;
	contact_id = new int[id_size];
}
int groups::get_count() const
{
	return id_count;
}
void groups::resize_list()
{
	int* temp_id = new int[id_size];
	for (int i = 0; i < id_count; i++)
	{
		temp_id[i] = contact_id[i];
	}
	delete[] contact_id;
	id_size = id_size * 2;
	contact_id = new int[id_size];
	for (int i = 0; i < id_count; i++)
	{
		contact_id[i] = temp_id[i];
	}
	delete[] temp_id;
	temp_id = nullptr;
}
void groups::remove_id(int id)
{
	if (!(id_count - 1 == id))
	{
		for (int i = id; i < id_count; i++)
		{
			contact_id[i] = contact_id[i + 1];
		}
	}
	contact_id[id_count - 1] = 0;
	id_count--;
}
