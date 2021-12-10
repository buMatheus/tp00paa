#include "includes/colors.h"

/*
Código de cada cor
Black -> \033[0;30m
Red -> \033[0;31m
Green -> \033[0;32m
Yellow -> \033[0;33m
Blue -> \033[0;34m
Purple -> \033[0;35m
Cyan -> \033[0;36m
White -> \033[0;37m
*/

void black () {
    printf("\033[0;30m");
}

void red () {
    printf("\033[1;31m");
}

void green() {
    printf("\033[0;32m");
}

void yellow () {
    printf("\033[1;33m");
}

void blue() {
    printf("\033[0;34m");
}

void purple() {
    printf("\033[0;35m");
}

void cyan() {
    printf("\033[0;36m");
}

void white() {
    printf("\033[0;37m");
}

// Necessário resetar para cor original
void reset () {
    printf("\033[0m"); 
}