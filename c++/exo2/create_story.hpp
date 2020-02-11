#ifndef CREATE_STORY_HPP
#define CREATE_STORY_HPP

#include <iostream>
#include <string>

class Date 
{
private:

	int m_day;
	int m_month;
	int m_year;

public:

	Date();
	Date(int ,int ,int);

	const int& day() const;
	const int& month() const;
	const int& year() const;

	int& day();
	int& month();
	int& year();

	static bool is_bissextile(int year);
	static bool is_date(int day_param, int month_param, int year_param);
	static Date from_string(const std::string& name);
	static std::string to_string(const Date& date);
};



class Person
{

private:
	std::string nom_value;
	Date dob_value;
public:

	Person();
	Person(std::string , Date);


	std::string& nom();
	Date& dob();

	int get_age(const Date& current_date);
	static void from_csv(const std::string& filename);

};

#endif