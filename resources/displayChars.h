/******************************************************************************
  A header file that contains enumerations that identify which cp437
  characters will be used to represent what object in a map.
 ******************************************************************************/
#ifndef DISPLAY_CHARS_H
#define DISPLAY_CHARS_H
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
    CROSS=197,

    DOOR=47
};
/******************************************************************************
  cp437 characters used to represent monsters
 ******************************************************************************/
enum monsterChars {
    PLAYER=64,
    FUNGUS=102
};

#endif /* DISPLAY_CHARS_H */

