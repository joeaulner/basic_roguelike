/*****************************************************************************
 * A header file containing the functions needed to generate a map.
******************************************************************************/
#ifndef GEN_MAP_H
#define GEN_MAP_H
/*****************************************************************************
 *****************************************************************************/
#include <time.h>
#include "displayChars.h" /* fillChars, wallChars */
#include "monsters.h" /* Monster, new<Monster> functions */
/*****************************************************************************
 * Default map width and height
 *****************************************************************************/
#define MAP_W   90
#define MAP_H   36
/*****************************************************************************
 * Initialize the map with all empty tiles
 *****************************************************************************/
void initMap(int tiles[MAP_W][MAP_H], short passable[MAP_W][MAP_H],
        Monster *monsters[MAP_W][MAP_H]) {
    int x, y; /* store coordinates on the map */

    /* fill the entire map with empty tiles */
    for (y = 0; y < MAP_H; y++) {
        for (x = 0; x < MAP_W; x++) {
            tiles[x][y] = EMPTY;
            passable[x][y] = 0;
            monsters[x][y] = NULL;
        }
    }
}
/*****************************************************************************
 * Map generation using random room sizing and placement
 *****************************************************************************/
void generate(int tiles[MAP_W][MAP_H], short passable[MAP_W][MAP_H],
        Monster *monsters[MAP_W][MAP_H]) {
    int x, y; /* store coordinates on the map */
    int rx, ry; /* coordinates for the center of a new room */
    int rw, rh; /* dimensions of a new room */
    short coll; /* whether a collision with an existing room has occurred */
    int rCount; /* the number of rooms already generated */

    initMap(tiles, passable, monsters); /* create an empty map */

    srand(time(NULL)); /* initialize the random number generator */
    rCount = 0;

    /* generate 15 new rooms */
    while (rCount < 15) {
        /* generate a new room */
        do {
            do {
                /* generate a random center of a new room */
                rx = rand() % MAP_W;
                ry = rand() % MAP_H;
                do {
                    /* generate random dimensions of a new room */
                    rw = rand() % 23 + 1;
                    rh = rand() % 9 + 1;
                } while (rw % 2 != 0 || rh % 2 != 0 || rw < 5 || rh < 3);
            } while (rx - rw/2 <= 0 || rx + rw/2 >= MAP_W-1 ||
                     ry - rh/2 <= 0 || ry + rh/2 >= MAP_H-1);

            coll = 0; /* assume no collisions */

            /* make sure the room does not collide with another room */
            for (y = ry-rh/2-3; y < ry+rh/2+3; y++) {
                /* cease checking when a collision is found */
                if (coll) {
                    break;
                }
                for (x = rx-rw/2-2; x < rx+rw/2+2; x++) {
                    if (tiles[x][y] == EMPTY) {
                        ;
                    } else {
                        coll = 1;
                        break;
                    }
                }
            }

            /* start over if a collision was detected */
            if (coll == 1) {
                continue;
            }

            /* set the inner tiles to floors */
            for (y = ry-rh/2+1; y < ry+rh/2; y++) {
                for (x = rx-rw/2+1; x < rx+rw/2; x++) {
                    tiles[x][y] = FLOOR;
                }
            }

            /* set the outer tiles to walls */
            for (x = rx-rw/2+1; x < rx+rw/2; x++) {
                tiles[x][ry-rh/2] = HORZ;
                tiles[x][ry+rh/2] = HORZ;
            }
            for (y = ry-rh/2+1; y < ry+rh/2; y++) {
                tiles[rx-rw/2][y] = VERT;
                tiles[rx+rw/2][y] = VERT;
            }
            tiles[rx-rw/2][ry-rh/2] = CNR_NW;
            tiles[rx+rw/2][ry-rh/2] = CNR_NE;
            tiles[rx+rw/2][ry+rh/2] = CNR_SE;
            tiles[rx-rw/2][ry+rh/2] = CNR_SW;

            rCount++;
        } while (coll == 1);
    }
}

#endif /* GEN_MAP_H */

