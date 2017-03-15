COPY %1\commomModel.dll X:\commomModel\dll_%2\bin\commomModel.dll
COPY %1\commomModel.lib X:\commomModel\dll_%2\bin\commomModel.lib

DEL /S X:\commomModel\dll_%2\include\*.h
XCOPY /S /Y X:\commomModel\commomModel\*.h X:\commomModel\dll_%2\include