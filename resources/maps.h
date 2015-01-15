/******************************************************************************
  A header file used to define the default map width & height, as well as a
  method used to print a whole map of the default size. In the future, this will
  also be the location of the methods used to randomly generate the map.
 ******************************************************************************/
#ifndef MAP_RESOURCES_H
#define MAP_RESOURCES_H
/******************************************************************************
 ******************************************************************************/
#include <stdlib.h> /* malloc(), exit() */
#include "display.h" /* ansi escape codes, character codes, Glyph */
#include "monsters.h" /* Monster */
/******************************************************************************
 ******************************************************************************/
#define MAP_WIDTH   45
#define MAP_HEIGHT  18
/******************************************************************************
  set of available user commands
 ******************************************************************************/
enum commands {
    MV_N='8', MV_E='6', MV_S='2', MV_W='4',
    MV_NW='7', MV_NE='9', MV_SW='1', MV_SE='3'
};
/******************************************************************************
  used to represent a specific tile on the map
 ******************************************************************************/
typedef struct {
    Glyph *glyph;
    Monster *monster;
} Tile;
/******************************************************************************
  allocate memory for and initialize the fields of a new Tile
 ******************************************************************************/
Tile *newTile(int symbol, char *style) {
    Tile *tile = (Tile*)malloc(sizeof(Tile));
    if (tile == NULL) {
        fprintf(stderr,
                "ERROR - failed to allocate Tile memory - TERMINATING...\n");
        exit(1);
    }

    tile->glyph = newGlyph(symbol, style);

    return tile;
}
/******************************************************************************
  prints the map provided
 ******************************************************************************/
void printMap(Tile *map[MAP_WIDTH][MAP_HEIGHT]) {
    Tile *current; /* used to interact with individual tiles */
    int x, y; /* used to iterate through the map */

    printf("\n");
    for (y = 0; y < MAP_HEIGHT; y++) {
        printf(" ");
        for (x = 0; x < MAP_WIDTH; x++) {
            current = map[x][y];
            if (current->monster != NULL) {
                /* colorless printing
                printf("%c", current->monster->glyph->symbol);*/

                /* colored printing */
                printf("%s%c",
                        current->monster->glyph->style,
                        current->monster->glyph->symbol);
            }
            else {
                /* colorless printing
                printf("%c", current->glyph->symbol);*/

                /* colored printing */
                printf("%s%c", current->glyph->style, current->glyph->symbol);
            }
        }
        printf("\n");
    }
    printf("\n");
}

#endif /* MAP_RESOURCES_H */
