
#include "vec2.hpp"
#include <iostream>
#include "circle.hpp"
#include "bezier.hpp"
using std::cout;
using std::endl;

int main()
{
    circle cercle(vec2(1.0f,2.0f), 3.0f);
    bezier<vec2> b;
    //Test si le cercle est bien cree
    int N = 10;
    for(int i = 0; i < N ; i++){
      //s : le parametre de la courbe de bézier
      float s = i/float(N-1);
     
      //Calcul du point de la courbe de bézier
      vec2 pt = cercle(s); 
      std::cout << s << " : " << pt << std::endl;
    }
    
    //Test si la fonction closest_point de la classe circle fonctionne bien
    vec2 point = cercle.closest_point(vec2(1.0f, 5.0f));
    std::cout << point << std::endl;
    
    
    //Verification du polymorphisme
    geometrical_object* c1 = &cercle;
    geometrical_object* b1 = &b;
    circle* c2 = &cercle;
    bezier<vec2>* b2 = &b;
    std::cout << c1 << " " << b1 << "\n" << c2 << " " << b2 << std::endl;
    
    
    return 0;
}


