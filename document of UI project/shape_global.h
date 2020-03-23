#ifndef SHAPE_GLOBAL_H
#define SHAPE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SHAPE_LIBRARY)
#  define SHAPE_EXPORT Q_DECL_EXPORT
#else
#  define SHAPE_EXPORT Q_DECL_IMPORT
#endif

#endif // SHAPE_GLOBAL_H
