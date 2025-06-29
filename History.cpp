#include"History.h"
void History::set_search_words(std::string search_words)
{
	this->search_words = search_words;
}

void History::set_time_date()
{
	time_date = time(0);
	localtime_s(&get_time, &time_date);
}

std::string History::get_search_words() const
{
	return search_words;
}

tm History::get_time_date() const
{
	return get_time;
}