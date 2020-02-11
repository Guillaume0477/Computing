#pragma once

#ifndef EXPORT_MATLAB_HPP
#define EXPORT_MATLAB_HPP

#include "bezier.hpp"
#include <string>
#include <iostream>
#include <fstream>

/** Given a bezier curve, export it in a readable format for Matlab **/
void export_matlab(std::string const& filename,bezier<float,3> const& b,int sample=100);

//Creation de la fonction template necessaire au bon fonctionnement du programme pour tout type de coefficient et d'ordre de bezier
template <typename T,int n>
void export_matlab(const std::string& filename,const bezier<T,n>& b,int sample=100)
{
    //Test si le nombre d'échantillon est suffisant ou si il y en a de trop
    if(sample<1 || sample>50000)
        throw std::exception();
    
    //Ouverture (creation) d'un fichier stockant les données
    std::ofstream ofs;
    ofs.open(filename.c_str());

    //Test si le fichier a bien été ouvert
    if(ofs.good()==false)
        throw std::exception();
    
    //Repertoire des points formant le polygone de controle de la courbe de bezier
    ofs<<"polygon=[";
    int indice = 0;
    //Parcours de tous les coefficients et ecriture dans le fichier
    while (indice != n+1){
        ofs<<b.coeff(indice)
        if (indice < n){
            <<",";
        }
        indice++;
    }
    ofs<< "];" << std::endl;
    
    //Calcul et écriture des points correspondants à la courbe de bézier
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
