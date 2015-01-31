/*
 * This file is part of libbluray
 * Copyright (C) 2010  William Hahne
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef BDJ_H_
#define BDJ_H_

#include "util/attributes.h"

typedef enum {
    BDJ_EVENT_NONE = 0,
    BDJ_EVENT_CHAPTER,
    BDJ_EVENT_PLAYITEM,
    BDJ_EVENT_ANGLE,
    BDJ_EVENT_SUBTITLE,
    BDJ_EVENT_PIP,
    BDJ_EVENT_END_OF_PLAYLIST,
    BDJ_EVENT_PTS,
    BDJ_EVENT_VK_KEY,
    BDJ_EVENT_MARK,
    BDJ_EVENT_PSR102,
    BDJ_EVENT_PLAYLIST,

    BDJ_EVENT_START, /* param: title number */
    BDJ_EVENT_STOP,

    BDJ_EVENT_RATE,
} BDJ_EVENT;

typedef struct {
    char *persistent_root;
    char *cache_root;
} BDJ_STORAGE;

typedef struct bdjava_s BDJAVA;

struct bluray;

BD_PRIVATE BDJAVA* bdj_open(const char *path, struct bluray *bd,
                            const char *bdj_disc_id, BDJ_STORAGE *storage);
BD_PRIVATE void bdj_close(BDJAVA *bdjava);
BD_PRIVATE int  bdj_process_event(BDJAVA *bdjava, unsigned ev, unsigned param);

BD_PRIVATE int  bdj_jvm_available(void); /* 0: no. 1: only jvm. 2: jvm + libbluray.jar. */

#endif
