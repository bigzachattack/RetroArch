/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2011-2015 - Daniel De Matteis
 *  Copyright (C) 2014-2015 - Jean-André Santoni
 *
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MENU_LIST_H
#define _MENU_LIST_H

#include <stddef.h>

#include <boolean.h>
#include <file/file_list.h>

#include "menu_entries.h"
#include "menu_setting.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct menu_list
{
   file_list_t *menu_stack;
   file_list_t *selection_buf;
} menu_list_t;

typedef enum
{
   MENU_LIST_PLAIN = 0,
   MENU_LIST_HORIZONTAL
} menu_list_type_t;


menu_list_t *menu_list_get_ptr(void);

void menu_list_free(menu_list_t *menu_list);

menu_list_t *menu_list_new(void);

void menu_list_flush_stack(menu_list_t *list,
      const char *needle, unsigned final_type);

bool menu_list_pop_stack(menu_list_t *list, size_t *directory_ptr);

void menu_list_get_at_offset(const file_list_t *list, size_t idx,
      const char **path, const char **label, unsigned *file_type,
      size_t *entry_idx);

void *menu_list_get_userdata_at_offset(const file_list_t *list, size_t idx);

menu_file_list_cbs_t *menu_list_get_actiondata_at_offset(const file_list_t *list, size_t idx);

size_t menu_list_get_stack_size(menu_list_t *list);

size_t menu_list_get_size(menu_list_t *list);

menu_file_list_cbs_t *menu_list_get_last_stack_actiondata(const menu_list_t *list);

void menu_list_get_last(const file_list_t *list,
      const char **path, const char **label,
      unsigned *file_type, size_t *entry_idx);

void menu_list_get_last_stack(const menu_list_t *list,
      const char **path, const char **label,
      unsigned *file_type, size_t *entry_idx);

void menu_list_clear(file_list_t *list);

void menu_list_push(file_list_t *list,
      const char *path, const char *label,
      unsigned type, size_t directory_ptr,
      size_t entry_idx);

void menu_list_get_alt_at_offset(const file_list_t *list, size_t idx,
      const char **alt);

void menu_list_set_alt_at_offset(file_list_t *list, size_t idx,
      const char *alt);

void menu_list_refresh(file_list_t *list);

#ifdef __cplusplus
}
#endif

#endif
