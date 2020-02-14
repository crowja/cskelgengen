/**
 *  @file errmsg.h
 *  @version 0.1.0-dev0
 *  @date Sun Jan 19 23:12:14 CST 2020
 *  @copyright 2020 John A. Crow <crowja@gmail.com>
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef ERRMSG_H_
#define ERRMSG_H_

/**
 *  @brief Print an error, success, or warning message.
 */
void        errmsg_error(FILE *out, const char *info);  /* red */
void        errmsg_success(FILE *out, const char *info);        /* green */
void        errmsg_warning(FILE *out, const char *info);        /* yellow */

#endif
