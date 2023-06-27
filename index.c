#include <stdio.h>
#include <stdlib.h>
#define lin 9
#define col 9

int verLineCol(int game[][col], int index, int l, int c, int thereIs) {
    int x,y;
    for( x = 0 ; x < lin ; x++ ) {
        if(game[x][c] ==  index) thereIs++;
        for( y = 0 ; y < col ; y++ ) {
            if(game[l][y] ==  index) thereIs++;

            if((l>=0 && l<=2) && (c>=0 && c<=2) && game[x][y] == index) {
                thereIs++;
            } else if((l>=0 && l<=2) && (c>=3 && c<=5) && game[x][y] == index) {
                thereIs++;
            } else if((l>=0 && l<=2) && (c>=6 && c<=8) && game[x][y] == index) {
                thereIs++;
            } else if((l>=3 && l<=5) && (c>=0 && c<=2) && game[x][y] == index) {
                thereIs++;
            } else if((l>=3 && l<=5) && (c>=3 && c<=5) && game[x][y] == index) {
                thereIs++;
            } else if((l>=3 && l<=5) && (c>=6 && c<=8) && game[x][y] == index) {
                thereIs++;
            } else if((l>=6 && l<=8) && (c>=0 && c<=2) && game[x][y] == index) {
                thereIs++;
            } else if((l>=6 && l<=8) && (c>=3 && c<=5) && game[x][y] == index) {
                thereIs++;
            } else if((l>=6 && l<=8) && (c>=6 && c<=8) && game[x][y] == index) {
                thereIs++;
            }
        }
    }

    return thereIs;
}

void preencherJogo(int game[][col], int index, int l, int c) {
    int x,y;
    int thereIs = 0;
    thereIs = verLineCol(game, index, l, c, thereIs);
    for( x = 0 ; x < lin ; x++ ) {
        for( y = 0 ; y < col ; y++ ) {
            if(index == -1) game[x][y] = 0;
            else if(l == x && c == y && !thereIs) game[x][y] = index;
        }
    }
    thereIs = 0;
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

    int game[lin][col];
    preencherJogo(game,-1,0,0);
    escreverJogo(game);

    int nb, linha, coluna;

    while(1) {
        printf("Escreva o proximo passo:");
        scanf("%i %i %i", &nb, &linha, &coluna);
        if((nb >= 1 && nb <= 9) && (linha >= 0 && linha <= 8) && (coluna >= 0 && coluna <= 8)) {
            preencherJogo(game, nb, linha, coluna);
            escreverJogo(game);
        } else {
            printf("Algum passo foi escrito fora do intervalo, rescreva!\n");
        }
    }


    return 0;

}