#pragma once

#ifndef RENDER_AREA_HPP
#define RENDER_AREA_HPP


#include <QWidget>
#include <QTimer>
#include <QTime>
#include <list>


#include "vec2.hpp"
#include "bezier.hpp"

//forward declaration of QLabel
class QLabel;



class render_area : public QWidget
{
    Q_OBJECT
public:

    render_area(QWidget *parent = 0);
    ~render_area();



protected:
    /** Actual drawing function */
    void paintEvent(QPaintEvent *event);

    /** Function called when the mouse is pressed */
    void mousePressEvent(QMouseEvent *event);
    /** Function called when the mouse is moved */
    void mouseMoveEvent(QMouseEvent *event);


private: //attributes

    /** The Bezier curve */
    bezier<vec2> curve;

    /** The selected vertex of the control polygon (-1 if none is selected) */
    int selected_point;

    /** The previously cliked position*/
    vec2 click_previous;


};

#endif
