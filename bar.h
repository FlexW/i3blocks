/*
 * bar.h - definition of a status line handling functions
 * Copyright (C) 2014  Vivien Didelot
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _BAR_H
#define _BAR_H

#include <stdbool.h>

struct map;

int i3bar_read(int fd, size_t count, struct map *map);

struct bar {
	struct block *blocks;
	bool frozen;
	bool term;
};

struct bar *bar_create(bool term);
void bar_destroy(struct bar *bar);
void bar_load(struct bar *bar, const char *path);
void bar_schedule(struct bar *bar);
void bar_dump(struct bar *bar);
int bar_click(struct bar *bar);

#endif /* _BAR_H */
