#pragma once

#ifndef IMAGE_HPP
#define IMAGE_HPP

#include "color.hpp"

#include <vector>
#include <iostream>
#include <string>




struct image
{
    /** \brief La taille suivant x de l'image **/
    int Nx;
    /** \brief La taille suivant y de l'image **/
    int Ny;

    /** \brief Les donnees de l'image **/
    std::vector<color> data;

    /** Certifie que (x,y) soit bien contenu dans l'image
     *  \return rien, mais quitte si les coordonnee sont hors de l'image
     **/
    void assert_coord(int x,int y) const;

    /** \brief Operateur "get" pour des coordonnees (x,y) **/
    color const& operator()(int x,int y) const;

    /** \brief Operateur "get/set" pour des coordonnees (x,y) **/
    color& operator()(int x,int y);

    /** \brief Redimentionne l'image a une nouvelle taille
      * Les parametres (Nx,Ny) sont remis a jour, et le vecteur
      * de donnees est redimensionne (mais il n'efface pas les donnees
      * precedente).
      **/
    void resize(int Nx_arg,int Ny_arg);


};


image from_ppm(const std::string& filename);

void to_ppm(const std::string& filename);

#endif
