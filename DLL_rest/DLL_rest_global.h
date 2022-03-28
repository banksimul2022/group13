#ifndef DLL_REST_GLOBAL_H
#define DLL_REST_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(DLL_REST_LIBRARY)
#  define DLL_REST_EXPORT Q_DECL_EXPORT
#else
#  define DLL_REST_EXPORT Q_DECL_IMPORT
#endif

#endif // DLL_REST_GLOBAL_H
