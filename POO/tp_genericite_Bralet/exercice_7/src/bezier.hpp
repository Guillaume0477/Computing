
#ifndef BEZIER_HPP
#define BEZIER_HPP
#include <iomanip>
#include <iostream>
#include <cmath>
#include <array>

//Expression constante permettant de calculer dès la compilation les différents k parmi n du programme
constexpr int kparmin(int k, int n){
    /*3 cas différents : n = k = 0 alors la valeur vaut 1 : condition d'arrêt
    *                    k < 0 ou k > n alors la valeur vaut 0 : condition d'arret
    *                    dans le cas contraire, le calcul des coefficients binomiaux vaut :
    *                               k parmi n = [(k-1) parmi (n-1)] + [k parmi (n-1)]
    * */
  return ((n == 0) && (k == 0)) ? 1 : ((k>n) || (k<0)) ? 0 : kparmin(k-1,n-1) + kparmin(k,n-1);
}


template <typename T, int n>
class bezier{
  //Coefficients de la courbe dans un vecteur
  std::array<T,n+1> P;
  
public:
  //Constructeurs
  bezier<T,n>() = default;
  bezier<T,n>(std::array<T,n+1> Points){P = Points;}
  
  //Getters
  const T& coeff(int i) const {return P[i];}
  
  //Setters
  T& coeff(int i) {return P[i];}
  
  T operator() (float f) const{
    int puissance = 0;
    T calcul;
    //Parcours de l'ensemble des coefficients et attribution de la puissance associé à chacun des facteurs s et 1-s
    while(puissance <= n){
        calcul += kparmin(puissance,n)*pow((1-f),n-puissance)*pow(f,puissance)*P[puissance];
        //Afffichage des différents coefficients binomiaux calcules pour verification
        //std::cout << puissance << " parmi " << n << " = " << kparmin(puissance,n) << std::endl;
        puissance++;
    }    
    return calcul;
  }
  
};

//Fonction template permettant de surcharger l'opérateur <<
template<typename T, int n>
//Fonction permettant l'affichage de la fonction définie par la courbe de Bézier
std::ostream& operator<< (std::ostream& flux, bezier<T,n> const & b){  
  //Envoi de la chaine de caractère dans le flux d'affichage
    int puissance = 0;
    //Parcours de toutes les puissances et affichage de la portion d'équation associée
    while (puissance <= n) {
        if (puissance == 0) {
            flux << "(1-s)^" << n << "*" << std::setprecision(3) << b.coeff(puissance) << " + ";
        } else if (puissance == n) {
            flux << "s^" << puissance << "*" << std::setprecision(3) << b.coeff(puissance);
        } else {
            flux << kparmin(puissance,n) << "s^" << puissance << "(1-s)^" << n-puissance << "*" << std::setprecision(3) << b.coeff(puissance) << " + ";
        }
        puissance++;
    }
    return flux;
};

#endif























