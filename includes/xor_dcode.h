#ifndef XOR_DECODE_H
#define XOR_DECODE_H

#include "libft.h"

#define ONE_LINE 0
#define ZEROX 1
#define BSX 2			// backslashx //x
#define SPACE 3
#define COLUMN 4
#define SEMI_COL 5
#define COMMA 6

char	*remove_whitespace(char *str);
char	*reset_hex(char *str);
char	*hex_format(char *str, int type);

#endif
