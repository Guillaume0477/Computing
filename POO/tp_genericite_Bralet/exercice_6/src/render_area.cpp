
#include "render_area.hpp"

#include "bezier_drawer.hpp"
#include "circle.hpp"

#include <QPainter>
#include <QMouseEvent>
#include <QLabel>


#include <iostream>




render_area::render_area(QWidget *parent)
    :QWidget(parent),objects(),point_sets(),closest_point(),mouse_point(),is_clicked()
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    init_fig();
}

render_area::~render_area()
{
    int const N=objects.size();
    for(int k=0;k<N;++k)
    {
        delete objects[k];
        objects[k]=nullptr;
    }
}


void render_area::init_fig()
{

    std::cout<<"Init geometric figures ..."<<std::endl;

    //create the circles
    circle* circle_0=new circle(vec2(600,300),60);
    circle* circle_1=new circle(vec2(200,20),20);
    circle* circle_2=new circle(vec2(120,350),30);

    objects.push_back(circle_0);
    objects.push_back(circle_1);
    objects.push_back(circle_2);

    //create the beziers
    bezier<vec2>* bezier_0=new bezier<vec2>(vec2(100,100),vec2(400,400),vec2(600,200),vec2(100,100));
    bezier<vec2>* bezier_1=new bezier<vec2>(vec2(100,150),vec2(120,300),vec2(550,320),vec2(600,120));
    bezier<vec2>* bezier_2=new bezier<vec2>(vec2(600,100),vec2(750,200),vec2(750,300),vec2(650,100));
    objects.push_back(bezier_0);
    objects.push_back(bezier_1);
    objects.push_back(bezier_2);

    //add all objects in generic container
    point_sets.resize(objects.size());
    int const N_object=objects.size();
    for(int k_obj=0;k_obj<N_object;++k_obj)
    {
        int const N_sample=250;
        point_sets[k_obj].resize(N_sample);
        geometrical_object const& current_object=*objects[k_obj];
        for(int k=0;k<N_sample;++k)
        {
            float const s=static_cast<float>(k)/(N_sample-1);
            point_sets[k_obj][k]=current_object(s);
        }
    }


    std::cout<<"Init OK"<<std::endl;

}


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

    pen.setWidth(1.0);
    pen.setColor(Qt::black);
    painter.setPen(pen);

    //draw all the objects
    int const N_objects=objects.size();
    for(int k_obj=0;k_obj<N_objects;++k_obj)
    {
        std::vector<vec2> const& current_curve=point_sets[k_obj];

        int const N_sample=current_curve.size();
        for(int k=1;k<N_sample;++k)
        {
            vec2 const& p0=current_curve[k-1];
            vec2 const& p1=current_curve[k];

            painter.drawLine(p0.x,p0.y,p1.x,p1.y);
        }
    }

    //draw the segment indicating the closest point
    pen.setWidth(1.0);
    pen.setColor(Qt::red);
    painter.setPen(pen);
    if(is_clicked==true)
    {
        painter.drawLine(mouse_point.x,mouse_point.y,
                         closest_point.x,closest_point.y);
    }


}




void render_area::mouseMoveEvent(QMouseEvent *event)
{
    mouse_point=vec2(event->x(),event->y());

    vec2 closest;
    float dist_closest=0.0f;

    //compute the closest point
    int const N_object=objects.size();
    for(int k_obj=0;k_obj<N_object;++k_obj)
    {
        geometrical_object const& current_object=*objects[k_obj];

        closest=current_object.closest_point(mouse_point);

        float const d=norm(closest-mouse_point);
        if(k_obj==0 || d<dist_closest)
        {
            dist_closest=d;
            closest_point=closest;
        }
    }

    repaint();
}

void render_area::mousePressEvent(QMouseEvent *)
{
    is_clicked=true;
    repaint();
}

void render_area::mouseReleaseEvent(QMouseEvent *)
{
    is_clicked=false;
    repaint();
}




