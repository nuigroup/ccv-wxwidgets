SRCDIRS=src
SRCS=$(foreach dir,$(SRCDIRS),$(wildcard $(dir)/*.cpp))
PROGDIR=build
PROGRAM=CCV
OSXPLIST=res/osx/Info.plist
OSTYPE = $(shell uname)

all: $(PROGRAM)
ifeq ($(OSTYPE), Darwin)
	mkdir -p $(PROGRAM).app/Contents/MacOS
	cp $(OSXPLIST) $(PROGRAM).app/Contents/
	cp $(PROGDIR)/$(PROGRAM) $(PROGRAM).app/Contents/MacOS/$(PROGRAM)
endif
     
clean:
	rm -fr $(PROGDIR) *.app

$(PROGRAM):
	mkdir -p build
	g++ -m32 $(SRCS) `wx-config --libs --cxxflags` -o $(PROGDIR)/$(PROGRAM)
