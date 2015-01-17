/******************************************************************************
  A header file with methods used to move monsters in a map constructed of
  Tiles in one of 8 directions (the 4 cardinal directions and their diagonals).
 ******************************************************************************/
#include <stdio.h>
#include "maps.h"
/******************************************************************************
  moves the provided monster to the NORTH on the provided map
 ******************************************************************************/
void moveNorth(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the NORTH,
       and there is no monster there, then move them */
    if (y-1 >= 0 && map[x][y-1] -> monster == NULL) {
        monster->y = y-1;;
        map[x][y-1] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the EAST on the provided map
 ******************************************************************************/
void moveEast(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the EAST,
       and there is no monster there, then move them */
    if (x+1 < MAP_WIDTH && map[x+1][y] -> monster == NULL) {
        monster->x = x+1;
        map[x+1][y] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the SOUTH on the provided map
 ******************************************************************************/
void moveSouth(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the SOUTH,
       and there is no monster there, then move them */
    if (y+1 < MAP_HEIGHT && map[x][y+1] -> monster == NULL) {
        monster->y = y+1;
        map[x][y+1] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the WEST on the provided map
 ******************************************************************************/
void moveWest(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the WEST,
       and there is no monster there, then move them */
    if (x-1 >= 0 && map[x-1][y] -> monster == NULL) {
        monster->x = x-1;
        map[x-1][y] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the NORTHWEST on the provided map
 ******************************************************************************/
void moveNorthwest(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the NORTHWEST,
       and there is no monster there, then move them */
    if (x-1 >= 0 && y-1 >= 0 && map[x-1][y-1] -> monster == NULL) {
        monster->x = x-1;
        monster->y = y-1;
        map[x-1][y-1] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the NORTHEAST on the provided map
 ******************************************************************************/
void moveNortheast(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the NORTHEAST,
       and there is no monster there, then move them */
    if (x+1 < MAP_WIDTH && y-1 >= 0 && map[x+1][y-1] -> monster == NULL) {
        monster->x = x+1;
        monster->y = y-1;
        map[x+1][y-1] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the SOUTHWEST on the provided map
 ******************************************************************************/
void moveSouthwest(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the SOUTHWEST,
       and there is no monster there, then move them */
    if (x-1 >= 0 && y+1 < MAP_HEIGHT && map[x-1][y+1] -> monster == NULL) {
        monster->x = x-1;
        monster->y = y+1;
        map[x-1][y+1] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}
/******************************************************************************
  moves the provided monster to the SOUTHEAST on the provided map
 ******************************************************************************/
void moveSoutheast(Monster *monster, Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    /* get current location of the monster */
    int x = monster->x;
    int y = monster->y;

    /* make sure the player is able to move to the SOUTHEAST,
       and there is no monster there, then move them */
    if (x+1 < MAP_WIDTH && y+1 < MAP_HEIGHT && map[x+1][y+1] -> monster == NULL) {
        monster->x = x+1;
        monster->y = y+1;
        map[x+1][y+1] -> monster = monster;
        map[x][y] -> monster = NULL;
    }
}

