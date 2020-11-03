#ifndef TICTACTOE_GLOBAL_H
#define TICTACTOE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TICTACTOE_LIBRARY)
#  define TICTACTOE_EXPORT Q_DECL_EXPORT
#else
#  define TICTACTOE_EXPORT Q_DECL_IMPORT
#endif

#endif // TICTACTOE_GLOBAL_H
