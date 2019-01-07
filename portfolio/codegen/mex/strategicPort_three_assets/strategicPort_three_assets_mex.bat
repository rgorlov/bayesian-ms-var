@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=strategicPort_three_assets_mex
set MEX_NAME=strategicPort_three_assets_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for strategicPort_three_assets > strategicPort_three_assets_mex.mki
echo COMPILER=%COMPILER%>> strategicPort_three_assets_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> strategicPort_three_assets_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> strategicPort_three_assets_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> strategicPort_three_assets_mex.mki
echo LINKER=%LINKER%>> strategicPort_three_assets_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> strategicPort_three_assets_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> strategicPort_three_assets_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> strategicPort_three_assets_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> strategicPort_three_assets_mex.mki
echo BORLAND=%BORLAND%>> strategicPort_three_assets_mex.mki
echo OMPFLAGS= >> strategicPort_three_assets_mex.mki
echo OMPLINKFLAGS= >> strategicPort_three_assets_mex.mki
echo EMC_COMPILER=mingw64>> strategicPort_three_assets_mex.mki
echo EMC_CONFIG=optim>> strategicPort_three_assets_mex.mki
"C:\Program Files\MATLAB\R2015b\bin\win64\gmake" -B -f strategicPort_three_assets_mex.mk
