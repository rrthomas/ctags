/*
 *   Copyright (c) 2019, Alberto Fanjul <albfan@gnome.org>
 *
 *   This source code is released for free distribution under the terms of the
 *   GNU General Public License version 2 or (at your option) any later version.
 */

#ifndef CTAGS_PARSER_VALA_H
#define CTAGS_PARSER_VALA_H

/*
*   INCLUDE FILES
*/
#include "general.h"  /* must always come first */

#include "subparser.h"
#include "tokeninfo.h"

typedef struct sValaSubparser valaSubparser;

enum ValaTokenType {
	/* 0..255 are the byte's value */
	TOKEN_VALA_EOF = 256,
	TOKEN_VALA_UNDEFINED,
	TOKEN_VALA_KEYWORD,
	TOKEN_VALA_IDENTIFIER,
	TOKEN_VALA_VARIABLE,
	TOKEN_VALA_EOL,
	TOKEN_VALA_STRING,
};

struct sValaSubparser {
	subparser subparser;

	/* `pstate' is needed to call newValaToken(). */
	void (* packageRequirementNotify) (valaSubparser *s, char *package,
									   void *pstate);
	void (* namespaceImportNotify) (valaSubparser *s, char *namespace,
									void *pstate);
	/* Return CORK_NIL if the command line is NOT consumed.
	   If a positive integer is returned, end: field may
	   be attached by tcl base parser.
	   Return CORK_NIL - 1 if the command line is consumed
	   but not tag is made. */
	int (* commandNotify) (valaSubparser *s, char *command,
						   int parentIndex,
						   void *pstate);
};

extern tokenInfo *newValaToken (void *pstate);
extern void skipToEndOfValaCmdline (tokenInfo *const token);

#endif	/* CTAGS_PARSER_VALA_H */
