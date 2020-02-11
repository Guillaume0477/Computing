
#ifndef BEZIER_HPP
#define BEZIER_HPP
#include <iomanip>
#include <iostream>
#include <cmath>
#include <array>

//Création de la classe template permettant de calculer les points d'une courbe de bézier à partir de ses coefficients
template <typename T>   //Le template agit sur le type des coefficients (float, int, vec2 ....)
class bezier {
  //Coefficients de la courbe dans un vecteur
  std::array<T,4> P;
  
public:
  //Constructeurs
  bezier<T>() = default;    //Par défaut
  bezier<T>(const T& p0, const T& p1, const T& p2, const T& p3):P{p0,p1,p2,p3}{}
  
  //Getters
  const T& coeff(int i) const {return P[i];}
  
  //Setters
  T& coeff(int i) {return P[i];}
  
  //Fonction permettant de calculer la valeur de la courbe en un flottant passé en argument
  T operator() (float f) const{
    T calcul = pow((1-f),3)*P[0]+ 3*f*pow((1-f),2)*P[1]+3*pow(f,2)*(1-f)*P[2]+pow(f,3)*P[3];
    
    return calcul;
  }
};

//Création de la fonction template permettant de surcharger l'opérateur <<
template<typename T>
//Fonction permettant l'affichage de la fonction définie par la courbe de Bézier
std::ostream& operator<< (std::ostream& flux, bezier<T> const & b){  
  //Envoi de la chaine de caractère dans le flux d'affichage
  flux << "(1-s)^3*" << std::setprecision(3) << b.coeff(0) << "+3s(1-s)^2*" << std::setprecision(3) << b.coeff(1) << "+3s^2(1-s)*" << std::setprecision(3) << b.coeff(2) << "s^3*" << std::setprecision(3) << b.coeff(3);
  return flux;
};

#endif