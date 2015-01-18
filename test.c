/******************************************************************************
   A basic implementation of the concepts that will be utilized in the
   roguelike I intend to construct from the resources located in the
   "resources" directory. This is a very rough testing environment, and will
   certainly need many modifications and much more polishing before it is ready
   for any sort of play.

   Intended to be compiled using the gcc compiler with the following flags:
        -Wall -ansi -std=c99
 ******************************************************************************/
#include <stdio.h> /* printf() */
#include "resources/displayChars.h" /* character codes */
#include "resources/monsters.h" /* Monster */
#include "resources/kbhit.h" /* kbhit(), getch() */
/******************************************************************************
******************************************************************************/
#define MAP_WIDTH   45
#define MAP_HEIGHT  18
/******************************************************************************
 * set of available user commands
 ******************************************************************************/
enum commands {
    MV_N='8', MV_E='6', MV_S='2', MV_W='4',
    MV_NW='7', MV_NE='9', MV_SW='1', MV_SE='3'
};
/******************************************************************************
******************************************************************************/
void move(Monster *monster, int dir, Monster *monsters[MAP_WIDTH][MAP_HEIGHT]);
/******************************************************************************
 ******************************************************************************/
int main() {
    /* Let's try to use a different method to represent the map.
     * I will try to use multiple different arrays, one for tiles,
     * one for monsters, and one for items */
    int tiles[MAP_WIDTH][MAP_HEIGHT];
    Monster *monsters[MAP_WIDTH][MAP_HEIGHT];

    Monster *player; /* represents the player's current location */
    Monster *fungus; /* a fungus used to test a portion of movement */

    int x, y; /* stores coordinates on the map */
    char input; /* input character from the user */
    short term; /* terminates execution when true */
    short update; /* determine whether the map needs to be reprinted */


    /* generate a map of all floor tiles and no monsters */
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            tiles[x][y] = FLOOR;
            monsters[x][y] = NULL;
        }
    }

    /* initialize a couple monsters to add to the map */
    player = newPlayer(0, 0);
    monsters[0][0] = player;
    fungus = newFungus(10, 10);
    monsters[10][10] = fungus;

    /* clear the screen */
    system("clear");

    /* print the current map */
    for (y = 0; y < MAP_HEIGHT; y++) {
        printf("\n ");
        for (x = 0; x < MAP_WIDTH; x++) {
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
            /* movement commands */
            case MV_N:
            case MV_E:
            case MV_S:
            case MV_W:
            case MV_NW:
            case MV_NE:
            case MV_SE:
            case MV_SW:
                move(player, input, monsters);
                break;
            /* terminate execution */
            case 'x':
                term = 1;
                break;
            default:
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
            for (y = 0; y < MAP_HEIGHT; y++) {
                printf("\n ");
                for (x = 0; x < MAP_WIDTH; x++) {
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
void move(Monster *monster, int dir, Monster *monsters[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* Perform the move operation in the appropriate direction by first
     * checking that the destination is free and then moving the monster */
    switch (dir) {
        case MV_N:
            if (y-1 >= 0 && monsters[x][y-1] == NULL) {
                monster->y = y-1;;
                monsters[x][y-1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_E:
            if (x+1 < MAP_WIDTH && monsters[x+1][y] == NULL) {
                monster->x = x+1;;
                monsters[x+1][y] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_S:
            if (y+1 < MAP_HEIGHT && monsters[x][y+1] == NULL) {
                monster->y = y+1;;
                monsters[x][y+1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_W:
            if (x-1 >= 0 && monsters[x-1][y] == NULL) {
                monster->x = x-1;;
                monsters[x-1][y] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_NW:
            if (x-1 >= 0 && y-1 >= 0 && monsters[x-1][y-1] == NULL) {
                monster->x = x-1;;
                monster->y = y-1;;
                monsters[x-1][y-1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_NE:
            if (x+1 < MAP_WIDTH && y-1 >= 0 && monsters[x+1][y-1] == NULL) {
                monster->x = x+1;;
                monster->y = y-1;;
                monsters[x+1][y-1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_SE:
            if (x+1 < MAP_WIDTH && y+1 < MAP_HEIGHT && monsters[x+1][y+1] == NULL) {
                monster->x = x+1;;
                monster->y = y+1;;
                monsters[x+1][y+1] = monster;
                monsters[x][y] = NULL;
            }
            break;
        case MV_SW:
            if (x-1 >= 0 && y+1 < MAP_HEIGHT && monsters[x-1][y+1] == NULL) {
                monster->x = x-1;;
                monster->y = y+1;;
                monsters[x-1][y+1] = monster;
                monsters[x][y] = NULL;
            }
            break;
    }
}

