
#include "vec2.hpp"
#include "export_matlab.hpp"


#include <iostream>

using std::cout;
using std::endl;

int main()
{
    vec2 v0;
    vec2 v1(1.5f,2.0f);

    v0.x = 2.2f;
    v0.y = 4.3f;

    cout<< v0 <<endl; //Should print [2.2;4.3]

    v1 *= 0.5f;
    cout<< v1 <<endl; //Should print [0.75;1]

    const vec2 v2(1.3f,2.2f);
    vec2 v3 = 1.5f*v2*2.2f;
    cout<< v3 <<endl; //Should print [4.29;7.26]

    v3 = v2/0.5f;
    cout<< v3 <<endl; //Should print [2.6;4.4]

    v3 += vec2(0.5f,0.2f);
    cout<< v3 <<endl; //Should print [3.1;4.6]
    cout<< v2+vec2(0.5f,0.2f) <<endl; //Should print [1.8;2.4]

    v3 -= vec2(0.4f,0.5f);
    cout<< v3 <<endl; //doit afficher [2.7;4.1]
    cout<< v2-vec2(1.1f,0.4f) <<endl; //Should print [0.2;1.8]

    //Should print 1.80278
    std::cout<< norm(vec2(1.0f,1.5f)) <<std::endl;


    bezier<vec2> b(vec2(0,0),vec2(1,1),vec2(0,1.5),vec2(-1,0.5));
    export_matlab("data.m",b);

    return 0;
}
