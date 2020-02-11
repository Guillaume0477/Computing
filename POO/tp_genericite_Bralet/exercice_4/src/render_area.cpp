
#include "render_area.hpp"

#include "bezier_drawer.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QLabel>


#include <iostream>


/** Get the index of the closest point of the control polygon of the click
  *  if the distance is less than some threshold. Otherwise return -1.
  *
  * INPUT:
  *  - The Bezier curve with its control polygon.
  *  - The position of the click.
  * OUTPUT:
  *  - An index >=0 of the closest control point of the Bezier curve if the distance
  *     is less than some threshold.
  *  - -1 if there is no point of the control polygon close enough of the click.
*/
static int select_point(bezier<vec2> const& curve,vec2 const& click);


render_area::render_area(QWidget *parent)
    :QWidget(parent),curve(),selected_point(-1),click_previous()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    curve=bezier<vec2>(
    {150.0f,100.0f},
    {250.0f,300.0f},
    {450.0f,350.0f},
    {550.0f,180.0f});
}

render_area::~render_area()
{}



void render_area::paintEvent(QPaintEvent*)
{
    //Initialize painters
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    QBrush brush = painter.brush();
    brush.setColor(Qt::gray);
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);

    QPen pen;

    //draw the bezier curve
    pen.setWidth(2.0);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    draw(painter,curve);

    //draw the control polygon
    pen.setWidth(1.0);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    draw_control_polygon(painter,curve);

    //draw the control points
    pen.setWidth(5.0);
    for(int k=0;k<4;++k)
    {
        if(k==selected_point)
            pen.setColor(Qt::yellow);
        else
            pen.setColor(Qt::red);
        painter.setPen(pen);

        draw_control_point(painter,curve,k);
    }



}




void render_area::mouseMoveEvent(QMouseEvent *event)
{
    vec2 const click=vec2(event->x(),event->y());

    //translate the control point
    if(selected_point!=-1)
    {
        vec2 translation=click-click_previous;
        curve.coeff(selected_point) += translation;
    }
    click_previous=click;

    repaint();
}

void render_area::mousePressEvent(QMouseEvent *event)
{
    vec2 const click=vec2(event->x(),event->y());

    //select a control point
    selected_point=select_point(curve,click);

    click_previous=click;
    repaint();
}


static int select_point(bezier<vec2> const& curve,vec2 const& click)
{
    //the minimal distance to be considered as clicked
    float const threshold=25;

    float distance_min=-1.0f;
    int index_distance_min=-1;

    //get the minimal distance
    for(int k=0;k<4;++k)
    {
        vec2 const& point=curve.coeff(k);
        float const distance=norm(point-click);

        if(k==0 || distance<distance_min)
        {
            distance_min=distance;
            index_distance_min=k;
        }
    }

    if(distance_min<=threshold)
        return index_distance_min;
    else
        return -1;
}




