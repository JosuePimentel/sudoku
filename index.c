#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#define lin 9
#define col 9

void verMatriz(int game[][col], int *p, int Ai, int Af, int Bi, int Bf) {
    int z;
    for( z = 0 ; z < lin ; z++ ) {
        for( Ai ; Ai < Af; Ai++ ) {
            for( Bi ; Bi < Bf ; Bi++ ) {
                if(game[Ai][Bi] == z+1) *p++;
            }
        }
    }
}

int verLineCol(int game[][col], int index, int l, int c, int thereIs, int *over, int key) {
    int x,y;
    int complete = 0;
    int *p = &complete;
    for( x = 0 ; x < lin ; x++ ) {
        if(game[x][c] ==  index) thereIs++;
        for( y = 0 ; y < col ; y++ ) {
            if(game[l][y] ==  index) thereIs++;

            int a,b;
            if((l>=0 && l<=2) && (c>=0 && c<=2)) {
                for( a = 0 ; a <= 2 ; a++) {
                    for( b = 0 ; b <= 2 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 0, 2, 0, 2);
                        if(complete && key) *over++;
                    }
                }
            } else if((l>=0 && l<=2) && (c>=3 && c<=5)) {
                for( a = 0 ; a <= 2 ; a++) {
                    for( b = 3 ; b <= 5 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 0, 2, 3, 5);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=0 && l<=2) && (c>=6 && c<=8)) {
                for( a = 0 ; a <= 2 ; a++) {
                    for( b = 6 ; b <= 8 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 0, 2, 6, 8);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=3 && l<=5) && (c>=0 && c<=2)) {
                for( a = 3 ; a <= 5 ; a++) {
                    for( b = 0 ; b <= 2 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 3, 5, 0, 2);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=3 && l<=5) && (c>=3 && c<=5)) {
                for( a = 3 ; a <= 5 ; a++) {
                    for( b = 3 ; b <= 5 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 3, 5, 3, 5);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=3 && l<=5) && (c>=6 && c<=8)) {
                for( a = 3 ; a <= 5 ; a++) {
                    for( b = 6 ; b <= 8 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 3, 5, 6, 8);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=6 && l<=8) && (c>=0 && c<=2)) {
                for( a = 6 ; a <= 8 ; a++) {
                    for( b = 0 ; b <= 2 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 6, 8, 0, 2);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=6 && l<=8) && (c>=3 && c<=5)) {
                for( a = 6 ; a <= 8 ; a++) {
                    for( b = 3 ; b <= 5 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 6, 8, 3, 5);
                        if(complete >= 9 && key) *over++;
                    }
                }
            } else if((l>=6 && l<=8) && (c>=6 && c<=8)) {
                for( a = 6 ; a <= 8 ; a++) {
                    for( b = 6 ; b <= 8 ; b++ ) {
                        if(game[a][b] == index) thereIs++;
                        verMatriz(game, p, 6, 8, 6, 8);
                        if(complete >= 9 && key) *over++;
                    }
                }
            }
        }
    }
    return thereIs;
}

void preencherJogo(int game[][col], int index, int l, int c, int *over) {
    int x,y;
    int thereIs = 0;
    thereIs = verLineCol(game, index, l, c, thereIs, over, 1);
    for( x = 0 ; x < lin ; x++ ) {
        for( y = 0 ; y < col ; y++ ) {
            if(index == -1) game[x][y] = 0;
            else if(!thereIs) game[l][c] = index;
        }
    }
    thereIs = 0;
}

void numAleatorios(int game[][col], int *over) {
    int count = 30;
    while(count) {
        int  thereIs = 0;
        srand(time(NULL));

        int nb = round(rand() % 10);
        int l = round(rand() % 9);
        int c = round(rand() % 9);

        thereIs = verLineCol(game, nb, l, c, thereIs, over, 0);
        if(!thereIs && game[l][c] == 0 && nb != 0) {
            preencherJogo(game, nb, l, c, over);
            count--;
        }
    }
}

void escreverJogo(int game[][col]) {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else 
        system("clear");
    #endif

    printf("  Escreva nessa ordem:\n Numero no intervalo[1;9]; Linha da casa ; Coluna da casa \n\n");

    int x,y;
    for( x = 0 ; x < lin ; x++ ) {
        for( y = 0 ; y < col ; y++ ) {
            printf("  %i  ", game[x][y]);
            if((y+1)%3==0 && y != 8) {
                printf("\033[34m | \033[0m");
            }
        }
        printf("\n");
        if((x+1)%3==0 && x != 8) {
            for( y = 0 ; y < col ; y++ ) {
                printf("\033[34m------\033[0m");
            }
        }
        printf("\n");
    }
}

int main(){

    int game[lin][col], over = 0, *p = &over;
    preencherJogo(game,-1,0,0,p);
    numAleatorios(game,p);
    escreverJogo(game);

    int nb, linha, coluna;

    while(!over) {
        printf("Escreva o proximo passo:");
        scanf("%i %i %i", &nb, &linha, &coluna);
        if((nb >= 1 && nb <= 9) && (linha >= 0 && linha <= 8) && (coluna >= 0 && coluna <= 8)) {
            preencherJogo(game, nb, linha, coluna, p);
            escreverJogo(game);
        } else {
            printf("Algum passo foi escrito fora do intervalo, rescreva!\n");
        }

        printf("%i", over);
    }


    return 0;

}