//
// Created by Maxime Jaconelli on 08/05/2023.
//

#ifndef PROJET_C_VMAC_PIXEL_H
#define PROJET_C_VMAC_PIXEL_H
#include "struct.h"
Pixel *create_pixel(int px, int py);
void delete_pixel(Pixel* pixel);
void pixel_point(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_line(Shape* shape, Pixel*** pixel,int* nb_pixels);
void pixel_circle(Shape* shape, Pixel*** pixel_tab, int* nb_pixels);
void pixel_square(Shape* square, Pixel*** pixel_tab, int* nb_pixels);
void pixel_rectangle(Shape* rectangle, Pixel*** pixel_tab, int* nb_pixels);
Pixel** create_shape_to_pixel(Shape * shape, int* nb_pixels);

#endif //PROJET_C_VMAC_PIXEL_H
