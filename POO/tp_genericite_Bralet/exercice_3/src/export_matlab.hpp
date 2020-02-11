#pragma once

#ifndef EXPORT_MATLAB_HPP
#define EXPORT_MATLAB_HPP

#include <string>
#include <iostream>
#include <fstream>

#include "bezier.hpp"

/** Export a scalar bezier curve into a Matlab compatible file */
void export_matlab(const std::string& filename,const bezier<float>& b,int sample=100);

/** Export a vectorial bezier curve into a Matlab compatible file */
template <typename T>
void export_matlab(const std::string& filename,const bezier<T>& b,int sample=100)
{
    if(sample<1 || sample>50000)
        throw std::exception();

    std::ofstream ofs;
    ofs.open(filename.c_str());

    if(ofs.good()==false)
        throw std::exception();

    ofs<<"polygon=["<<b.coeff(0)<<","<<b.coeff(1)<<","<<b.coeff(2)<<","<<b.coeff(3)<<"];"<<std::endl;

    ofs<<"curve=[";
    for(int k=0;k<sample;++k)
    {
        float const s = static_cast<float>(k)/(sample-1);
        T const y = b(s);

        ofs<<y;
        if(k<sample-1)
            ofs<<",";
    }
    ofs<<"];";

    ofs.close();
}



#endif
