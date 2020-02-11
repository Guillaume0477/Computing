#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include "create_story.hpp"

/* ------------------------------------------------------------------------------------------
 * Fonction principale
 * ----------------------------------------------------------------------------------------*/

int main(int argc, char* argv[]){
    /*Date date(22,12,13);// = Date::from_string("02/04/1999");
    std::cout << date.day() << ' ' << date.month() << ' ' << date.year() << std::endl;
    date.day() = 29;
    std::cout << Date::to_string(date) << std::endl;
    const int x = date.day();
    //x = 12;
    std::cout << x << ' ' << date.month() << ' ' << date.year() << std::endl;
    
    std::string c = "Coucou";
    Person Jean;
    Date date(22,11,2013);
    std::cout << Jean.get_age(date) << '\n' ;
    std::cout << c.back() << '\n';*/
    
    //Test si le nombre d'argument est correct
    int ret1 = test_arg(argc);
    if (ret1 != 0) {
      return ret1;
    }
    
    //Récupération des données
    std::string filename = argv[1];
    std::string carnet = argv[2];
    int indice = std::stoi(argv[3]);
    
    //Récupération de la liste des personnes à partir du carnet
    std::map<int,Person> maMap = Person::from_csv(carnet);
    
    //Vérification que le carnet a bien pu être lu et qu'il est consistant
    if (maMap.size() == 0){
      return 4;
    }
//     int a = maMap[1].get_age(Date::from_string("22/11/2013"));
//     int b = maMap[10].get_age(Date::from_string("22/11/2013")); 
//     std::cout << a  << '\n' << b << std::endl;

    //Affichage du carnet
    for (std::pair<int,Person> Ref : maMap){
      std::cout << Ref.first << " " << Ref.second.getName() << " " << Date::to_string(Ref.second.birth()) << std::endl;
    }
    
    //Test si l'indice existe dans les id du carnet
    int ret5 = test_indice(indice, maMap, carnet);
    if (ret5 != 0) {
      return ret5;
    } 
    
    //Récupérations des données de la personne
    std::string name = maMap[indice].getName();
    std::string dob = Date::to_string(maMap[indice].birth());
    
    //Lecture de l'histoire à partir des données récupérées
    read_story(filename,name,dob);
    
    return 0;
}


/* ------------------------------------------------------------------------------------------
 * Fonctions interne à la classe Date
 * ----------------------------------------------------------------------------------------*/

//Constructeur de la date
Date::Date(int day, int month, int year){
  if(Date::is_date(day,month,year)) {
    d = day;
    m = month;
    y = year;
  } else {
    d = 0;
    m = 0;
    y = 0;
  }
}

//Constructeur par défaut
Date::Date(){
    d = 0;
    m = 0;
    y = 0;
}

/*Teste si la date a existée*/
bool Date::is_date(int day, int month, int year){
    bool is_bissex=is_bissextile(year);
    if ((day<1) || (day>31) || (year<1) || (month<1) || (month>12)){
        return 0;
    }
    else if ((day==31) && ((month==2) || (month==4) || (month==6) || (month==9) || (month==11))){
        return 0;
    }
    else if ((month==2) && (day==29) && (is_bissex==0)){
        return 0;
    }
    return 1;
}

/*Fonction permettant d'isoler la date en fonction d'une chaine de caractère*/
Date Date::from_string(const std::string& name){
    Date date;
    //Test si la date est bien conforme (du type jj/mm/aaaa)
    if (test_conformite(name)){
      int pos1 = name.find('/');
      int pos2 = name.find('/',pos1+1);
      
      //Isolation des données
      date.day() = std::stoi(name.substr(0,pos1)); //récupération du jour
      date.month() = std::stoi(name.substr(pos1+1,pos2-pos1-1)); //récupération du mois 
      date.year() = std::stoi(name.substr(pos2+1,name.length() - pos2+1)); //récupération de l'année

    } 
    return date;
}

//Transformation de la date en string sous forme jj/mm/aaaa
std::string Date::to_string(const Date& date){
    std::string date_str;
    int day = date.day();
    int month = date.month();
    int year = date.year();
    date_str = std::to_string(day) + '/' + std::to_string(month) + '/' + std::to_string(year);
    return date_str;
}

/* ----------------------------------------------------------------------------------------------
 * Fonctions utiles à la classe Date
 * --------------------------------------------------------------------------------------------*/

/* Test la conformité de la date*/
bool test_conformite(std::string date_name){
    bool ret = true ;
    //Test de la conformité de la chaine de caractère
    if((date_name.length() > 10)) {//| (date_name[2] != '/') | (date_name[5] != '/')) {
      ret = false;
    }
    
    //Test de l'utilisation uniquement de / et de chiffres
    for (unsigned int i = 0; i<date_name.length(); i++){
      if (!(((date_name[i] >= 0x30) & (date_name[i] <= 0x39)) | (date_name[i] == 0x2F))){
	ret = false;
      }
    }
    return ret;
}

/*Teste si l'année est bissextile*/
bool is_bissextile(int year){
    if ((year%4==0) && (year%100!=0)){
        return 1;
    }
    else if (year%400==0){
        return 1;
    }
    return 0;
}

/*-----------------------------------------------------------------------------------------------
 * Fonctions internes à la classe Person
 * --------------------------------------------------------------------------------------------*/

//Constructeur de la classe Person par défaut
Person::Person(){
    prenom = "Undefined";
    Date d;
    dob = d;
}

//Constructeur de la classe Person
Person::Person(std::string name , Date date){
    prenom = name;
    dob = date;
}

//Fonction permettant de calculer l'age de la personne en question
int Person::get_age(const Date& current_date){
    int age = 0; 
    //Récupération des données
    age = current_date.year() - this->birth().year();
    int mois = this->birth().month();
    int jour = this->birth().day();
    
    //Test si l'anniversaire de la personne est déjà passé ou non
    if ((mois > current_date.month()) || ((mois == current_date.month()) && (jour > current_date.day()))){
        age -= 1;
    }
    return age;
}

//Création d'une map associant chaque identifiant à une personne à partir d'un fichier csv
std::map<int,Person> Person::from_csv(const std::string& filename){
    std::map<int,Person> maMap;
    std::string file = filename;
    std::string line;
    std::ifstream myfile (filename, std::ifstream::in);
    std::string word;
    
    //Vérification de la bonne ouverture du fichier
    if (myfile.is_open()){    
        //Obtention du header
        getline (myfile,line);
        
        // Travail sur le header
        int posid;
        int posname;
        int posdob;
        
        //Recherche des trois chaines de caractères dans le header
        RechercheHeader(line, posid, posname, posdob);

        getline(myfile,line);
        
        while (line.size() != 0){
            std::string nom;
            std::string idstr;
            std::string dob;
            int id;

            //Recherche des informations à stocker
            RechercheCorps(line, idstr, posid, nom, posname, dob, posdob);

            //Création de la personne à ajouter
            Person nouveau(nom,Date::from_string(dob));

            //Conversion de l'identifiant en int
            id = std::stoi(idstr);
	    
            //Insertion dans la map 
            maMap.insert(std::pair<int,Person> (id,nouveau));
            
            //Changement de ligne
            getline(myfile,line);

            
        }
    } else {
        //Si le fichier n'est pas ouvert, signalement à l'utilisateur
          std::cerr << "Error 4 : Address book " << filename << "not found " << std::endl;
    }
    
    return maMap;
}

/* ----------------------------------------------------------------------------------------------
 * Fonctions utiles à la classe Person
 * --------------------------------------------------------------------------------------------*/

//Fonction permettant de rechercher après combien de virgules se trouve l'information à extraire
void RechercheHeader(std::string line, int& posid, int& posname, int& posdob){
    int pos = line.find(',');
    int oldpos = 0;
    int cpt = 0;
    std::string s1("$id");
    std::string s2("$name");
    std::string s3("$dob");
    std::string word;

    
    while (line.find(',',oldpos) != std::string::npos){
        //Extraction des mots de la ligne
        word = line.substr(oldpos,pos-oldpos);            
        if (word.compare(s1) == 0){ //Recherche de $id
            posid = cpt;
        } else if (word.compare(s2) == 0){ //Recherche de $name
            posname = cpt;
        } else if (word.compare(s3) == 0) { //Recherche de $dob
            posdob = cpt;
        }
        cpt+=1;                         //Actualisation de la référence de la virgule
        oldpos = pos+1;                 //Actualisation de la position basse
        pos = line.find(',',oldpos);    //Actualisation de la position haute
    }
    //Extraction des mots de la ligne
    word = line.substr(oldpos,pos-oldpos);        
    if (word.compare(s1) == 0){ //Recherche de $id
        posid = cpt;
    } else if (word.compare(s2) == 0){ //Recherche de $name
        posname = cpt;
    } else if (word.compare(s3) == 0) { //Recherche de $dob
        posdob = cpt;
    }
}

//Fonction permettant de récupérer les informations nécessaires à la création de la map : id, nom et date de naissance
void RechercheCorps(std::string line, std::string& idstr, int posid, std::string& nom, int posname, std::string& dob, int posdob){
    int cpt = 0;
    int pos = line.find(',');
    int oldpos = 0;
    
    //Recherche des données
    while (line.find(',',oldpos) != std::string::npos){
        if (cpt == posid){ //Recherche de $id
            idstr = line.substr(oldpos,pos-oldpos);
        } else if (cpt == posname){ //Recherche de $name
            nom = line.substr(oldpos,pos-oldpos);
        } else if (cpt == posdob) { //Recherche de $dob
            dob = line.substr(oldpos,pos-oldpos);
        }

        cpt+=1;                         //Actualisation de la référence de la virgule
        oldpos = pos+1;                 //Actualisation de la position basse
        pos = line.find(',',oldpos);    //Actualisation de la position haute
    }
    
    if (cpt == posid){ //Recherche de $id
        idstr = line.substr(oldpos,pos-oldpos);
    } else if (cpt == posname){ //Recherche de $name
        nom = line.substr(oldpos,pos-oldpos);
    } else if (cpt == posdob) { //Recherche de $dob
        dob = line.substr(oldpos,line.length()-oldpos);
    }
}

/* ----------------------------------------------------------------------------------------------
 * Fonctions utiles au programme
 * --------------------------------------------------------------------------------------------*/

/*Fonction de test du nombre d'arguments*/
int test_arg(int& a){
  int ret = 0;
  if (a < 4){
    std::cerr << "Error 1 : Running out of arguments" << std::endl;
    ret = 1;
  }
  return ret;
}

/*Fonction de test de l'indice passé en arguments*/
int test_indice(int& indice, std::map<int,Person>& maMap, std::string& filename){
  int ret = 0;
  Person nouv = maMap[indice];
  if (nouv.getName().compare("Undefined") == 0){
    std::cerr << "Error 5 : Id " << indice << " not found in " << filename << std::endl;
    ret = 5;
  }
  return ret;
}

/* Fonction permettant de raconter l'histoire*/
int read_story(std::string filename, std::string name, std::string dob){
    std::string s1("$(name)");
    std::string s2("$(dob)");
    std::string word;
    std::ifstream myfile (filename, std::ifstream::in);
    if (myfile.is_open()){    
        //Obtention du premier mot
        getline (myfile,word,' ');
        std::string wordbis = word;
        do { //Itération jusqu'à ce qu'un mot apparaisse deux fois de suite
            
	    if (word.compare(wordbis) != 0) {
		std::cout << ' ';
	    }
	    //Test si le $(name) est le mot en cours et changement le cas échéant
            while (word.find(s1)!= std::string::npos){
                word.replace(word.find(s1), s1.length(), name);
            }
            //Test si le $(dob) est le mot en cours et changement le cas échéant
            while (word.find(s2)!= std::string::npos){
                word.replace(word.find(s2), s2.length(), dob);
            }
            //Actuallisation du mot comparatoire
            wordbis = word;
            //Affichage du mot courant
            std::cout << word;
            //Capture du mot suivant
            getline (myfile,word,' ');
        //Test pour éviter la redondance de la fonction    
        } while (word.compare(wordbis) != 0);
    } else {
        //Si le fichier n'est pas ouvert, signalement à l'utilisateur
          std::cerr << "Error 3 : Story " << filename << "not found " << std::endl;
	  return 3;
    }
    //Fermeture du fichier
    return 0;
}


















