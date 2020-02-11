#include "vec2.hpp"

#include "bezier.hpp"

#include "export_matlab.hpp"

#include <iostream>

int main()
{

    bezier<vec2,5> b(std::array<vec2,6>{vec2(0,0),vec2(1,1),vec2(2,1),vec2(1,0), vec2(2,-1), vec2(3,0)});
    export_matlab("data.m",b);

    return 0;
}

















