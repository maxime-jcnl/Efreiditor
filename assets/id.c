//
// Created by Maxime on 23/04/2023.
//
unsigned int global_id = 0;
unsigned int get_next_id(){
    global_id++;
    return global_id-1;
}