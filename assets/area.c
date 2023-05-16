//
// Created by Maxime on 24/04/2023.
//
#include "struct.h"
#include "area.h"
#include "pixel.h"
#include <stdlib.h>
#include <stdio.h>
Area* create_area(unsigned int width, unsigned int height){
    Area* a=(Area*) malloc(sizeof(Area));
    a->width=width;
    a->height=height;
    a->mat = (BOOL**)malloc(height * sizeof(BOOL*));
    for (int i = 0; i < a->height; i++) {
        a->mat[i] = (BOOL*)calloc(width, sizeof(BOOL));
    }
    a->nb_shape = 0;
    for(int i = 0; i < SHAPE_MAX; i++) {
        a->shapes[i] = NULL;
    }
    return a;
}
void clear_area(Area* area){
    for(int i=0; i<area->height;i++) {
        for (int j = 0; j < area->width; j++) {
            area->mat[i][j] = 0;
        }
    }
}
void print_area(Area* area){
    for(int i=0; i<area->height;i++){
        printf("\n");
        for(int j= 0; j<area->width;j++){
            if(area->mat[i][j]==0){
                printf(". ");
            } else {
                printf("# ");
            }
        }
    }
}
void add_shape_to_area(Area* area,Shape* shape){
    area->shapes[area->nb_shape]=shape;
    area->nb_shape++;
}
void erase_area(Area* area){
    for(int i=0;i<area->nb_shape;i++){
        Shape* shp = area->shapes[i];
        delete_shape(shp);
        area->shapes[i]=NULL;
    }
}
void delete_area(Area* area){
    erase_area(area);
    free(area);
    area=NULL;
}
void draw_area(Area* area) {
    int nb_pixel=0;
    int draw_x=0;
    int draw_y=0;

    Pixel **draw_tab = NULL;
    for (int i = 0; i < area->nb_shape; i++) {
        draw_tab = create_shape_to_pixel(area->shapes[i], &nb_pixel);
        for(int j = 0; j<nb_pixel;j++){
            draw_x=draw_tab[j]->px;
            draw_y=draw_tab[j]->py;
            if(draw_x<area->height && draw_y<area->width){
                area->mat[draw_y][draw_x]=1;
            }
        }
    }
}