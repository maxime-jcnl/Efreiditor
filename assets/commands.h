//
// Created by Maxime Jaconelli on 16/05/2023.
//

#ifndef PROJET_C_VMAC_COMMANDS_H
#define PROJET_C_VMAC_COMMANDS_H
#include "struct.h"
#include "function.h"


struct command {
    char name[50];
    int int_size;
    int int_params[10];
    int str_size;
    char* str_params[10];
};
typedef struct command Command;

Command* create_commande();
void add_str_param(Command* cmd, char* p);
void add_int_param(Command* cmd, int p);
void free_cmd(Command* cmd);
int read_exec_command(Command* cmd);
void read_from_stdin(Command* cmd);


#endif //PROJET_C_VMAC_COMMANDS_H