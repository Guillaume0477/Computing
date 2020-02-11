
#include "image.hpp"

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>


using namespace std;






// verifie les bornes x et y
void image::assert_coord(int x,int y) const
{
    if(x<0 || x>=Nx || y<0 || y>=Ny)
    {
        std::cerr<<"Index "<<x<<","<<y<<" hors bornes."<<std::endl;
        exit(1);
    }
}

const color& image::operator()(int x,int y) const
{
    assert_coord(x,y);
    return data[y+Ny*x];
}

// on defini un operateur () qui s'applique au type image et permet de grandement simplifier le code 
// si on compare à java
color& image::operator()(int x,int y)
{
    assert_coord(x,y);
    return data[y+Ny*x];
}

//prend en argument les dimentions pour redimentionner le vecteur contenant les pixels
void image::resize(int Nx_arg,int Ny_arg)
{
    Nx=Nx_arg;
    Ny=Ny_arg;
    data.resize(Nx_arg*Ny_arg);
}



//lit un fichier et crée une nouvelle image contenant les valeur des pixels inversé
image from_ppm(const string& filename){

    image ima;

    ifstream flux(filename.c_str(),ios::in);
    if (flux){
        string ligne;
        int dim1,dim2,lim;
        flux >> ligne >> dim1 >> dim2 >>lim;
        ima.resize(dim1,dim2);
        for (int x=0;x<dim1;x++){// les pixels
            for (int y=0;y<dim2;y++){
                int entierR,entierG,entierB;
                flux >> entierR >> entierG >> entierB;
                ima(x,y)=color(255-entierR,255-entierG,255-entierB);
            }
        }
    }
    else{
        cerr << "Error 3 : "<< filename<<" not found" << endl;
    }

    return(ima);
}

// fait un ficher filenam-neg.pmm contenant l'image inversé de l'image en argument
void to_ppm(const std::string& filename){

    image img_origine_neg=from_ppm(filename);
    std::size_t taille = filename.size();
    string new_filename = filename.substr(0,taille-4);
    new_filename += "-neg.ppm";

    ofstream flux(new_filename,ios::out|ios::trunc);
    if (flux){
        flux << "P3" << endl;
        int dim1,dim2;
        dim1=img_origine_neg.Nx;
        dim2=img_origine_neg.Ny;
        flux << dim1 << " " << dim2 << endl;
        flux << 255 << endl;
        for (int x=0;x<dim1;x++){// les pixels
            for (int y=0;y<dim2;y++){
                flux << img_origine_neg(x,y) << endl;
            }
        }

    }
       else{
        cerr << "Error 3 : "<< filename<<" not found" << endl;
    }




}






