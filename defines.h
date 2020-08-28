
#ifndef _DEFINES_H
#define _DEFINES_H 1

#define ALT(key)	((key) + (161 - 'a'))
#if defined(CTRL) && defined(_AIX)
# undef CTRL
#endif

#ifndef CTRL
# define CTRL(key)	((key) & 0x1F)
#endif

#define CTRL_ALT(key)	((key) + (129 - 'a'))

#define IS_CONTROL(key)	(!((key) & 0xFFFFFF60ul))


#define countof(arr)	(sizeof(arr) / sizeof((arr)[0]))
#define MAX(x, y)	((x) > (y) ? (x) : (y))
#define MIN(x, y)	((x) < (y) ? (x) : (y))

#endif /* _DEFINES_H */
