This is the new CCV that based on wxWidgets.

== Complie under Windows ==
Require:
  wxWidget
  MinGW
  Doxygen

To complie, use the following command in MinGW shell:
  $ mingw32-make -f Makefile.mingw32

== Complie under Mac OS X ==
Require:
  gcc4
  Doxygen
  
you may need select the correct gcc version in shell like this:
  $ sudo gcc_select gcc42

To complie, use the following command in uxix shell:
  $ make -f Makefile.osx
