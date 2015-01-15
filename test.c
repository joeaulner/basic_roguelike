/******************************************************************************
   A basic implementation of the concepts that will be utilized in the rogulike
   I intend to construct from the reources located in the "recources"
   directory. This is a very rough testing environment, and will certainly need
   many modifications and much more polishing before it is ready for play.

   Intended to be compiled using the gcc compiler with the following flags:
        -Wall -ansi -std=c99
 ******************************************************************************/
#include <stdio.h> /* printf() */
#include "resources/display.h" /* ansi escape codes, character codes, Glyph */
#include "resources/monsters.h" /* Monster */
#include "resources/maps.h" /* Tile, map printing */
#include "resources/kbhit.h" /* kbhit(), getch() */
#include "resources/movement.h" /* various move methods */
/******************************************************************************
 ******************************************************************************/
int main() {
    Tile *map[MAP_WIDTH][MAP_HEIGHT]; /* stores a map of tiles */

    Monster *player; /* represents the player's current location */
    Monster *fungus; /* a fungus used to test a portion of movement */

    int x, y; /* stores coordinates on the map */
    int input; /* stores the user's next command */
    int updated; /* "boolean" representing whether the map has been updated */


    /* create a map of all floors */
    for (x = 0; x < MAP_WIDTH; x++) {
        for (y = 0; y < MAP_HEIGHT; y++) {
            map[x][y] = newTile(FLOOR, INTENSE F_WHITE B_BLACK);
        }
    }

    /* generate a new player monster at 0,0 */
    player = newPlayer(0, 0);
    map[player->x][player->y] -> monster = player;

    /* generate a new fungus monster at 5,7 */
    fungus = newFungus(5, 7);
    map[fungus->x][fungus->y] -> monster = fungus;

    /* print the map */
    system("clear");
    printMap(map);

    do {
        /* begin listening for user input */
        while (kbhit() == 0) {
            ;
        }
        input = getch();

        /* assume the user entered a valid command and the map was updated */
        updated = 1;

        switch (input) {
            /* If the user entered a move command,
               move the player in the appropriate direction. */
            case MV_N: moveNorth(player, map); break;
            case MV_E: moveEast(player, map); break;
            case MV_S: moveSouth(player, map); break;
            case MV_W: moveWest(player, map); break;
            case MV_NW: moveNorthwest(player, map); break;
            case MV_NE: moveNortheast(player, map); break;
            case MV_SW: moveSouthwest(player, map); break;
            case MV_SE: moveSoutheast(player, map); break;

            /* if the user entered an invalid command, the map is not updated */
            default: printf(RESET "You typed: %c\n\n", input);
                     updated = 0;
        }

        if (updated) {
            system("clear");
            printMap(map);
        }
    } while (input != 'x');

    return 0;
}
