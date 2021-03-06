/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef Security_H
#define Security_H

#include "exception/Except.h"
#include "util/log/Log.h"
#include "util/Linker.h"
#ifdef win32
    Linker_require("util/Security_Windows.c")
#else
    Linker_require("util/Security.c")
#endif

/** @return Security_setUser_PERMISSION if the user does not have sufficient permissions. */
#define Security_setUser_PERMISSION -1
int Security_setUser(char* userName, struct Log* logger, struct Except* eh);

void Security_noFiles(struct Except* eh);

void Security_maxMemory(unsigned long maxMemory, struct Except* eh);

#endif
