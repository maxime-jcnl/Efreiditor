//
// Created by ameli on 21/04/2023.
//

#ifndef PROJET_C_VMAC_FUNCTION_H
#define PROJET_C_VMAC_FUNCTION_H
#include "struct.h"

//Point
Point *create_point(int px, int py);
void print_point(Point * p);
void delete_point(Point * p);

//Line
Line *create_line(Point * p1, Point * p2);
void delete_line(Line * line);
void print_line(Line * line);

//Square
Square *create_square(Point * point, int length);
void delete_square(Square * square);
void print_square(Square * square);

//Rectangle
Rectangle *create_rectangle(Point * point, int width, int height);
void delete_rectangle(Rectangle * rectangle);
void print_rectangle(Rectangle * rectangle);

//Circle
Circle *create_circle(Point * center, int circle_radius);
void delete_circle(Circle * circle);
void print_circle(Circle * circle);

//Polygon
Polygon *create_polygon(int n);
void delete_polygon(Polygon * polygon);
void print_polygon(Polygon * polygon);
#endif //PROJET_C_VMAC_FUNCTION_H

//Shape
Shape *create_empty_shape(SHAPE_TYPE shape_type);
Shape *create_point_shape(int px, int py);
Shape *create_line_shape(int px1, int py1, int px2, int py2);
Shape *create_square_shape(int px, int py, int length);
Shape *create_rectangle_shape(int px, int py, int width, int height);
Shape *create_circle_shape(int px, int py, int radius);
Shape *create_polygon_shape(int n);
void delete_shape(Shape * shape);
void print_shape(Shape * shape);


void print_help();