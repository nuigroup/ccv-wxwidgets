== Compile on Mac OS X ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  gcc4
  
you may need to select the correct gcc version in shell like this:
  $ sudo gcc_select gcc42

To compile, use the following command in uxix shell:
  $ make -f Makefile.osx

== Compile on Linux ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  gcc4

If you are using Ubuntu, you may want to use apt to install binary wxWidgets:
  $ sudo aptitude install libwxgtk2.8-dev

To compile, use the following command in uxix shell:
  $ make -f Makefile.linux
  
== Compile on Windows ==
Require:
  wxWidgets
  OpenCV2.2 or higher

You can download the binary wxWidgets (wxPack) from:
http://wxpack.sourceforge.net

For some reason, the mingw does not work for CCV now, we'll fix it in futrue.
At present you need to use Microsoft Visual C++ 2010 to compile CCV. Microsoft
provided a Visual C++'s free express version, which can be download from:
http://www.microsoft.com/express/Downloads/#2010-Visual-CPP

To compile, open MSVC\ccv2.sln and run build. Before compiling, make sure set
environment variable WXWIN to the wxWidgets path, OPENCVWIN to the opencv path.

== Documents ==
If you want to build documents, you need install doxygen and use the following
command:
   $ make -f Makefile.yourplatform doc
