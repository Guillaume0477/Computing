#include "circle.hpp"
#include <cmath>
#include "geometrical_object.hpp"

//Constructeurs
circle::circle(vec2 centre, float rayon){
  c = centre;
  R = rayon;
}

//Methodes virtual de surcharge d'operateur permettant le calcul de la valeur d'un point en fonction d'une valeur passee en argument
vec2 circle::operator() (float s) const{
  //Le calcul du point issu de l'équation du cercle
  vec2 point = c + R*vec2(cos(2*M_PI*s), sin(2*M_PI*s));
  return point;
}

//Fonction permettant de retourner le point du cercle le plus proche d'un point passé en paramètre
vec2 circle::closest_point(const vec2& point) const{
    /*
     * Cette méthode consiste à trouver l'intersection entre le cercle et la droite reliant le centre du cercle et le point connu.
     * Pour se faire il suffit de normaliser le vecteur directeur de la droite entre le centre et le point pour obtenir le respect 
     * de la contrainte due à la droite.
     * Puis à multiplier celui ci par le rayon et à ajouter les coordonnées du centre du cercle pour obtenir le respect de la 
     * contrainte due au cercle
     */
    //Calcul du vecteur directeur en le centre du cercle et le point en question
  vec2 vecdir = point - c;
    //Normalisation du vecteur directeur
  vecdir = normalize(vecdir);
    //Multiplication du vecteur normalise par le rayon du cercle
  vecdir *= R;
    //Deplacement du vecteur sur le cercle
  vecdir += c;
  return vecdir;
}