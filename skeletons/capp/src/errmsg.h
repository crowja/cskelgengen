#ifndef _ERRMSG_H_
#define _ERRMSG_H_

/**
 *  @brief Print an error, success, or warning message.
 */
void        errmsg_error(FILE *out, const char *info);  /* red */
void        errmsg_success(FILE *out, const char *info);        /* green */
void        errmsg_warning(FILE *out, const char *info);        /* yellow */

#endif
