
#ifndef BEZIER_HPP
#define BEZIER_HPP
#include <iomanip>
#include <iostream>
#include <cmath>
#include <array>
#include "geometrical_object.hpp"

//Classe template permettant de modéliser une courbe de bézier à partir de ses coefficients (points de référence)
template <typename T>
class bezier : public geometrical_object{
  //Coefficients de la courbe dans un vecteur
  std::array<T,4> P;
  
public:
  //Constructeurs
  bezier<T>() = default;    //Par défaut
  bezier<T>(T p0, T p1, T p2, T p3):P{p0,p1,p2,p3}{}
  
  //Getters
  const T& coeff(int i) const {return P[i];}
  
  //Setters
  T& coeff(int i) {return P[i];}
  
  T operator() (float f) const{
    T calcul = pow((1-f),3)*P[0]+ 3*f*pow((1-f),2)*P[1]+3*pow(f,2)*(1-f)*P[2]+pow(f,3)*P[3];
    
    return calcul;
  }
  
  //Fonction permettant de calculer le point de la courbe le plus proche d'un point donné en paramètre
  T closest_point(const T& point) const{
    int N = 100;	//Nombres de points de la courbe de bézier
    T pt_proche;        //Initialisation de la référence au point le plus proche
    float dist = 10000; //Distance minimale entre le point et un point de la courbe
    bezier b = *this;   //Référenciation de la courbe de bézier (nécessaire pour l'utilisation de l'opérateur ())
    for(int i = 0; i < N ; i++){
      //s : le parametre de la courbe de bézier
      float s = i/float((N-1));
      
      //Calcul du point de la courbe de bézier
      T pt = b(s);
      
      //Détermination du vecteur représentatif de la distance entre le point courant de la courbe et le point
      T const v = point-pt;
      
      //Actualisation du point le plus proche et de sa distance si necessaire
      if(norm(v) < dist){
	dist = norm(point-pt);
	pt_proche = pt;
      }
      
    }
    
    return pt_proche;
  }
  
};

//Fonction template permettant la surcharge de l'opérateur <<
template<typename T>
//Fonction permettant l'affichage de la fonction définie par la courbe de Bézier
std::ostream& operator<< (std::ostream& flux, bezier<T> const & b){  
  //Envoi de la chaine de caractère dans le flux d'affichage
  flux << "(1-s)^3*" << std::setprecision(3) << b.coeff(0) << "+3s(1-s)^2*" << std::setprecision(3) << b.coeff(1) << "+3s^2(1-s)*" << std::setprecision(3) << b.coeff(2) << "s^3*" << std::setprecision(3) << b.coeff(3);
  return flux;
};

#endif
