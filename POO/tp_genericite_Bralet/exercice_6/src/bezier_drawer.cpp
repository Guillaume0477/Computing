#include "bezier_drawer.hpp"

#include <QPainter>

void draw(QPainter& painter,bezier<vec2> const& curve)
{
    int const N_sample=200;
    for(int k=1;k<N_sample;++k)
    {
        float const s0=static_cast<float>(k-1)/(N_sample-1);
        float const s1=static_cast<float>(k)/(N_sample-1);

        vec2 p0=curve(s0);
        vec2 p1=curve(s1);

        painter.drawLine(p0.x,p0.y,
                         p1.x,p1.y);
    }
}

void draw_control_polygon(QPainter& painter,bezier<vec2> const& curve)
{
    for(int k=1;k<4;++k)
    {
        vec2 const& p0=curve.coeff(k-1);
        vec2 const& p1=curve.coeff(k);
        painter.drawLine(p0.x,p0.y,
                         p1.x,p1.y);
    }
}

void draw_control_point(QPainter& painter,bezier<vec2> const& curve,int const index)
{
    vec2 const& p=curve.coeff(index);
    painter.drawPoint(p.x,p.y);
}

