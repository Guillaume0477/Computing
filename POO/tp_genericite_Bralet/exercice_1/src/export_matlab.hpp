#pragma once

#ifndef EXPORT_MATLAB_HPP
#define EXPORT_MATLAB_HPP

#include "bezier.hpp"
#include <string>


/** Given a bezier curve, export it in a readable format for Matlab */
void export_matlab(std::string const& filename,bezier const& b,int sample=100);


#endif
