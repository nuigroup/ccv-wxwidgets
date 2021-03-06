ccv-wxwidgets
=============

Rebuilding CCV for WxWidgets and Modular architecture based on Movid.

== Supported Platforms ==
CCV2 use cmake (http://cmake.org/) as its build system. It can be build on Windows,
Mac OS X and Linux. Please make sure cmake has been installed before trying to build.
As an alternative way, you can also use MSVC to build.

== Dependencies ==
CCV2 depends on NUIFrameworks. NUIFrameworks requires OpenCV, and CCV2 requires 
both OpenCV and wxWidgets. Before building, OpenCV and wxWidgets must be installed.

For Ubuntu, installing OpenCV and wxWidgets should be very easy, 
what you just need to do is type the following command:
   sudo apt-get install libcv-dev libcvaux-dev libhighgui-dev libwxgtk2.8-dev

For Windows, you can download binary libraries:
binary wxWidgets for win32 (wxPack):
   http://wxpack.sourceforge.net
binary OpenCV2.3 for win32 (the "superpack"):
   http://sourceforge.net/projects/opencvlibrary/files/opencv-win/2.3/OpenCV-2.3.0-win-superpack.exe/download

You can also choose download the source codes of wxWidgets and OpenCV and compile
them by yourself.

== Build Steps ==
Step 1: Install the dependencies (OpenCV, wxWidgets).
Step 2: cd xxx/trunk && mkdir build
Step 3: cd build && cmake ..
Step 4: make

== Build with MSVC ==
If you are a Windows guy, You may want to use MSVC to build. Before compiling,
make sure the environment variable WXWIN was set to wxWidgets's path, 
OPENCV_DIR was set to opencv's path (do not need these for cmake users).
We provided a Visual C++ 2010 sln. To compile, cd trunk/CCV2.0/msvc, and then
run msvc\build.bat. Or open CCV.sln and click the Rebuild button.
