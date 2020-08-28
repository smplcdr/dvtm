/*
 * Copyright © 2004 Bruno T. C. de Oliveira
 * Copyright © 2006 Pierre Habouzit
 * Copyright © 2008-2013 Marc André Tanner
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF MIND, USE, DATA OR PROFITS, WHETHER
 * IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#ifndef _VT_H
#define _VT_H 1

#include <curses.h>
#include <stdbool.h>
#include <sys/types.h>

#ifndef NCURSES_MOUSE_VERSION
# define mmask_t unsigned long
#endif

typedef struct Vt Vt;
typedef void (*vt_title_handler_t)(Vt *, const char *title);
typedef void (*vt_urgent_handler_t)(Vt *);

extern void vt_init(void);
extern void vt_shutdown(void);

extern void vt_keytable_set(char const *const keytable_overlay[], int count);
extern void vt_default_colors_set(Vt *, attr_t attrs, short int fg, short int bg);
extern void vt_title_handler_set(Vt *, vt_title_handler_t);
extern void vt_urgent_handler_set(Vt *, vt_urgent_handler_t);
extern void vt_data_set(Vt *, void *);
extern void *vt_data_get(Vt *);

extern Vt *vt_create(int rows, int cols, int scroll_buf_sz);
extern void vt_resize(Vt *, int rows, int cols);
extern void vt_destroy(Vt *);
extern pid_t vt_forkpty(Vt *, const char *p, const char *argv[], const char *cwd,
			const char *env[], int *to, int *from);
extern int vt_pty_get(Vt *);
extern bool vt_cursor_visible(Vt *);

extern int vt_process(Vt *);
extern void vt_keypress(Vt *, int keycode);
extern ssize_t vt_write(Vt *, const char *buf, size_t len);
extern void vt_mouse(Vt *, int x, int y, mmask_t mask);
extern void vt_dirty(Vt *);
extern void vt_draw(Vt *, WINDOW *win, int startrow, int startcol);
extern short int vt_color_get(Vt *, short int fg, short int bg);
extern short int vt_color_reserve(short int fg, short int bg);

extern void vt_scroll(Vt *, int rows);
extern void vt_noscroll(Vt *);

extern pid_t vt_pid_get(Vt *);
extern size_t vt_content_get(Vt *, char **s, bool colored);
extern int vt_content_start(Vt *);

#endif /* _VT_H */
