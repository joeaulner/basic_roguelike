/******************************************************************************
   A basic implementation of the concepts that will be utilized in the
   roguelike I intend to construct from the resources located in the
   "resources" directory. This is a very rough testing environment, and will
   certainly need many modifications and much more polishing before it is ready
   for any sort of play.

   Intended to be compiled using the gcc compiler with the following flags:
        -Wall -ansi -std=c99
 *****************************************************************************/
#include <stdio.h> /* printf() */
#include "resources/monsters.h" /* Monster */
#include "resources/kbhit.h" /* kbhit(), getch() */
#include "resources/genMap.h" /* generate() */
/******************************************************************************
 * set of available user commands
 ******************************************************************************/
enum commands {
    MV_N='8', MV_E='6', MV_S='2', MV_W='4',
    MV_NW='7', MV_NE='9', MV_SW='1', MV_SE='3'
};
/*****************************************************************************
******************************************************************************/
void move(int dir, Monster *monster, Monster *monsters[MAP_W][MAP_H],
        short passable[MAP_W][MAP_H]);
/******************************************************************************
 ******************************************************************************/
int main() {
    /* Let's try to use a different method to represent the map.
     * I will try to use multiple different arrays, one for tiles,
     * one for monsters, and one for items */
    int tiles[MAP_W][MAP_H];
    short passable[MAP_W][MAP_H];
    Monster *monsters[MAP_W][MAP_H];

    Monster *player; /* represents the player's current location */
    Monster *fungus; /* a fungus used to test a portion of movement */

    int x, y; /* store coordinates on the map */
    char input; /* input character from the user */
    short term; /* terminates execution when true */
    short update; /* determine whether the map needs to be reprinted */


    /* generate a map of all floor tiles and no monsters 
    genFloors(tiles, passable, monsters);*/
    generate(tiles, passable, monsters);

    /* initialize a couple monsters to add to the map 
    player = newPlayer(0, 0);
    monsters[0][0] = player;
    fungus = newFungus(10, 10);
    monsters[10][10] = fungus;*/

    /* clear the screen */
    system("clear");

    /* print the current map */
    for (y = 0; y < MAP_H; y++) {
        printf("\n ");
        for (x = 0; x < MAP_W; x++) {
            /* display precedence: monster > tile */
            if (monsters[x][y] != NULL) {
                printf("%c", monsters[x][y] -> glyph);
            } else {
                printf("%c", tiles[x][y]);
            }
        }
    }
    printf("\n\n");

    /* listen for user input until an x is entered */
    while (kbhit() != -1) {
        input = getch();

        update = 1;

        /* execute the appropriate action for the command */
        switch (input) {
            /* movement commands from arrow keys */
            case 27:
                if (getch() == 91) {
                    input = getch();
                    switch (input) {
                        case 65: move(MV_N, player, monsters, passable); break;
                        case 66: move(MV_S, player, monsters, passable); break;
                        case 67: move(MV_E, player, monsters, passable); break;
                        case 68: move(MV_W, player, monsters, passable); break;
                    }
                }
                break;
            /* movement commands numpad */
            case MV_N:  case MV_E:
            case MV_S:  case MV_W:
            case MV_NW: case MV_NE:
            case MV_SE: case MV_SW:
                move(input, player, monsters, passable);
                break;
            /* terminate execution */
            case 'x':
                term = 1;
                break;
            /* no valid command entered */
            default:
                printf("You entered: %d\n", input);
                printf("You entered: %c\n\n", input);
                update = 0;
                break;
        }

        /* user terminated input */
        if (term == 1) {
            system("clear");
            break;
        }

        /* only reprint the map if it was updated */
        if (update == 1) {
            system("clear");

            /* print the current map */
            for (y = 0; y < MAP_H; y++) {
                printf("\n ");
                for (x = 0; x < MAP_W; x++) {
                    /* print the symbol of any monster on the tile */
                    if (monsters[x][y] != NULL) {
                        printf("%c", monsters[x][y] -> glyph);
                    } else {
                        printf("%c", tiles[x][y]);
                    }
                }
            }
            printf("\n\n");
        }
    }

    return 0;
}
/******************************************************************************
 * moves the provided monster to the specified direction on the provided map
 ******************************************************************************/
void move(int dir, Monster *monster, Monster *monsters[MAP_W][MAP_H],
        short passable[MAP_W][MAP_H]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* Perform the move operation in the appropriate direction by first
     * checking that the destination is free and then moving the monster */
    switch (dir) {
        case MV_N:
            if (y-1 >= 0 && passable[x][y-1] == 1 &&
                    monsters[x][y-1] == NULL) {
                monster->y = y-1;;
                monsters[x][y-1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_E:
            if (x+1 < MAP_W && passable[x+1][y] == 1 &&
                    monsters[x+1][y] == NULL) {
                monster->x = x+1;;
                monsters[x+1][y] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_S:
            if (y+1 < MAP_H && passable[x][y+1] == 1 &&
                    monsters[x][y+1] == NULL) {
                monster->y = y+1;;
                monsters[x][y+1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_W:
            if (x-1 >= 0 && passable[x-1][y] == 1 &&
                    monsters[x-1][y] == NULL) {
                monster->x = x-1;;
                monsters[x-1][y] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_NW:
            if (x-1 >= 0 && y-1 >= 0 && passable[x-1][y-1] == 1 &&
                    monsters[x-1][y-1] == NULL) {
                monster->x = x-1;;
                monster->y = y-1;;
                monsters[x-1][y-1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_NE:
            if (x+1 < MAP_W && y-1 >= 0 && passable[x+1][y-1] == 1 &&
                    monsters[x+1][y-1] == NULL) {
                monster->x = x+1;;
                monster->y = y-1;;
                monsters[x+1][y-1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_SE:
            if (x+1 < MAP_W && y+1 < MAP_H && passable[x+1][y+1] == 1 &&
                    monsters[x+1][y+1] == NULL) {
                monster->x = x+1;;
                monster->y = y+1;;
                monsters[x+1][y+1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_SW:
            if (x-1 >= 0 && y+1 < MAP_H && passable[x-1][y+1] == 1 &&
                    monsters[x-1][y+1] == NULL) {
                monster->x = x-1;;
                monster->y = y+1;;
                monsters[x-1][y+1] = monster;
                monsters[x][y] = NULL;
            }
            break;
    }
}

