#ifndef __MAIL_CUSTOM_FLAGS_H
#define __MAIL_CUSTOM_FLAGS_H

/* NOTE: Contains it's own locking, unrelated to index locks. */

#include "mail-index.h"

#define CUSTOM_FLAGS_FILE_NAME ".customflags"

int mail_custom_flags_open_or_create(struct mail_index *index);
void mail_custom_flags_free(struct mail_custom_flags *mcf);

/* Change custom flags so that they reflect the real flag numbers in
   the file. Initially flags contains the custom flags in the order of the
   specified list, it's modified to reflect the actual list. Returns 1 if ok,
   0 if number of custom flags exceeded or -1 if error */
int mail_custom_flags_fix_list(struct mail_custom_flags *mcf,
			       enum mail_flags *flags,
			       const char *custom_flags[], unsigned int count);

/* Returns a pointer to list of flags. Note that calls to
   mail_cutom_flags_fix_list() may modify the flags in the returned list.
   It can modify only the flags that aren't in use anywhere, so this should
   be safe. */
const char **mail_custom_flags_list_get(struct mail_custom_flags *mcf);

/* Returns TRUE if there's been any changes since this function was
   called last time, or since open if this is the first call. */
int mail_custom_flags_has_changes(struct mail_custom_flags *mcf);

#endif
