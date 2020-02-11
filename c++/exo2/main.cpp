

#include "create_story.hpp"


#include <iostream>
#include <string>


//using namespace std;



int main()
{	



	Date date1=Date::from_string("10/10/1950");
	std::string date1_str=Date::to_string(date1);
	std::cout<<date1_str<<std::endl;

	Person guigui1 = Person();
	Person guigui2 = Person("guillaume",Date(13,9,1997));

	std::cout<<guigui1.nom()<<std::endl;
	std::cout<<Date::to_string(guigui1.dob())<<std::endl;
	std::cout<<guigui2.nom()<<std::endl;
	std::cout<<Date::to_string(guigui2.dob())<<std::endl;

	std::cout<<guigui2.get_age(Date(5,3,2019))<<std::endl;



	return(0);


}

