
#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <fstream>
#include "negatif.hpp"

/*------------------------------------------------------------------------------
 * Fonction principale
 * ---------------------------------------------------------------------------*/

int main(int argc, char* argv[]){
    
    //Test s'il y a assez d'arguments dans la fonction
    if (!(test_arg(argc))){
        std::cerr << "Error 1 : Running out of arguments" << std::endl;
        return 1;
    }
    
    //Récupération du fichier
    std::string file = argv[1];
    //Récupération des données de l'image
    Image imageb = Image::from_ppm(file);
    
    //Test si l'image a pu être importée
    if ((imageb.hauteur() == 0) & (imageb.largeur() == 0)){
        std::cerr << "Error 3 : Image " << file << " not found " << std::endl;
        return 3;
    }
    
    //Transformation de l'image (passage au négatif)
    Image::neg(imageb);
    
    //Modification du nom de l'image
    std::string nouvnom = file;
    nouvnom = nouvnom.substr(0, nouvnom.size()-4) + "-neg.ppm";
    //Création de la nouvelle image
    imageb.to_ppm(nouvnom);
    
    return 0;
}

/*------------------------------------------------------------------------------
 * Fonction internes à la classe Color
 * ---------------------------------------------------------------------------*/
//Constructeur
Color::Color(int r, int g, int b){
    //Test de la validité de la couleur et attribution de la valeur
    if ((0 <= r) && (r<=255)){
        R = r;
    }
    if ((0 <= b) && (b<=255)){
        B = b;
    }
    if ((0 <= g) && (g<=255)){
        G = g;
    }
}

/*------------------------------------------------------------------------------
 * Opérateurs particuliers à la classe Color
 * ---------------------------------------------------------------------------*/
//Opérateurs d'affichage
std::ostream& operator<< (std::ostream& flux, Color const & color){
    int r = color.r();
    int b = color.b();
    int g = color.g();
    //Création de la chaine de caractère à afficher
    std::string ret = std::to_string(r) + ' ' + std::to_string(g) + ' ' + std::to_string(b);
    //Affichage dans le flux de sortie
    flux << ret;
    return flux;
}

/*------------------------------------------------------------------------------
 * Fonction internes à la classe Image
 * ---------------------------------------------------------------------------*/

//Constructeur
Image::Image(int hauteur, int largeur,std::vector<Color> pixelslist){
  h = hauteur;  //Hauteur de l'image (nombre de lignes)
  w = largeur;  //Largeur de l'image (nombre de colonne)
  pixels = pixelslist;  //liste des pixels sous forme d'objet Color
}

//Fonction permettant de connaitre les coordonnées d'un pixel en fonction d'un indice donné
std::vector<int> Image::f(int i,int h,int w){
  std::vector<int> coords;
  int x = -1;
  int y = -1;
  //Vérification de la validité de l'indice
  if (i <= h*w) {
    y = i/w;    //Calcul de l'indice de ligne
    x = i-y*w;  //Calcul de l'indice de colonne
  }
  //Retour des coordonnées du pixel
  coords.push_back(x);
  coords.push_back(y);
  return coords;
}

//Fonction permettant de connaitre l'indice d'un pixel en fonction de ses coordonnées
int Image::g(int x, int y, int h, int w){
  int indice = -1;
  //Vérification de la validité des coordonnées
  if ((x <= w) && (y<=h)) {
      //Calcul de l'indice
      indice = w*(y-1)+x-1;
  }
  return indice;
}

//Fonction permettant de créer une image au format ppm
void Image::to_ppm(const std::string& filename){
  std::ofstream myfile (filename, std::ios::out | std::ios::trunc);
  if (myfile.is_open()){
    // Création du header
    myfile << "P3\n" << w << ' ' << h << '\n' << 255 <<'\n';
    //Ajout des données des pixels
    uint i = 0;
    for (i = 0; i < pixels.size(); i++){
        myfile << pixels[i] << '\n';
    }
  }
}

//Fonction permettant d'importer une image en ppm
Image Image::from_ppm(const std::string& filename){
    std::ifstream myfile (filename, std::ios::in);
    if (myfile.is_open()){
        std::string line;
        std::string linecorrect;
        std::string word;
        std::vector<Color> listpix;
        //Recherche de la hauteur et de la largeur de l'image dans le fichier
        getline(myfile, line);
        while (!(test_line(line))){ //Vérification que la ligne en cours est uniquement composée de chiffres
            getline(myfile, line);
        }
        int h,w;
        //Extraction de la hauteur et de la largeur de l'image
        w = std::stoi(line.substr(0, line.find(' ')));
        h = std::stoi(line.substr(line.find(' ') + 1, line.find(' ', line.find(' ') + 1)));
        //Recherche de la valeur des pixels
        getline(myfile, line);
        getline(myfile, line);
        //Parcour de toutes les lignes du fichier
        while (line.size() != 0){
            //Création d'une ligne exploitable (soit minimum 3 valeurs par ligne)
            linecorrect = line;
            while (!test_linecorrect(linecorrect)){
                //Ajout d'un espace permettant de séparer les valeurs
                linecorrect.append(" ");
                //Sélection d'une nouvelle ligne
                getline(myfile, line);
                linecorrect += line;
            }
            linecorrect.append(" ");

            
            int oldpos = 0;
            int pos1,pos2,pos3,R,V,B;
            
            //Extraction des différentes couleurs des pixels présents dans la ligne
            while (linecorrect.find(' ', oldpos) != std::string::npos){
                //Recherche des position des différents séparateurs de valeurs
                pos1 = linecorrect.find(' ', oldpos);
                pos2 = linecorrect.find(' ', pos1+1);
                pos3 = linecorrect.find(' ', pos2+1);
                //Extraction des couleurs : Rouge, Vert et Bleu
                R = std::stoi(linecorrect.substr(oldpos, pos1));
                V = std::stoi(linecorrect.substr(pos1+1, pos2 - pos1 - 1));
                B = std::stoi(linecorrect.substr(pos2 + 1, pos3 - pos2 - 1));
                
                //Création d'une nouvelle couleur
                Color newcolor(R,V,B);
                //Ajout de la couleur dans la liste
                listpix.push_back(newcolor);
                //Actualisation de la position
                oldpos = pos3+1;
            }
            //Actualisation de la ligne à traiter
            getline(myfile, line);
        }
        //Création de l'image à créer
        Image image(h,w,listpix);
        return image;
    } else {
        //Création d'une image nulle en cas d'erreur
        std::vector<Color> pix;
        Image image(0,0,pix);
        return image;

    }
    
}

//Permet de faire le négatif d'une image
void Image::neg(Image& im) {
    int x,y;
    //Parcours des pixels de l'image
    for (x = 1; x <= im.w; x++){
        for (y=1; y<= im.h; y++){
            //Passage au négatif des couleurs
            im(x,y).r() = 255 - im(x,y).r();
            im(x,y).g() = 255 - im(x,y).g();
            im(x,y).b() = 255 - im(x,y).b();
        }
    }
}

/*------------------------------------------------------------------------------
 * Opérateurs particuliers à la classe Image
 * ---------------------------------------------------------------------------*/

//Extraction de la couleur présente aux coordonnées données
Color& Image::operator() (int x, int y){
    int i = g(x,y,h,w);
    return pixels[i];
}

/*------------------------------------------------------------------------------
 * Fonctions utiles à la classe Image
 * ---------------------------------------------------------------------------*/

//Permet de tester si la ligne en cours est constituée uniquement de chiffres (Recherche de la hauteur et de la largeur de l'image)
bool test_line(std::string line){
    uint i = 0;
    bool ret = true;
    //Si la ligne ne comprends qu'un caractère (comme \n)
    if (line.size() <= 1){
        ret = false;
    } else { //Test s'il n'y a que des chiffres, des espaces ou des retours chariots
        for (i = 0; i < line.size() ; i++){
            if (!(((0x30 <= line[i]) && (line[i] <= 0x39)) | (line[i] == ' ') | (line[i] == '\n'))){
                ret = false;
                break;
            }
        }
    }
    return ret;
}

//Permet de tester si la ligne contient suffisemment de valeurs
bool test_linecorrect(std::string& line){
    bool ret;
    //Recherche d'un premier séparateur
    if (line.find(' ') != std::string::npos){
        //Récherche d'un second séparateur
        if (line.find(' ', line.find(' ') + 1) != std::string::npos){
            ret = true;
        } else {
            ret = false; 
        }
    } else { 
        ret = false;
    }
    return ret;
}

/*------------------------------------------------------------------------------
 * Fonctions de test du programme
 * ---------------------------------------------------------------------------*/

//Fonction permettant de tester la validité du nombre d'arguments
bool test_arg(int arg){
    if (arg < 2) {
        return false;
    }
    return true;
}


