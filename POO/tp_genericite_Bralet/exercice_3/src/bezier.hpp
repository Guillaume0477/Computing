
#ifndef BEZIER_HPP
#define BEZIER_HPP
#include <iomanip>
#include <iostream>
#include <cmath>
#include <array>

//Classe template permettant la gestion d'une courbe de bezier a partir de ses coefficients
template <typename T>
class bezier {
  //Coefficients de la courbe dans un vecteur
  std::array<T,4> P;
  
public:
  //Constructeurs
  bezier<T>():P{0.0f, 0.0f, 0.0f, 0.0f}{}
  bezier<T>(T p0, T p1, T p2, T p3):P{p0,p1,p2,p3}{}
  
  //Getters
  const T& coeff(int i) const {return P[i];}
  
  //Setters
  T& coeff(int i) {return P[i];}
  
  //Fonction permettant le calcul de la courbe de bézier en un flottant passé en paramètre
  T operator() (float f) const{
    T calcul = pow((1-f),3)*P[0]+ 3*f*pow((1-f),2)*P[1]+3*pow(f,2)*(1-f)*P[2]+pow(f,3)*P[3];
    return calcul;
  }
};

//Création de la fonction template permettant la surcharge de l'opérateur <<
template<typename T>
//Fonction permettant l'affichage de la fonction définie par la courbe de Bézier
std::ostream& operator<< (std::ostream& flux, bezier<T> const & b){  
  //Envoi de la chaine de caractère dans le flux d'affichage
  flux << "(1-s)^3*" << std::setprecision(3) << b.coeff(0) << "+3s(1-s)^2*" << std::setprecision(3) << b.coeff(1) << "+3s^2(1-s)*" << std::setprecision(3) << b.coeff(2) << "s^3*" << std::setprecision(3) << b.coeff(3);
  return flux;
};

#endif