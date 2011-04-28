This is the new CCV that based on wxWidgets.

== Complie under Windows ==
Require:
  wxWidget
  MinGW

To complie, use the following command in MinGW shell:
  $ mingw32-make -f Makefile.mingw32

== Complie under Mac OS X ==
Require:
  gcc4
  
you may need select the correct gcc version in shell like this:
  $ sudo gcc_select gcc42

To complie, use the following command in uxix shell:
  $ make -f Makefile.osx

== Notes & Tips ==
1. Compiling wxWidgets need a long time. For windows users, you can download the binary wxWidgets from http://wxpack.sourceforge.net
2. If you want to build documents, you need install doxygen and use the following command:
   $ make -f Makefile.yourplatform doc
   