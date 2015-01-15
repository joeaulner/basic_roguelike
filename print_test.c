
#include <stdio.h>
#include <stdlib.h>
#include "resources/display.h"

int main() {
    int i;
    Glyph *player = newGlyph(PLAYER, F_BLUE INTENSE);

    /* clear the screen before demonstrating available color schemes */
    system("clear");

    /* show different foreground colors */
    printf("Here is some text displayed with multiple foreground colors:\n");
    printf("Black:  " F_BLACK "I am some BLACK text.\n" RESET);
    printf("Red:    " F_RED "I am some RED text.\n" RESET);
    printf("Green:  " F_GREEN "I am some GREEN text.\n" RESET);
    printf("Yellow: " F_YELLOW "I am some YELLOW text.\n" RESET);
    printf("Blue:   " F_BLUE "I am some BLUE text.\n" RESET);
    printf("Magenta:" F_MAGENTA "I am some MAGENTA text.\n" RESET);
    printf("Cyan:   " F_CYAN "I am some CYAN text.\n" RESET);
    printf("White:  " F_WHITE "I am some WHITE text.\n\n" RESET);

    /* show different intense foreground colors */
    printf(INTENSE);
    printf("Here is some intense text displayed with multiple foreground colors:\n");
    printf("Black:  " F_BLACK "I am some BLACK text.\n" F_WHITE);
    printf("Red:    " F_RED "I am some RED text.\n" F_WHITE);
    printf("Green:  " F_GREEN "I am some GREEN text.\n" F_WHITE);
    printf("Yellow: " F_YELLOW "I am some YELLOW text.\n" F_WHITE);
    printf("Blue:   " F_BLUE "I am some BLUE text.\n" F_WHITE);
    printf("Magenta:" F_MAGENTA "I am some MAGENTA text.\n" F_WHITE);
    printf("Cyan:   " F_CYAN "I am some CYAN text.\n" F_WHITE);
    printf("White:  " F_WHITE "I am some WHITE text.\n\n" RESET);

    /* show different background colors */
    printf("Here is some text displayed with multiple background colors:\n");
    printf("Black:  " B_BLACK "I have a BLACK background.\n" RESET);
    printf("Red:    " B_RED "I have a RED background.\n" RESET);
    printf("Green:  " B_GREEN "I have a GREEN background.\n" RESET);
    printf("Yellow: " B_YELLOW "I have a YELLOW background.\n" RESET);
    printf("Blue:   " B_BLUE "I have a BLUE background.\n" RESET);
    printf("Magenta:" B_MAGENTA "I have a MAGENTA background.\n" RESET);
    printf("Cyan:   " B_CYAN "I have a CYAN background.\n" RESET);
    printf("White:  " B_WHITE "I have a WHITE background.\n\n" RESET);

    /* show an example player glyph */
    printf("Here is an example player glyph:\n %s%c\n\n" RESET,
            player->style, player->symbol);

    /* show the cp 437 characters */
    printf("And here are characters 32-255 from the cp437:" F_GREEN);
    for (i = 32; i < 256; i++) {
        if (i % 32 == 0) {
            printf("\n ");
        }
        printf("%c", i);
    }
    printf("\n\n" RESET);

    /* show an example room drawing */
    printf("And here is a possible room drawn using cp437 characters:\n");
    printf(INTENSE "%c%c%c%c%c%c%c%c%c\n%c%c%c%c%c%c%c%c%c\n%c%c%s%c%s%c%c%c%c%c%c\n%c%c%c%c%c%c%c%c%c\n%c%c%c%c%c%c%c%c%c\n%c%c%c%c%c%c%c%c%c\n\n" RESET,
            CNR_NW, HORZ, HORZ, HORZ, HORZ, HORZ, HORZ, HORZ, CNR_NE,
            VERT, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, VERT,
            VERT, FLOOR, INTENSE F_BLUE, PLAYER, INTENSE F_WHITE, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, VERT,
            VERT, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, VERT,
            VERT, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, FLOOR, VERT,
            CNR_SW, HORZ, HORZ, HORZ, HORZ, HORZ, HORZ, HORZ, CNR_SE);

    return 0;
}
