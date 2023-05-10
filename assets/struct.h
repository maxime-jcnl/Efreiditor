//
// Created by ameli on 21/04/2023.
//

#ifndef PROJET_C_STRUCT_H
#define PROJET_C_STRUCT_H

// Point
typedef struct {
    int pos_x;
    int pos_y;
}Point;

// Line
typedef struct {
    Point *p1;
    Point *p2;
}Line;

// Square
typedef struct {
    Point *p;
    int l;
}Square;

// Rectangle
typedef struct {
    Point *p;
    int w;
    int h;
}Rectangle;

// Circle
typedef struct {
    Point *p;
    int r;
}Circle;

// Polygon
typedef struct polygon {
    int n;
    Point ** points; // tableau 1D dynamique de Point*
}Polygon;

// Shape
typedef enum { POINT, LINE, SQUARE, RECTANGLE, CIRCLE, POLYGON} SHAPE_TYPE;
typedef struct shape {
    int id; // identifiant unique de la forme
    SHAPE_TYPE shape_type; // type de la forme pointé
    void *ptrShape; // pointeur sur n'importe quelle forme
}Shape;

struct pixel {
    int px;
    int py;
};
typedef struct pixel Pixel;
#endif //PROJET_C_STRUCT_H
