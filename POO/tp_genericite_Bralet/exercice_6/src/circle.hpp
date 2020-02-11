#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "vec2.hpp"
#include <iostream>
#include <cmath>
#include "geometrical_object.hpp"

//Classe permettant la modélisation d'un cercle en fonction de son rayon et de la position de son centre
//Classe fille de la classe geometrical_object
class circle : public geometrical_object{
  float R;  //Rayon du cercle
  vec2 c;   //Position du centre du cercle
  
public:
  //Constructeurs
  circle() = default;   //Par défaut
  circle(vec2 centre, float rayon);
  
  //Redefinition des methodes virtual de geometrical_object
  vec2 operator() (float s) const;
  vec2 closest_point(const vec2& point) const;
};





#endif