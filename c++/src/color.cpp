
#include "color.hpp"

//constructeur sans argument 
color::color()
    :R(0),G(0),B(0)
{

}

//constructeur avec argument 
color::color(int r_arg,int g_arg,int b_arg)
    :R(r_arg),G(g_arg),B(b_arg)
{

}

//setter
const int& color::r() const{return color::R;}
const int& color::g() const{return color::G;}
const int& color::b() const{return color::B;}

// surcharge de l'operateur << pour afficher des element du type color
std::ostream& operator<<(std::ostream& stream,color const& c)
{
    stream<<c.r()<<" "<<c.g()<<" "<<c.b();
    return stream;
}

bool is_valid(color const& c)
{
    if(c.r()<0 || c.r()>255 || c.g()<0 || c.g()>255 || c.b()<0 || c.b()>255)
        return false;
    return true;
}

