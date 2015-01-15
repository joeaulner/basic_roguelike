
#ifndef TILE_RESOURCES_H
#define TILE_RESOURCES_H

#include <string.h> /* strcpy() */
#include <stdlib.h> /* malloc(), exit() */

/* The following is a list of ansi escape codes
   used to change the foreground color of output */
#define F_BLACK     "\x1b[30m"
#define F_RED       "\x1b[31m"
#define F_GREEN     "\x1b[32m"
#define F_YELLOW    "\x1b[33m"
#define F_BLUE      "\x1b[34m"
#define F_MAGENTA   "\x1b[35m"
#define F_CYAN      "\x1b[36m"
#define F_WHITE     "\x1b[37m"

/* The following is a list of ansi escape codes
   used to change the background color of output */
#define B_BLACK     "\x1b[40m"
#define B_RED       "\x1b[41m"
#define B_GREEN     "\x1b[42m"
#define B_YELLOW    "\x1b[43m"
#define B_BLUE      "\x1b[44m"
#define B_MAGENTA   "\x1b[45m"
#define B_CYAN      "\x1b[46m"
#define B_WHITE     "\x1b[47m"

#define UNDERLINE   "\x1b[4m" /* toggle underlined output on */
#define UNDERLINE_O "\x1b[24m" /* toggle underlined output off */
#define NEGATIVE    "\x1b[7m" /* set output to negative */
#define POSITIVE    "\x1b[27m" /* set output to positive */
#define F_DEFAULT   "\x1b[39m" /* set foreground color to default */
#define B_DEFAULT   "\x1b[49m" /* set background color to default */
#define INTENSE     "\x1b[1m" /* toggle bold/intense output on */
#define NORMAL      "\x1b[22m" /* toggle bold/intense/faint output off */

#define RESET       "\x1b[0m" /* set foreground/background colors to default */

#define STYLE_LEN   41 /* the maximum expected length of a style string */

/******************************************************************************
   cp437 characters used to represent solid and empty fills
 ******************************************************************************/
enum fillChars {
    EMPTY=32, FLOOR=250,
    FILL_MIN=176, FILL_MED=177, FILL_MAX=178
};
/******************************************************************************
  cp437 characters used to represent walls
 ******************************************************************************/
enum wallChars {
    HORZ=196, VERT=179,
    CNR_NW=218, CNR_NE=191, CNR_SW=192, CNR_SE=217,
    TEE_N=193, TEE_E=195, TEE_S=194, TEE_W=180,
    CROSS=197
};
/******************************************************************************
  cp437 characters used to represent monsters
 ******************************************************************************/
enum monsterChars {
    PLAYER=64,
    FUNGUS=102
};
/******************************************************************************
  used to store the characteristics of a printable glyph
 ******************************************************************************/
typedef struct {
    int symbol;
    char *style;
} Glyph;
/******************************************************************************
  allocate memory for and initialize the fields of a new Glyph
 ******************************************************************************/
Glyph *newGlyph(int symbol, char *style) {
    Glyph *glyph = (Glyph*)malloc(sizeof(Glyph));
    if (glyph == NULL) {
        fprintf(stderr, "ERROR - failed to allocate Glyph memory - TERMINATING...\n");
        exit(1);
    }

    glyph->symbol = symbol;

    glyph->style = (char*)malloc(sizeof(char)*STYLE_LEN);
    strcpy(glyph->style, style);

    return glyph;
}

#endif /* TILE_RESOURCES_H */
