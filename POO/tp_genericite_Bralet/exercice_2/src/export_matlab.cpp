
#include "export_matlab.hpp"


#include <iostream>
#include <exception>
#include <fstream>


void export_matlab(std::string const& filename,bezier<float> const& b,int const sample)
{
    //Check if the number of samples is correct
    if(sample<1 || sample>50000)
        throw std::exception();

    //write a file storing all the sampled points
    std::ofstream ofs;
    ofs.open(filename.c_str());

    if(ofs.good()==false)
        throw std::exception();

    //export the control polygon
    ofs<<"polygon=[";
    ofs<<"["<<0.0f   <<";" << b.coeff(0) << "],";
    ofs<<"["<<1.0f/3 <<";" << b.coeff(1) << "],";
    ofs<<"["<<2.0f/3 <<";" << b.coeff(2) << "],";
    ofs<<"["<<1.0f   <<";" << b.coeff(3) << "]";
    ofs<<"];"<<std::endl;

    ofs<<"curve=[";

    //export all the samples
    for(int k=0;k<sample;++k)
    {
        float const s = k/(sample-1.0f);
        float const y = b(s);

        ofs<<"["<<s<<";"<<y<<"]";
        
        if(k<sample-1)
            ofs<<",";
    }

    ofs<<"];";

    ofs.close();
}

