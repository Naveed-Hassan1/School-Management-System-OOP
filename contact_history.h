#pragma once
#include"History.h"
using namespace std;
class contact_history
{
	int search_size;
	History* search_history;
	int search_count;
public:
	contact_history(int);
	void input_history(string);
	void resize_Obj();
	int get_search_count();
	void get_history(int);
};