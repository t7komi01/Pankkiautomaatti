#ifndef BANKLIBRARY_GLOBAL_H
#define BANKLIBRARY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(BANKLIBRARY_LIBRARY)
#  define BANKLIBRARYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define BANKLIBRARYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // BANKLIBRARY_GLOBAL_H