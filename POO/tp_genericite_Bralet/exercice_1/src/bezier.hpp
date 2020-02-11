
#ifndef BEZIER_HPP
#define BEZIER_HPP

#include <array>

//Classe permettant la simulation de courbe de Bézier
class bezier {
  //Coefficients de la courbe dans un array
  std::array<float,4> P;
  
public:
  //Constructeurs
  bezier() = default;   //Constructeur par défaut
  bezier(float p0, float p1, float p2, float p3);
  
  //Getters
  const float& coeff(int i) const {return P[i];}
  
  //Setters
  float& coeff(int i) {return P[i];}
  
  //Operateur permettant de calculer la valeur de la courbe de Bézier en un flottant
  float operator() (float f) const;
};

//Fonction permettant l'affichage de la fonction définie par la courbe de Bézier
std::ostream& operator<< (std::ostream& flux, bezier const & b);

#endif