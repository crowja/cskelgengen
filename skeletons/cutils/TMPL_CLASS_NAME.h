/**
 *  @file TMPL_CLASS_NAME.h
 *  @version TMPL_CLASS_VERSION
 *  @date %TODAY%
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


/**
 *  @brief FIXME Example function.
 *  @details FIXME longer description here ...
 *
 *  @param cp [in] Pointer to a string.
 */

int         TMPL_CLASS_TAG_func1(const char *cp);

/**
 *  @brief Return the version of this package.
 *  @details FIXME longer description here ...
 */

const char *TMPL_CLASS_TAG_version(void);

#endif
