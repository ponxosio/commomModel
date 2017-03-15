COPY %1\commonModel.dll X:\commomModel\dll_%2\bin\commonModel.dll
COPY %1\commonModel.lib X:\commomModel\dll_%2\bin\commonModel.lib

DEL /S X:\commomModel\dll_%2\include\*.h
XCOPY /S /Y X:\commomModel\commomModel\*.h X:\commomModel\dll_%2\include