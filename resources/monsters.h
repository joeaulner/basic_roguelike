
#ifndef MONSTER_RESOURCES_H
#define MONSTER_RESOURCES_H

#include "display.h"

/* used to represent the characteristics of a monster */
typedef struct {
    Glyph *glyph;
    int x;
    int y;
} Monster;

/* allocate memory for and initialize the fields of a new Monster */
Monster *newMonster(int symbol, char *style, int x, int y) {
    Monster *monster = (Monster*)malloc(sizeof(Monster));
    if (monster == NULL) {
    fprintf(stderr, "ERROR - failed to allocate Monster memory - Terminating...\n");
    exit(1);
    }

    monster->glyph = newGlyph(symbol, style);
    monster->x = x;
    monster->y = y;

    return monster;
}

Monster *newPlayer(int x, int y) {
    Monster *player = newMonster(PLAYER, INTENSE F_GREEN, x, y);
    return player;
}

Monster *newFungus(int x, int y) {
    Monster *fungus = newMonster(FUNGUS, NORMAL F_GREEN, x, y);
    return fungus;
}

#endif /* MONSTER_RESOURCES_H */
