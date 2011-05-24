This is the new CCV that based on wxWidgets.

== Complie under Windows ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  MinGW

You can download the binary wxWidgets (wxPack) from http://wxpack.sourceforge.net

To complie, use the following command in MinGW shell:
  $ mingw32-make -f Makefile.mingw32

== Complie under Mac OS X ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  gcc4
  
you may need to select the correct gcc version in shell like this:
  $ sudo gcc_select gcc42

To complie, use the following command in uxix shell:
  $ make -f Makefile.osx

== Complie under Linux ==
Require:
  wxWidgets
  OpenCV2.2 or higher
  gcc4

If you are using Ubuntu, you may want to use apt to install binary wxWidgets:
  $ sudo aptitude install libwxgtk2.8-dev

To complie, use the following command in uxix shell:
  $ make -f Makefile.linux


== Documents ==
If you want to build documents, you need install doxygen and use the following command:
   $ make -f Makefile.yourplatform doc
