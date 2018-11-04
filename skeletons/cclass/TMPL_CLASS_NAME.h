/**
 *  @file TMPL_CLASS_NAME.h
 *  @version TMPL_CLASS_VERSION
 *  @date
 *  @copyright %COPYRIGHT%
 *  @brief FIXME
 *  @details FIXME
 */

#ifndef _TMPL_CLASS_NAME_UC_H_
#define _TMPL_CLASS_NAME_UC_H_

#ifdef  _PACKAGE_NAME
#undef  _PACKAGE_NAME
#endif
#define _PACKAGE_NAME "TMPL_CLASS_NAME"

struct TMPL_CLASS_NAME;

/**
 *  @brief Create and return a new TMPL_CLASS_NAME object.
 *  @details FIXME longer description here ...
 */

struct TMPL_CLASS_NAME *TMPL_CLASS_TAG_new(void);

/**
 *  @brief Clean up and free a TMPL_CLASS_NAME structure.
 *  @details FIXME longer description here ...
 */

void        TMPL_CLASS_TAG_free(struct TMPL_CLASS_NAME *p);

/**
 *  @brief Initialize a TMPL_CLASS_NAME object.
 *  @details FIXME longer description here ...
 *  @param p Pointer to a TMPL_CLASS_NAME object
 *  @param x FIXME
 */

int         TMPL_CLASS_TAG_init(struct TMPL_CLASS_NAME *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @details FIXME longer description here ...
 */

const char *TMPL_CLASS_TAG_version(void);

#endif
