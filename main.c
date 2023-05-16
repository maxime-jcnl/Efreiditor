#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./assets/function.h"
#include "./assets/struct.h"
#include "./assets/id.h"
#include "./assets/area.h"
#include "./assets/pixel.h"


int main() {
    // terminal
    char instruction[15];
    char target[15];
    int quit = 0;
    int counter = 0;
    Pixel** pixel_tab = NULL;


    Area *area = create_area(50,50);
    clear_area(area);

    while(quit==0){
        system("clear");
        print_area(area);

        // Boucle infinie pour garder le terminal ouvert
        printf("\n---> ");  // Symbole d'attente d'entrée de l'utilisateur
        scanf("%s", instruction);
        if(strcmp(instruction,"add")==0){ // "strcmp" permet de comparer deux chaines de caractère
            // Choix de la forme :
            scanf("%s", target);
            if(strcmp(target,"point")==0){ // Si Point
                int x,y;
                scanf("%d %d", &x,&y);
                Shape * shp = create_point_shape(x,y);
                add_shape_to_area(area,shp);
            }
            else if(strcmp(target,"line")==0){ //
                int x1,y1,x2,y2;
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                Shape *shp = create_line_shape(x1,y1,x2,y2);
                add_shape_to_area(area,shp);
            }
            else if(strcmp(target,"square")==0){
                int x,y,l;
                scanf("%d %d %d",&x,&y,&l);

                Shape *shp = create_square_shape(x,y,l);
                add_shape_to_area(area,shp);
            }
            else if(strcmp(target,"rectangle")==0){
                int x,y,w,h;
                scanf("%d %d %d %d",&x,&y,&w,&h);
                /*Point *p= create_point(x,y);
                Rectangle *r= create_rectangle(p,w,h);
                print_rectangle(r);*/
                Shape *shp = create_rectangle_shape(x,y,w,h);
                add_shape_to_area(area,shp);

            }
            else if(strcmp(target,"circle")==0){
                int x,y,r;
                scanf("%d %d %d",&x,&y,&r);
                /*Point *p= create_point(x,y);
                Circle *c = create_circle(p,r);
                print_circle(c);*/
                Shape *shp = create_circle_shape(x,y,r);
                add_shape_to_area(area,shp);
            }
            else if(strcmp(target,"poly")==0){
                int n;
                scanf("%d",&n);
                /*Polygon *p= create_polygon(n);
                print_polygon(p);*/
                Shape *shp = create_polygon_shape(n);
                add_shape_to_area(area,shp);
            }
            else{
                printf("Forme inconnue, veuillez réessayez\n");
            }
        }
        else if(strcmp(instruction,"help")==0){
            print_help();
        }
        else if(strcmp(instruction,"quit")==0){
            quit =1;
        }
        else if(strcmp(instruction,"erase")==0){
            erase_area(area);

        }
        else if(strcmp(instruction,"delete")==0){
            delete_area(area);
        }
        else if(strcmp(instruction,"draw")==0){
            draw_area(area);
        }
    }
}
