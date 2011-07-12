== Compile on Windows ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  Microsoft Visual C++ 2010 (Free express version is enough)

You do not need compile wxWidgets by yourself. You can download the 
binary wxWidgets (wxPack) from:
  http://wxpack.sourceforge.net

Microsoft provided a free express version's Visual C++:
  http://www.microsoft.com/express/Downloads/#2010-Visual-CPP

To compile, just run msvc\build.bat. Before compiling, make environment
variable WXWIN was set to wxWidgets's path, OPENCV_DIR was set to opencv's path.

== Compile on Mac OS X ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  gcc4
  
Move makefiles/Makefile.osx to the this folder and rename it to Makefile.  
  
you may need to select the correct gcc version in shell like this:
  $ sudo gcc_select gcc42

To compile, just run "make" in the uxix shell.

== Compile on Linux ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  gcc4
  
Move makefiles/Makefile.linux to the this folder and rename it to Makefile.    

If you are using Ubuntu, you may want to use apt to install binary wxWidgets:
  $ sudo aptitude install libwxgtk2.8-dev

To compile, just run "make" in the uxix shell.
