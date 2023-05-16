//
// Created by Maxime Jaconelli on 08/05/2023.
//
#include <stdlib.h>
#include "pixel.h"
#include "area.h"
#include "struct.h"
#include <stdio.h>
Pixel* create_pixel(int px, int py){
    Pixel* pxl = (Pixel*)malloc(sizeof(Pixel));
    pxl->px=px;
    pxl->py=py;
    return pxl;
}
void delete_pixel(Pixel* pixel){
    free(pixel);
    pixel=NULL;
}



void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels){
    Point* pt    = (Point*) shape->ptrShape;
    *pixel_tab    = (Pixel**) malloc (1*sizeof (Pixel*));
    (*pixel_tab)[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels   = 1;
}

void pixel_line(Shape* shape, Pixel*** pixel_tab,int* nb_pixels){
    int dMin,dMax;

    Line* line = shape->ptrShape;
    Point* p1=line->p1;
    Point* p2=line->p2;

    if()

    int delta_x = abs( (p1->pos_x) - (p2->pos_x));
    int delta_y =  (p1->pos_y) - (p2->pos_y);

    if (delta_x>abs(delta_y)){
        dMax=delta_x;
        dMin=abs(delta_y);
    }else{
        dMax=abs(delta_y);
        dMin=delta_x;
    }
    int nb_segs = (dMin + 1);
    int taille_segs = (dMax + 1)/(dMin + 1);
    int *segments=(int*) malloc(nb_segs*sizeof (int));
    for(int i=0; i<nb_segs;i++){
        segments[i]=taille_segs;
    }
    int restants = (dMax+1)%(dMin+1);
    int *cumuls = (int *)malloc(nb_segs*sizeof(int));
    cumuls[0]=0;
    for (int i = 1; i < nb_segs;i++)
    {
        cumuls[i] = ((i+1)*restants)%(dMin+1) < ((i*restants)%(dMin+1));
        segments[i] = segments[i]+cumuls[i];
    }
    *(pixel_tab) = (Pixel**) malloc (nb_segs*sizeof (Pixel*));
    int px_x,px_y;
    px_x=p1->pos_x;
    px_y=p1->pos_y;
    int temp_i=0;
    if (delta_y < 0) {
        if (delta_x > abs(delta_y)) {
            for (int i = 0; i < nb_segs; i++) { // Parcours pour chaque segment
                for (int j = 0; j < segments[i]; j++) { // On parcourt autant de fois que la taille du segment
                    Shape * shp = create_point_shape(px_x,px_y);
                    Point* p = shp->ptrShape;
                    (*pixel_tab)[temp_i] = create_pixel(p->pos_x, p->pos_y);
                    (*nb_pixels)++;
                    px_x++;
                    temp_i++;
                }
                px_y--;
                }
        } else {
            for (int i = 0; i < nb_segs; i++) { // Parcours pour chaque segment
                for (int j = 0; j < segments[i]; j++) { // On parcourt autant de fois que la taille du segment
                    Shape * shp = create_point_shape(px_x,px_y);
                    Point* p = shp->ptrShape;
                    (*pixel_tab)[temp_i] = create_pixel(p->pos_x, p->pos_y);
                    (*nb_pixels)++;
                    px_y++;
                    temp_i++;
                }
                px_x--;
            }

        }
    } else {
        if (delta_x > abs(delta_y)){
            for(int i = 0;i<nb_segs;i++){
                for (int j = 0; j < segments[i]; j++){
                    Shape * shp = create_point_shape(px_x,px_y);
                    Point* p = shp->ptrShape;
                    (*pixel_tab)[temp_i] = create_pixel(p->pos_x, p->pos_y);
                    (*nb_pixels)++;
                    px_x++;
                    temp_i++;
                }
                px_y--;
            }
        } else {
            for (int i = 0; i < nb_segs; i++) { // Parcours pour chaque segment
                for (int j = 0; j < segments[i]; j++) { // On parcourt autant de fois que la taille du segment
                    Shape * shp = create_point_shape(px_x,px_y);
                    Point* p = shp->ptrShape;
                    (*pixel_tab)[temp_i] = create_pixel(p->pos_x, p->pos_y);
                    (*nb_pixels)++;
                    px_y++;
                    temp_i++;
                }
                px_x++;
            }
        }
    }
}

void pixel_circle(Shape* shape, Pixel*** pixel_tab, int *nb_pixels){
    Circle* cercle=shape->ptrShape;
    *(pixel_tab) = (Pixel**) malloc(1000*sizeof (Pixel*));
    int x=0;
    int y=cercle->r;
    int d=(cercle->r)-1;
    *nb_pixels=0;
    while(y>=x){
        // Premier octant
        Pixel* px = create_pixel(cercle->p->pos_x + x, cercle->p->pos_y + y);
        (*pixel_tab)[(*nb_pixels)++] = px;
        // Ajout du second octant
        px = create_pixel(cercle->p->pos_x + y, cercle->p->pos_y + x);
        (*pixel_tab)[(*nb_pixels)++] = px;       // Ainsi de suite...
        px = create_pixel(cercle->p->pos_x - x, cercle->p->pos_y + y);
        (*pixel_tab)[(*nb_pixels)++] = px;
        px = create_pixel(cercle->p->pos_x - y, cercle->p->pos_y + x);
        (*pixel_tab)[(*nb_pixels)++] = px;
        px = create_pixel(cercle->p->pos_x + x, cercle->p->pos_y - y);
        (*pixel_tab)[(*nb_pixels)++] = px;
        px = create_pixel(cercle->p->pos_x + y, cercle->p->pos_y - x);
        (*pixel_tab)[(*nb_pixels)++] = px;
        px = create_pixel(cercle->p->pos_x - x, cercle->p->pos_y - y);
        (*pixel_tab)[(*nb_pixels)++] = px;
        px = create_pixel(cercle->p->pos_x - y, cercle->p->pos_y - x);
        (*pixel_tab)[(*nb_pixels)++] = px;
        if (d>=2*x){
            d-=2*x+1;
            x++;
        }
        else if (d<2*(cercle->r-y)){
            d+=2*y-1;
            y--;
        } else {
            d+=2*(y-x-1);
            y--;
            x++;
        }
    }
}

void pixel_square(Shape* shape, Pixel*** pixel_tab, int* nb_pixels){
    Square* sqr = shape->ptrShape;
    *nb_pixels = (sqr->l)*sqr->l;
    *pixel_tab = (Pixel**) malloc (*nb_pixels*sizeof(Pixel*));
    int counter=0;
    int x = sqr->p->pos_x;
    int y = sqr->p->pos_y;

    for(int i=0; i<sqr->l; i++){
        for(int j=0;j<sqr->l;j++){

            if(i==0 || i==(sqr->l)-1){
            (*pixel_tab)[counter++]=create_pixel(x+j, (y+i));
            }
            else if (j==0){
                (*pixel_tab)[counter++]=create_pixel(x, (y+i));
            } else {
                (*pixel_tab)[counter++]=create_pixel(x+sqr->l-1, (y+i));
            }
        }
    }
}

// Fonction à vérifier avec le tracé
void pixel_rectangle(Shape* shape, Pixel*** pixel_tab, int* nb_pixels){
    Rectangle * rect = shape->ptrShape;
    *nb_pixels = (rect->w)*(rect->h);
    *pixel_tab = (Pixel**) malloc (*nb_pixels*sizeof(Pixel*));
    int counter=0;
    int x = rect->p->pos_x;
    int y = rect->p->pos_y;
    for(int i=0; i<rect->w; i++){
        for(int j=0;j<rect->h;j++){
            if(i==0 || i==(rect->w)-1){
                (*pixel_tab)[counter++]=create_pixel(x+j, (y+i));
            }
            else if (j==0){
                (*pixel_tab)[counter++]=create_pixel(x, (y+i));
            } else {
                (*pixel_tab)[counter++]=create_pixel(x+rect->h-1, (y+i));
            }
        }
    }
}
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels){
    Pixel** pixel_tab = NULL;
    *nb_pixels=0;
    if (shape->shape_type==POINT){
        pixel_point(shape,&pixel_tab,nb_pixels);
    }
    else if (shape->shape_type==LINE){
        pixel_line(shape,&pixel_tab,nb_pixels);
    }
    else if (shape->shape_type==SQUARE){
        pixel_square(shape,&pixel_tab,nb_pixels);
    }
    else if (shape->shape_type==RECTANGLE){
        pixel_rectangle(shape,&pixel_tab,nb_pixels);
    }
    else if (shape->shape_type==CIRCLE){
        pixel_circle(shape,&pixel_tab, nb_pixels);
    }
    else if (shape->shape_type==POLYGON){
        // a faire
        printf("EN COURS");
    }
    return pixel_tab;
}

