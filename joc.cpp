#include <stdio.h>


int main() {

    int posx = 0;
    int posy = 0;
    int vidas = 3;

    char map[10][10] = {
        {'X','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','R','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'},
        {'-','-','-','-','-','-','-','-','-','-'} 
        };


    printf("Tu objetivo es llegar a la R para cumplir el reto \n");


    do {

        for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++){

            printf("%c ", map[i][j]);

        }
        printf("\n");
    }

        map[posx][posy] = '-';
        int move;

        printf("Que posicion quieres ir?\n");
        printf("1 = Arriba, 2 = Abajo, 3 = Izquierda, 4 = Derecha\n");
        scanf_s("%d", &move);

        switch (move) {

            case 1:
                if (posx > 0) posx--;
                else printf("No puedes hacer eso, cara almendra");
                break;
            
            case 2:
                if (posx < 9) posx++;
                else printf("No puedes hacer eso, cara almendra");
                break;
            
            case 3: 
                if (posy > 0) posy--;
                else printf("No puedes hacer eso, cara almendra");
                break;

            case 4:
                if (posy < 9) posy++;
                else printf("No puedes hacer eso, cara almendra");
                break;

            default:
                printf("Porque pones un numero que no te pido?");
                break;
        }

        map[posx][posy] = 'X';


    } while (map[posx][posy] = map[4][4]);



}