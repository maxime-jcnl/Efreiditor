//
// Created by Maxime Jaconelli on 08/05/2023.
//
#include <stdlib.h>
#include "pixel.h"
#include "area.h"
#include "struct.h"

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



void pixel_point(Shape* shape, Pixel** pixel_tab, int* nb_pixels)
{
    Point* pt    = (Point*) shape->ptrShape;
    pixel_tab    = (Pixel**) malloc (sizeof (Pixel*));
    pixel_tab[0] = create_pixel(pt->pos_x, pt->pos_y);
    *nb_pixels   = 1;
}