#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAP_SIZE 10
#define START_LIVES 3

void initMap(char map[MAP_SIZE][MAP_SIZE]);
void printMap(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY);
void movePlayer(char direction, int *playerX, int *playerY);
int hangmanChallenge();

int main() {
    char map[MAP_SIZE][MAP_SIZE];
    int playerX = 0, playerY = 0;  // Posición inicial del jugador
    int lives = START_LIVES;
    char direction;
    
    initMap(map);

    while (lives > 0) {
        system("clear");  // Usar "cls" en Windows
        printMap(map, playerX, playerY);
        printf("\nVidas: %d\n", lives);
        printf("Mover (w/a/s/d): ");
        scanf_s(" %c", &direction);

        movePlayer(direction, &playerX, &playerY);

        // Verificar si llegó al reto del ahorcado
        if (playerX == 4 && playerY == 4) {
            printf("\n¡Has encontrado el reto del ahorcado!\n");
            if (hangmanChallenge() == 1) {
                printf("¡Has superado el reto! Fin del juego.\n");
                break;
            } else {
                lives--;
                if (lives == 0) {
                    printf("Te has quedado sin vidas. Fin del juego.\n");
                }
            }
        }
    }
    
    return 0;
}

void initMap(char map[MAP_SIZE][MAP_SIZE]) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            map[i][j] = '-';
        }
    }
    map[4][4] = 'H';  // Posición del reto de ahorcado
}

void printMap(char map[MAP_SIZE][MAP_SIZE], int playerX, int playerY) {
    for (int i = 0; i < MAP_SIZE; i++) {
        for (int j = 0; j < MAP_SIZE; j++) {
            if (i == playerX && j == playerY) {
                printf("X ");
            } else {
                printf("%c ", map[i][j]);
            }
        }
        printf("\n");
    }
}

void movePlayer(char direction, int *playerX, int *playerY) {
    switch (direction) {
        case 'w': if (*playerX > 0) (*playerX)--; break;
        case 's': if (*playerX < MAP_SIZE - 1) (*playerX)++; break;
        case 'a': if (*playerY > 0) (*playerY)--; break;
        case 'd': if (*playerY < MAP_SIZE - 1) (*playerY)++; break;
        default: printf("Dirección no válida.\n"); break;
    }
}

int hangmanChallenge() {
    char word[] = "gato";  // La palabra a adivinar
    char guess[20];
    
    printf("Adivina la palabra de 4 letras: ");
    scanf_s("%s", guess);
    
    if (strcmp(guess, word) == 0) {
        printf("¡Correcto!\n");
        return 1;  // Desafío superado
    } else {
        printf("Incorrecto. Pierdes una vida.\n");
        return 0;  // Desafío fallado
    }
}
