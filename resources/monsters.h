/******************************************************************************
  A header file used to define what characteristics a Monster has, as well as
  provide methods for generating new monsters. At this point it is unknown
  whether different types of monsters will be represented with their own
  structs or if the one struct will be sufficient. The monster AI's may also be
  included in this file, but they could be stored in their own files as well.
 ******************************************************************************/
#ifndef MONSTERS_H
#define MONSTERS_H

#include <stdlib.h>
#include "displayChars.h"
/*****************************************************************************
   Used to represent the characteristics of a monster
 *****************************************************************************/
typedef struct {
    int glyph;
    int x;
    int y;
} Monster;
/******************************************************************************
   Allocate memory for and initialize the fields of a new Monster
 ******************************************************************************/
Monster *newMonster(int glyph, int x, int y) {
    Monster *monster = (Monster*)malloc(sizeof(Monster));
    if (monster == NULL) {
        fprintf(stderr, "ERROR - failed to allocate Monster memory - Terminating...\n");
        exit(1);
    }

    monster->glyph = glyph;
    monster->x = x;
    monster->y = y;

    return monster;
}
/******************************************************************************
  Call upon the newMonster function to generate a new player monster
 ******************************************************************************/
Monster *newPlayer(int x, int y) {
    Monster *player = newMonster(PLAYER, x, y);
    return player;
}
/******************************************************************************
  Call upon the newMonster function to generate a new fungus monster
 ******************************************************************************/
Monster *newFungus(int x, int y) {
    Monster *fungus = newMonster(FUNGUS, x, y);
    return fungus;
}

#endif /* MONSTERS_H */

