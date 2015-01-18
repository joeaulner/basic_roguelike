/******************************************************************************
  A header file that defines various ansi escape sequences used to print
  formatted output.
 ******************************************************************************/
#ifndef DISPLAY_STYLE_H
#define DISPLAY_STYLE_H
/******************************************************************************
  The following is a list of ansi escape codes
  used to change the foreground color of output
 ******************************************************************************/
#define F_BLACK     "\x1b[30m"
#define F_RED       "\x1b[31m"
#define F_GREEN     "\x1b[32m"
#define F_YELLOW    "\x1b[33m"
#define F_BLUE      "\x1b[34m"
#define F_MAGENTA   "\x1b[35m"
#define F_CYAN      "\x1b[36m"
#define F_WHITE     "\x1b[37m"
/******************************************************************************
  The following is a list of ansi escape codes used
  to change the foreground color of intense output
 ******************************************************************************/
#define FI_BLACK     "\x1b[90m"
#define FI_RED       "\x1b[91m"
#define FI_GREEN     "\x1b[92m"
#define FI_YELLOW    "\x1b[93m"
#define FI_BLUE      "\x1b[94m"
#define FI_MAGENTA   "\x1b[95m"
#define FI_CYAN      "\x1b[96m"
#define FI_WHITE     "\x1b[97m"
/******************************************************************************
  The following is a list of ansi escape codes
  used to change the background color of output
 ******************************************************************************/
#define B_BLACK     "\x1b[40m"
#define B_RED       "\x1b[41m"
#define B_GREEN     "\x1b[42m"
#define B_YELLOW    "\x1b[43m"
#define B_BLUE      "\x1b[44m"
#define B_MAGENTA   "\x1b[45m"
#define B_CYAN      "\x1b[46m"
#define B_WHITE     "\x1b[47m"
/******************************************************************************
  The following is a list of ansi escape codes used
  to change the background color of intense output
 ******************************************************************************/
#define BI_BLACK     "\x1b[100m"
#define BI_RED       "\x1b[101m"
#define BI_GREEN     "\x1b[102m"
#define BI_YELLOW    "\x1b[103m"
#define BI_BLUE      "\x1b[104m"
#define BI_MAGENTA   "\x1b[105m"
#define BI_CYAN      "\x1b[106m"
#define BI_WHITE     "\x1b[107m"
/******************************************************************************
  The following is a list of ansi escape codes used to
  define miscellaneous characteristics of formatted output
 ******************************************************************************/
#define FAINT	    "\x1b[2m" /* toggle faint output on */
#define UNDERLINE   "\x1b[4m" /* toggle underlined output on */
#define UNDERLINE_O "\x1b[24m" /* toggle underlined output off */
#define NEGATIVE    "\x1b[7m" /* set output to negative */
#define POSITIVE    "\x1b[27m" /* set output to positive */
#define F_DEFAULT   "\x1b[39m" /* set foreground color to default */
#define B_DEFAULT   "\x1b[49m" /* set background color to default */
#define INTENSE     "\x1b[1m" /* toggle bold/intense output on */
#define NORMAL      "\x1b[22m" /* toggle bold/intense */

#define RESET       "\x1b[0m" /* set foreground/background colors to default */

#endif /* DISPLAY_STYLE_H */

