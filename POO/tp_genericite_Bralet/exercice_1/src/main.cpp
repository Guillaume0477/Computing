
#include "bezier.hpp"

#include "export_matlab.hpp"

#include <iostream>

int main()
{
    //Call empty constructor
    bezier b0;
    //Build a bezier with control polygon given by [P0,P1,P2,P3]
    bezier const b1(0.0f,1.0f,1.1f,0.15f);

    float const P0 = b1.coeff(0); //get P0
    float const P1 = b1.coeff(1); //get P1
    
    std::cout<< P0 <<std::endl; //should print 0
    std::cout<< P1 <<std::endl; //should print 1

    //set Bezier coefficient for b0
    b0.coeff(0) = 0.0f;
    b0.coeff(1) = 0.4f;
    b0.coeff(2) = 0.6f;
    b0.coeff(3) = 0.2f;
    
    std::cout<< b0.coeff(0) <<std::endl; //should print 0
    std::cout<<  b0.coeff(1) <<std::endl;  // should print 0.4
    
    
    //Should print on the command line
    // (1-s)^3*0+3s(1-s)^2*1+3s^2(1-s)*1.1+s^3*0.15
    std::cout<< b1 <<std::endl;

    //Should print on the command line
    // (1-s)^3*0+3s(1-s)^2*0.4+3s^2(1-s)*0.6+s^3*0.2
    std::cout<< b0 <<std::endl;
    

    //Number of samples of the Bezier curve
    int const N_sample=10;
    for(int k=0; k<N_sample; ++k)
    {
        //s is the parameter of the Bezier curve
        // s spans the interval [0,1] with N_sample samples.
        float const s = k/(N_sample-1.0f);

        //Compute the value of the Bezier curve b1(s)
        float const value = b1(s);

        //Print all the values.
        // Check specificaly that
        //  value=P0 when s=0
        //  value=P3 when s=1
        std::cout<<k<<" : "<<value<<std::endl;
    }
    
    export_matlab("data.m",b1);
 
    return 0;
}

















