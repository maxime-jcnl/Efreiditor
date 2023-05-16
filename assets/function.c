//
// Created by ameli on 21/04/2023.

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>
#include "pixel.h"
#include "id.h"
// Point
Point *create_point(int px, int py){
    Point* p=(Point*)malloc(sizeof (Point));
    p->pos_x=px;
    p->pos_y=py;
    return p;
}
void print_point(Point * p){
    printf("\nPOINT %d %d", p->pos_x,p->pos_y);
}
void delete_point(Point * p){
    free(p);
    p=NULL;
}

// Line
Line *create_line(Point * p1, Point * p2){
    Line* l=(Line*)malloc(2*(sizeof(Line)));
    l->p1=p1;
    l->p2=p2;
    return l;
}
void print_line(Line * line){
    printf("\nLINE %d %d %d %d",line->p1->pos_x,line->p1->pos_y,line->p2->pos_x,line->p2->pos_y);
}
void delete_line(Line * line){
    free(line);
    line=NULL;
}

//Square
Square *create_square(Point * point, int length){
    Square* s=(Square*)malloc(sizeof(Square));
    s->p=point;
    s->l=length;
    return s;
}
void print_square(Square * square){
    printf("\nSQUARE %d %d %d",square->p->pos_x,square->p->pos_y,square->l);
}
void delete_square(Square * square){
    free(square);
    square=NULL;
}

//Rectangle
Rectangle *create_rectangle(Point * point, int width, int height){
    Rectangle *r=(Rectangle*) malloc(sizeof(Rectangle));
    r->p=point;
    r->w=width;
    r->h=height;
    return r;
}
void delete_rectangle(Rectangle * rectangle){
    free(rectangle);
    rectangle=NULL;
}
void print_rectangle(Rectangle * rectangle){
    printf("\nRECTANGLE %d %d %d %d",rectangle->p->pos_x,rectangle->p->pos_y,rectangle->w,rectangle->h);
}

//Circle
Circle *create_circle(Point * point, int circle_radius){
    Circle *c=(Circle*)malloc(sizeof(Circle));
    c->p=point;
    c->r=circle_radius;
    return c;
}
void print_circle(Circle * c){
    printf("\nCIRCLE %d %d %d",c->p->pos_x,c->p->pos_y,c->r);
}
void delete_circle(Circle * c){
    free(c);
    c=NULL;
}

//Polygon
Polygon *create_polygon(int n){
    Polygon *p = (Polygon*)malloc(sizeof(Polygon));
    p->n = n;
    p->points = (Point**)malloc(n * sizeof(Point*));
    int x, y;
    for(int i = 0; i < n; i++){
        scanf("%d %d", &x, &y);
        Point *point = create_point(x, y);
        p->points[i] = point;
    }

    if((p->points[0]->pos_x!=p->points[n-1]->pos_x) || (p->points[0]->pos_y!=p->points[n-1]->pos_y) ){
        printf("Erreur: Polygone non fermé\n");
        return 0;
    }

    return p;
}
void print_polygon(Polygon * p){
    printf("\nPOLYGON ");
    for(int i = 0; i<p->n;i++){
        printf("%d %d ",p->points[i]->pos_x,p->points[i]->pos_y);
    }
}
void delete_polygon(Polygon * p){
    free(p);
    p=NULL;
}

//Shape
Shape *create_empty_shape(SHAPE_TYPE shape_type) {
    Shape *shp = (Shape *) malloc(sizeof(Shape));
    shp->id = get_next_id(); // plus tard on appellera get_next_id();
    shp->shape_type = shape_type;
    return shp;
}
Shape *create_point_shape(int px, int py) {
    Shape *shp = create_empty_shape(POINT);
    shp->ptrShape = NULL;
    Point *p = create_point(px, py);
    shp->ptrShape = p;
    return shp;
}
Shape *create_line_shape(int px1, int py1, int px2, int py2){
    Shape *shp= create_empty_shape(LINE);
    Point *p1 = create_point(px1,py1);
    Point *p2 = create_point(px2,py2);
    Line *l = create_line(p1,p2);
    shp->ptrShape = l;
    return shp;
}
Shape *create_square_shape(int px, int py, int length){
    Shape *shp= create_empty_shape(SQUARE);
    Point *p = create_point(px, py);
    Square *s = create_square(p,length);
    shp->ptrShape= s;
    return shp;
}
Shape *create_rectangle_shape(int px, int py, int width, int height){
    Shape *shp = create_empty_shape(RECTANGLE);
    Point *p= create_point(px,py);
    Rectangle *r = create_rectangle(p,width,height);
    shp->ptrShape = r;
    return shp;
}
Shape *create_circle_shape(int px, int py, int radius){
    Shape *shp = create_empty_shape(CIRCLE);
    Point *p= create_point(px,py);
    Circle *c = create_circle(p,radius);
    shp->ptrShape = c;
    return shp;
}
Shape *create_polygon_shape(int n){
    Shape *shp = create_empty_shape(POLYGON);
    Polygon *p = create_polygon(n);
    shp->ptrShape = p;
    return shp;

}
void delete_shape(Shape * shape){
    free(shape);
    shape = NULL;
}
void print_shape(Shape * shape){
    printf("\n%d",shape->id);
    if(shape->shape_type==POINT){
        print_point(shape->ptrShape);
    }
    else if(shape->shape_type==SQUARE){
        print_square(shape->ptrShape);
    }
    else if(shape->shape_type==RECTANGLE){
        print_rectangle(shape->ptrShape);
    }
    else if(shape->shape_type==LINE){
        print_line(shape->ptrShape);
    }
    else if(shape->shape_type==CIRCLE){
        print_circle(shape->ptrShape);
    }
    else if(shape->shape_type==POLYGON){
        print_polygon(shape->ptrShape);
    }
}

void print_help(){
    printf("**************************************************\n");
    printf("****              VECT_IN_TEXT                ****\n");
    printf("**************************************************\n");
    printf("help : print this help\n");
    printf("============ Dessiner une forme ============\n");
    printf("add point x y : create point at position (x, x)\n");
    printf("add line x1 y1 x2 x2 : draw line from (x1, y1) to (x1, y1)\n");
    printf("add square x1 y1 l : draw square (x1, y1)  length\n");
    printf("add rectangle x1 y1 w h : draw rectangle (x1, y1)  width height\n");
    printf("add circle x y r : center at (x, y) radius r\n");
    printf("add poly n x1 y1 x2 y2 ... : draw polygon (n is the number of points)\n");
}