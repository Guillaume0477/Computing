#include <iostream>
#include <string>
#include <fstream>
#include <map>

class Date{
  int d, m, y;
public:
  //Constructeurs
  Date(int day,int month,int year);
  Date();
  //Getters
  const int& day() const {return d;}
  const int& month() const {return m;}
  const int& year() const {return y;}
  //Setters
  int& day() {return d;}
  int& month() {return m;}
  int& year() {return y;}
  
  //Fonctions statiques
  static bool is_date(int day, int month, int year);
  static Date from_string(const std::string& name);
  static std::string to_string(const Date& date);
};

class Person{
    std::string prenom;
    Date dob;
public:
    //Constructeur 
    Person();
    Person(std::string name, Date date);
    //Getters
    const std::string& getName() const {return prenom;}
    const Date& birth() const {return dob;}
    int get_age(const Date& current_date);
    
    //Methodes statiques
    static std::map<int,Person> from_csv(const std::string& filename);
};


bool is_bissextile(int year);
bool test_conformite(std::string date_name);
void RechercheHeader(std::string line, int& posid, int& posname,int& posdob);
void RechercheCorps(std::string line, std::string& idstr, int posid, std::string& nom, int posname, std::string& dob, int posdob);
int read_story(std::string filename, std::string name, std::string dob);
int test_arg(int& a);
int test_indice(int& indice, std::map<int,Person>& maMap, std::string& filename);
