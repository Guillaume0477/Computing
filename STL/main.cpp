

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <chrono>






bool fncomp (int lhs, int rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const int& lhs, const int& rhs) const
  {return lhs>rhs;}
};

int main() {

/*********************** map****************************/


    std::chrono::time_point<std::chrono::system_clock> start01,end01,start02,end02,start03,end03,start04,end04;


    //definition d’un set de nom: mon_vecteur stockant desentiers
    std::set<int>mon_set;							// empty set of ints

	std::cout<<"1"<<std::endl;
    //passage par référence constante
    //modification impossible des valeurs
    for(auto const&value: mon_set)
    	std::cout<< value<<" ";
    std::cout<<std::endl;

    //definition d’un vecteur de nom: mon_vecteur2 stockant des doubles
    std::set<double>mon_set2;

    std::cout<<"2"<<std::endl;
    for(auto const& value: mon_set2)
    	std::cout<<value<<" ";
    std::cout<<std::endl;
    
    //definition d’un vecteur de nom: mon_vecteur3 stockant des pointeurs//  vers des entiers
    std::set<int*>mon_set3;

    std::cout<<"3"<<std::endl;
    for(auto const& value: mon_set3)
    	std::cout<<value<<" ";
    std::cout<<std::endl;


    start01 = std::chrono::system_clock::now();

		int myints[]= {100,20,300,40,50,18,56,56};
	 	std::set<int> second (myints,myints+8);        // range


		std::cout<<"5"<<std::endl;
		for(auto const& value: second)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;

	end01 = std::chrono::system_clock::now();
	float elapsed_time01 = std::chrono::duration_cast<std::chrono::nanoseconds>(end01-start01).count();
	std::cout << "temps constructeur 1 : " << elapsed_time01 << "ns"<< std::endl;


    start02 = std::chrono::system_clock::now();

	 	std::set<int> third (second);                  // a copy of second

		std::cout<<"6"<<std::endl;
		for(auto const& value: third)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;


	end02 = std::chrono::system_clock::now();
	float elapsed_time02 = std::chrono::duration_cast<std::chrono::nanoseconds>(end02-start02).count();
	std::cout << "temps constructeur 2 : " << elapsed_time02 << "ns"<< std::endl;


    start03 = std::chrono::system_clock::now();

		std::set<int> fourth (second.begin(), second.end());  // iterator ctor.

		std::cout<<"7"<<std::endl;
		for(auto const& value: fourth)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;


	end03 = std::chrono::system_clock::now();
	float elapsed_time03 = std::chrono::duration_cast<std::chrono::nanoseconds>(end03-start03).count();
	std::cout << "temps constructeur 3 : " << elapsed_time03 << "ns"<< std::endl;


    start04 = std::chrono::system_clock::now();

	 	std::set<int,classcomp> fifth (myints,myints+8);                 // class as Compare

		std::cout<<"8"<<std::endl;
	 	for(auto const& value: fifth)
	    	std::cout<<value<<" ";
	    std::cout<<std::endl;


	end04 = std::chrono::system_clock::now();
	float elapsed_time04 = std::chrono::duration_cast<std::chrono::nanoseconds>(end04-start04).count();
	std::cout << "temps constructeur 4 : " << elapsed_time04 << "ns"<< std::endl;


 // 	bool(*fn_pt)(int,int) = fncomp;

 //  	std::set<int,bool(*)(int,int)> sixth (fn_pt);  // function pointer as Compare



	// std::cout<<"9"<<std::endl;
 //  	for(auto const& value: sixth)
 //    	std::cout<<value<<" ";
 //    std::cout<<std::endl;


/*********************** map****************************/


    std::chrono::time_point<std::chrono::system_clock> start1,end1,start2,end2;

    start1 = std::chrono::system_clock::now();

		std::map<char,int> first_map;
//cr�e les cases (1,10) et (2, 30)
		first_map['a']=10;
		first_map['b']=30;
		first_map['g']=860;
		first_map['c']=50;
		first_map['c']=5;
		first_map['k']=30;
		first_map.at[1]=70;

	end1 = std::chrono::system_clock::now();
	float elapsed_time1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1).count();
	std::cout << "temps execution insert dans map avec clé [] : " << elapsed_time1 << "ns"<< std::endl;


    start2 = std::chrono::system_clock::now();

	std::map<char,int> first_map2;

		first_map2.insert(std::pair<char,int>('a',10));
		first_map2.insert(std::pair<char,int>('b',30));
		first_map2.insert(std::pair<char,int>('g',860));
		first_map2.insert(std::pair<char,int>('c',50));
		first_map2.insert(std::pair<char,int>('c',5));
		first_map2.insert(std::pair<char,int>('k',30));
		first_map2.insert(std::pair<char,int>('d',70));


	end2 = std::chrono::system_clock::now();
	float elapsed_time2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end2-start2).count();
	std::cout << "temps execution insert dans map avec fct insert : " << elapsed_time2 << "ns"<< std::endl;



	std::chrono::time_point<std::chrono::system_clock> start11,end11,start12,end12,start13,end13,start14,end14;


	start11 = std::chrono::system_clock::now();

		std::cout<<"10"<<std::endl;
	    //passage par référence constante
	    //modification impossible des valeurs
	    for(auto const&value: first_map)
	    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
	    std::cout<<std::endl;

   	end11  = std::chrono::system_clock::now();
	float elapsed_time11= std::chrono::duration_cast<std::chrono::nanoseconds>(end11-start11).count();
	std::cout << "temps constructeur 4 : " << elapsed_time11 << "ns"<< std::endl;


	start12 = std::chrono::system_clock::now();

		std::map<char,int> second_map (first_map.begin(),first_map.end());
		
		std::cout<<"11"<<std::endl;
		for(auto const&value: second_map)
	    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
	    std::cout<<std::endl;

   	end12 = std::chrono::system_clock::now();
	float elapsed_time12 = std::chrono::duration_cast<std::chrono::nanoseconds>(end12-start12).count();
	std::cout << "temps constructeur 4 : " << elapsed_time12 << "ns"<< std::endl;



	start13 = std::chrono::system_clock::now();

		std::map<char,int> third_map (second_map);

		std::cout<<"12"<<std::endl;
		for(auto const&value: third_map)
	    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
	    std::cout<<std::endl;

   	end13 = std::chrono::system_clock::now();
	float elapsed_time13 = std::chrono::duration_cast<std::chrono::nanoseconds>(end13-start13).count();
	std::cout << "temps constructeur 4 : " << elapsed_time13 << "ns"<< std::endl;

	
	start14 = std::chrono::system_clock::now();

		std::map<char,int,classcomp> fourth_map (first_map.begin(),first_map.end());                 // class as Compare

		std::cout<<"("<<"13"<<std::endl;
		for(auto const&value: fourth_map)
	    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
	    std::cout<<std::endl;

 	end14 = std::chrono::system_clock::now();
	float elapsed_time14 = std::chrono::duration_cast<std::chrono::nanoseconds>(end14-start14).count();
	std::cout << "temps constructeur 4 : " << elapsed_time14 << "ns"<< std::endl;


	// bool(*fn_pt)(char,char) = fncomp;
	// std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare

    

/*********************** multiset****************************/




  	std::multiset<int>mon_multiset;							// empty set of ints

	std::cout<<"1"<<std::endl;
    //passage par référence constante
    //modification impossible des valeurs
    for(auto const&value: mon_multiset)
    	std::cout<< value<<" ";
    std::cout<<std::endl;


	int myintsmulti[]= {100,20,300,40,50,18,56,56};
 	std::multiset<int> second_multiset (myintsmulti,myintsmulti+8);        // range

	std::cout<<"5"<<std::endl;
	for(auto const& value: second_multiset)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

 	std::multiset<int> third_multiset (second_multiset);                  // a copy of second

	std::cout<<"6"<<std::endl;
	for(auto const& value: third_multiset)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

	std::multiset<int> fourth_multiset (second_multiset.begin(), second_multiset.end());  // iterator ctor.

	std::cout<<"7"<<std::endl;
	for(auto const& value: fourth_multiset)
    	std::cout<<value<<" ";
    std::cout<<std::endl;

 	std::multiset<int,classcomp> fifth_multiset (myintsmulti,myintsmulti+8);                 // class as Compare

	std::cout<<"8"<<std::endl;
 	for(auto const& value: fifth_multiset)
    	std::cout<<value<<" ";
    std::cout<<std::endl;



/*********************** multimap****************************/


	std::multimap<char,int> first_multimap;

	// first_multimap['a']=10;
	// first_multimap['b']=30;
	// first_multimap['g']=860;
	// first_multimap['c']=50;
	// first_multimap['k']=30;
	// first_multimap['d']=70;



	first_multimap.insert(std::pair<char,int>('a',10));
	first_multimap.insert(std::pair<char,int>('b',30));
	first_multimap.insert(std::pair<char,int>('g',860));
	first_multimap.insert(std::pair<char,int>('c',50));
	first_multimap.insert(std::pair<char,int>('c',5));
	first_multimap.insert(std::pair<char,int>('k',30));
	first_multimap.insert(std::pair<char,int>('d',70));


	std::cout<<"10"<<std::endl;
    //passage par référence constante
    //modification impossible des valeurs
    for(auto const&value: first_multimap)
    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
    std::cout<<std::endl;

	std::multimap<char,int> second_multimap (first_multimap.begin(),first_multimap.end());
	
	std::cout<<"11"<<std::endl;
	for(auto const&value: second_multimap)
    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
    std::cout<<std::endl;

	std::multimap<char,int> third_multimap (second_multimap);

	std::cout<<"12"<<std::endl;
	for(auto const&value: third_multimap)
    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
    std::cout<<std::endl;

	std::multimap<char,int,classcomp> fourth_multimap (first_map.begin(),first_map.end());                 // class as Compare

	std::cout<<"("<<"13"<<std::endl;
	for(auto const&value: fourth_multimap)
    	std::cout<<"("<< value.first << " associé " << value.second <<")"<<" ";
    std::cout<<std::endl;


	// bool(*fn_pt)(char,char) = fncomp;
	// std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare







  	return 0;
}







