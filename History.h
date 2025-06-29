#pragma once
#include<iostream>
using namespace std;
class History
{
	tm get_time;
	string search_words;
	time_t time_date;
public:
	void set_search_words(string);
	void set_time_date();
	string get_search_words() const;
	tm get_time_date() const;
};
