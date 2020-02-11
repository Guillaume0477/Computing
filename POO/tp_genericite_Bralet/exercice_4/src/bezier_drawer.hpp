
#pragma once

#ifndef BEZIER_DRAWER_HPP
#define BEZIER_DRAWER_HPP

#include "vec2.hpp"
#include "bezier.hpp"

class QPainter;



/** Draw on the QPainter the Bezier curve */
void draw(QPainter& painter,bezier<vec2> const& curve);

/** Draw on the QPainter the control polygon of the bezier as a set of segments */
void draw_control_polygon(QPainter& painter,bezier<vec2> const& curve);

/** Draw on the QPainter the vertex of the control polygon given by its index */
void draw_control_point(QPainter& painter,bezier<vec2> const& curve,int index);



#endif
