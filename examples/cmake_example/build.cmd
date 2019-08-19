rmdir /S /Q build
mkdir build
cd build

REM Mimic submodule process by copying cpp-client src into the expected directory
REM git doesn't like nested .gitmodule files
rmdir /S /Q ..\lib\cpp-client\
mkdir ..\lib\cpp-client\
xcopy /E /Y /H /R ..\..\..\src ..\lib\cpp-client\

cmake ..
cmake --build .
