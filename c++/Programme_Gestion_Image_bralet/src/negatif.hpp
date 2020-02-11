#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include <fstream>

class Color{
    int R,G,B;
public:
    //Constructeur
    Color(int r, int g, int b);
    
    //Getters
    const int& r() const {return R;}
    const int& g() const {return G;}
    const int& b() const {return B;}
    
    //Setters
    int& r() {return R;}
    int& g() {return G;}
    int& b() {return B;}
};

class Image{
  int h,w;
  std::vector<Color> pixels;
public:
  //Constructeur
  Image(int hauteur, int largeur,std::vector<Color> pixelslist);
  Image();
  
  //Getters
  const int& hauteur() const {return h;}
  const int& largeur() const {return w;}
  std::vector<int> f(int i,int h,int w);
  int g(int x, int y, int h, int w);
  void to_ppm(const std::string& filename);
  Color& operator() (int x, int y);
  static void neg(Image& im);
  static Image from_ppm (const std::string& filename);
};

std::ostream& operator<< (std::ostream& flux, Color const & color);
bool test_line(std::string line);
bool test_linecorrect(std::string& line);
bool test_arg(int arg);
