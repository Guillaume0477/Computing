#ifndef GEOMETRICAL_OBJECT_HPP
#define GEOMETRICAL_OBJECT_HPP
#include "vec2.hpp"
//SuperClasse permettant la gestion de tout objet géométrique qui en hérite
class geometrical_object{
  
public:
    /*Fonction permettant de calculer le point le plus proche d'un point donné en argument (et appartenant à la forme)
    * Cette fonction est impérativement implémentée par les héritiers */
    virtual vec2 closest_point(const vec2& point) const = 0;
    /*Fonction permettant de calculer la valeur d'un point de l'objet en une valeur donne en argument
    * Cette fonction est impérativement implémentée par les héritiers */
    virtual vec2 operator() (float s) const = 0;
};




#endif
