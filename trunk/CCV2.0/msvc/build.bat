call "%VS100COMNTOOLS%..\..\VC\vcvarsall.bat"
msbuild /p:Configuration=Release /p:Platform="Win32" %*
@pause
