#include<iostream>
#include"contact_history.h"
contact_history::contact_history(int search_size)
{
	this->search_size = search_size;
	search_history = new History[search_size];
	search_count = 0;
}
void contact_history::input_history(string search)
{
	if (search_count >= search_size)
	{
		resize_Obj();
	}
	search_history[search_count].set_search_words(search);
	search_history[search_count].set_time_date();
	search_count++;
}

void contact_history::get_history(int search_index)
{
	tm search_time = search_history[search_index].get_time_date();
	cout << "Search " << search_index + 1 << endl;
	cout << "Time: " << search_time.tm_hour << ":" << search_time.tm_min << ":" << search_time.tm_sec << ", Date: " << search_time.tm_mday << "/" << search_time.tm_mon + 1 << "/" << search_time.tm_year + 1900 << endl;
	cout << "string: " << search_history[search_index].get_search_words() << endl;
}

void contact_history::resize_Obj()
{
	History* temp_obj = new History[search_size];
	for (int i = 0; i < search_count; i++)
	{
		temp_obj[i] = search_history[i];
	}
	delete[]search_history;
	search_history = nullptr;
	search_size *= 2;
	search_history = new History[search_size];
	for (int i = 0; i < search_count; i++)
	{
		search_history[i] = temp_obj[i];
	}
	delete[]temp_obj;
	temp_obj = nullptr;
}
int contact_history::get_search_count()
{
	return search_count;
}