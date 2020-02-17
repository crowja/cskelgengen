/**
 *  @file TMPL_CLASS_NAME.h
 *  @version 0.0.0
 *  @date
 *  @copyright
 *  @license Unlicense <http://unlicense.org/>
 */

#ifndef TMPL_CLASS_NAME_UC_H
#define TMPL_CLASS_NAME_UC_H

struct TMPL_CLASS_NAME;

/**
 *  @brief Constructor.
 *  @details Create and return a new TMPL_CLASS_NAME object.
 *  @returns New TMPL_CLASS_NAME object.
 */
struct TMPL_CLASS_NAME *TMPL_CLASS_TAG_new(void);

/**
 *  @brief Destructor.
 *  @details Clean up and free a TMPL_CLASS_NAME structure.
 *  @param[in, out] p.
 */
void        TMPL_CLASS_TAG_free(struct TMPL_CLASS_NAME **pp);

/**
 *  @brief Initialize a TMPL_CLASS_NAME object.
 *  @details FIXME longer description here ...
 *  @param[in,out] p Pointer to a TMPL_CLASS_NAME object
 *  @param[in] x FIXME
    @returns FIXME
 */
int         TMPL_CLASS_TAG_init(struct TMPL_CLASS_NAME *p, void *x);

/**
 *  @brief Return the version of this package.
 *  @returns Version string.
 */
const char *TMPL_CLASS_TAG_version(void);

#endif
