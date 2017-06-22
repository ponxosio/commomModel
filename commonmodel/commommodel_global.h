#ifndef COMMOMMODEL_GLOBAL_H
#define COMMOMMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(COMMOMMODEL_LIBRARY)
#  define PLUGINCONFIGURATION_EXPORT Q_DECL_EXPORT
#  define PUMPPLUGINFUNCTION_EXPORT Q_DECL_EXPORT
#  define VALVEPLUGINGROUTINGFUNCTION_EXPORT Q_DECL_EXPORT
#  define FUNCTIONSET_EXPORT Q_DECL_EXPORT
#  define HEATFUNCTION_EXPORT Q_DECL_EXPORT
#  define LIGHTFUNCTION_EXPORT Q_DECL_EXPORT
#  define MEASUREOD_EXPORT Q_DECL_EXPORT
#  define STIRFUNCTION_EXPORT Q_DECL_EXPORT
#  define MEASURETEMPERATUREFUNCTION_EXPORT Q_DECL_EXPORT
#  define MEASURELUMINISCENCEFUNCTION_EXPORT Q_DECL_EXPORT
#  define CENTRIFUGATIONWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define ELECTROPHORESISWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define EMPTYWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define HEATERWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define LIGTHWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define MEASUREFLUORESCENCEWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define MEASUREODWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define PUMPWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define SHAKEWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define STIRWORKINGRANGE_EXPORT Q_DECL_EXPORT
#  define ELECTROPHORESISFUNCTION_EXPORT Q_DECL_EXPORT
#  define MEASUREFLUORESCENCEFUNCTION_EXPORT Q_DECL_EXPORT
#  define MEASUREVOLUMEFUNCTION_EXPORT Q_DECL_EXPORT
#  define SHAKEFUNCTION_EXPORT Q_DECL_EXPORT
#  define CENTRIFUGATEFUNCTION_EXPORT Q_DECL_EXPORT
#else
#  define PLUGINCONFIGURATION_EXPORT Q_DECL_IMPORT
#  define PUMPPLUGINFUNCTION_EXPORT Q_DECL_IMPORT
#  define VALVEPLUGINGROUTINGFUNCTION_EXPORT Q_DECL_IMPORT
#  define FUNCTIONSET_EXPORT Q_DECL_IMPORT
#  define HEATFUNCTION_EXPORT Q_DECL_IMPORT
#  define LIGHTFUNCTION_EXPORT Q_DECL_IMPORT
#  define MEASUREOD_EXPORT Q_DECL_IMPORT
#  define STIRFUNCTION_EXPORT Q_DECL_IMPORT
#  define MEASURETEMPERATUREFUNCTION_EXPORT Q_DECL_IMPORT
#  define MEASURELUMINISCENCEFUNCTION_EXPORT Q_DECL_IMPORT
#  define CENTRIFUGATIONWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define ELECTROPHORESISWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define EMPTYWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define HEATERWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define LIGTHWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define MEASUREFLUORESCENCEWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define MEASUREODWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define PUMPWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define SHAKEWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define STIRWORKINGRANGE_EXPORT Q_DECL_IMPORT
#  define ELECTROPHORESISFUNCTION_EXPORT Q_DECL_IMPORT
#  define MEASUREFLUORESCENCEFUNCTION_EXPORT Q_DECL_IMPORT
#  define MEASUREVOLUMEFUNCTION_EXPORT Q_DECL_IMPORT
#  define SHAKEFUNCTION_EXPORT Q_DECL_IMPORT
#  define CENTRIFUGATEFUNCTION_EXPORT Q_DECL_IMPORT
#endif

#endif // COMMOMMODEL_GLOBAL_H
