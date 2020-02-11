
#include "create_story.hpp"

#include <iostream>
#include <string>




Date::Date()
	:m_day(0),m_month(0),m_year(0) 
{}

Date::Date(int day_param,int month_param,int year_param)
	:m_day(day_param),m_month(month_param),m_year(year_param) 
{}

const int& Date::day() const {return Date::m_day;}
const int& Date::month() const {return Date::m_month;}
const int& Date::year() const {return Date::m_year;}

int& Date::day(){return Date::m_day;}
int& Date::month(){return Date::m_month;}
int& Date::year(){return Date::m_year;}



bool Date::is_bissextile(int year){
   if (((year%4==0)&&(year%100))||(year%400==0)){
        return true;
    } else {
        return false;
    }
}


bool Date::is_date(int day, int month, int year){
	    if ((month<1)||(month>12)){
        	return false;
    }
    if ((day<1)||(day>31)){
        return false;
    }
    switch (month){
        case 4:
        case 6:
        case 9:
        case 11:
            if (day==31){
                return false;
            }
            break;

        case 2:
            if (Date::is_bissextile(year)){
                if (day>29){
                    return false;
                }
            } else {
                if (day>28){
                    return false;
                }
            }
            break;
    }
    return true;
}



Date Date::from_string(const std::string& name){	
	int day,month,year;
	std::size_t pos1 = name.find('/');
	if (pos1!=std::string::npos){
		std::string strday =name.substr(0,pos1);
		day = std::stoi (strday);
	}
	else {
		std::cerr << "Error 2 : Date "<<std::endl;
	}
	std::size_t pos2 = name.find('/',pos1+1);
	if (pos2!=std::string::npos){
		std::string strmonth =name.substr(pos1+1,pos2);
		month = std::stoi (strmonth);
	}
	else {
		std::cerr << "Error 2 : Date "<<std::endl;
	}
	std::size_t pos3 = name.find('/',pos2+1);
	if (pos3==std::string::npos){
		std::string stryear =name.substr(pos2+1);
		year = std::stoi (stryear);
	}
	else {
		std::cerr << "Error 2 : Date "<<std::endl;
	}
	

	if (is_date(day,month,year)){
		return Date(day,month,year);
	}

}



std::string Date::to_string(const Date& date){
	std::string day_str = std::to_string(date.day());
	std::string month_str = std::to_string(date.month());
	std::string year_str = std::to_string(date.year());
  
	return day_str+ "/"+ month_str+ "/"+ year_str;
 
}





Person::Person()
	:nom_value(""),dob_value(Date())
{}


Person::Person(std::string nom_param, Date dob_param)
	:nom_value(nom_param),dob_value(dob_param)
{}




std::string& Person::nom(){return Person::nom_value;}

Date& Person::dob(){return Person::dob_value;}

int Person::get_age(const Date& current_date)
{
   int age = 0;
   
   Date dob = this->dob();
   int a_dob = dob.year();
   int m_dob = dob.month();
   int j_dob = dob.day();
   
   int a_cud = current_date.year();
   int m_cud = current_date.month();
   int j_cud = current_date.day();
   
   age = a_cud - a_dob;
   if (m_cud < m_dob || (m_cud=m_dob && j_cud < j_dob)){
     age = age - 1;
   }
   return age;
}
