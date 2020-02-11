#include "bezier.hpp"
#include <iomanip>
#include <iostream>
#include <cmath>

//Constructeurs de la classe bezier
bezier::bezier(float p0, float p1, float p2, float p3)
  :P{p0,p1,p2,p3}
{}

//Fonction permettant l'affichage de la fonction
std::ostream& operator<< (std::ostream& flux, bezier const & b){  
  //Envoi de la chaine de caractère dans le flux d'affichage
  flux << "(1-s)^3*" << std::setprecision(3) << b.coeff(0) << "+3s(1-s)^2*" << std::setprecision(3) << b.coeff(1) << "+3s^2(1-s)*" << std::setprecision(3) << b.coeff(2) << "s^3*" << std::setprecision(3) << b.coeff(3);
  return flux;
}

//Fonction permettant le calcul de la valeur de la courbe de Bézier en le point f
float bezier::operator() (float f) const {
  float calcul = pow((1-f),3)*P[0]+ 3*f*pow((1-f),2)*P[1]+3*pow(f,2)*(1-f)*P[2]+pow(f,3)*P[3];
  
  return calcul;
}
