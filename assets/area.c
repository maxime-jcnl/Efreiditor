//
// Created by Maxime on 24/04/2023.
//
#include "struct.h"
#include "area.h"
#include <stdlib.h>
#include <stdio.h>
Area* create_area(unsigned int width, unsigned int height){
    Area* a=(Area*) malloc(sizeof(Area));
    a->width=width;
    a->height=height;
    a->mat = (BOOL**)malloc(height * sizeof(BOOL*));
    for (int i = 0; i < a->height; i++) {
        a->mat[i] = (BOOL**)calloc(width, sizeof(BOOL*));
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
        for(int j= 0; j<area->width;j++){
            if(area->mat[i][j]==0){
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
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
