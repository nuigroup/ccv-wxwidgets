This is the CCV based on wxWidgets.

== For Windows ==
Require:
  wxWidget
  MinGW

To complie, use the following command in MinGW shell:
  mingw32-make -f Makefile.mingw32

== For Mac OS X ==
Require:
  gcc4
you may need select the correct gcc version in shell like this:
  $sudo gcc_select gcc42

To complie, use the following command in uxix shell:
  make -f Makefile.osx 