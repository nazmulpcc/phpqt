NAME = phpqt

INI_DIR = $(shell php-config --configure-options | sed -n 's/.*--with-config-file-scan-dir=\([^ ]*\).*/\1/p')

#
#   The extension dirs
#
#   This is normally a directory like /usr/lib/php5/20121221 (based on the 
#   PHP version that you use. We make use of the command line 'php-config' 
#   instruction to find out what the extension directory is, you can override
#   this with a different fixed directory
#

EXTENSION_DIR       =   $(shell php-config --extension-dir)

#
#   The name of the extension and the name of the .ini file
#
#   These two variables are based on the name of the extension. We simply add
#   a certain extension to them (.so or .ini)
#

EXTENSION           =   ${NAME}.so
INI                 =   ${NAME}.ini

#
#   Compiler
#
#   By default, the GNU C++ compiler is used. If you want to use a different
#   compiler, you can change that here. You can change this for both the 
#   compiler (the program that turns the c++ files into object files) and for
#   the linker (the program that links all object files into the single .so
#   library file. By default, g++ (the GNU C++ compiler) is used for both.
#

COMPILER = g++
LINKER = g++

#
#   Compiler and linker flags
#
#   This variable holds the flags that are passed to the compiler. By default, 
#   we include the -O2 flag. This flag tells the compiler to optimize the code, 
#   but it makes debugging more difficult. So if you're debugging your application, 
#   you probably want to remove this -O2 flag. At the same time, you can then 
#   add the -g flag to instruct the compiler to include debug information in
#   the library (but this will make the final libphpcpp.so file much bigger, so
#   you want to leave that flag out on production servers).
#
#   If your extension depends on other libraries (and it does at least depend on
#   one: the PHP-CPP library), you should update the LINKER_DEPENDENCIES variable
#   with a list of all flags that should be passed to the linker.
#

QT_FLAGS            = -I/opt/homebrew/lib/QtWebEngineWidgets.framework/Headers -I/opt/homebrew/lib/QtWebEngineWidgets.framework -DQT_WEBENGINEWIDGETS_LIB -I/opt/homebrew/lib/QtWebEngineCore.framework/Headers -I/opt/homebrew/lib/QtWebEngineCore.framework -DQT_WEBENGINECORE_LIB -I/opt/homebrew/lib/QtQuick.framework/Headers -I/opt/homebrew/lib/QtQuick.framework -DQT_QUICK_LIB -I/opt/homebrew/lib/QtQmlModels.framework/Headers -I/opt/homebrew/lib/QtQmlModels.framework -DQT_QMLMODELS_LIB -I/opt/homebrew/lib/QtOpenGL.framework/Headers -I/opt/homebrew/lib/QtOpenGL.framework -DQT_OPENGL_LIB -I/opt/homebrew/lib/QtWebChannel.framework/Headers -I/opt/homebrew/lib/QtWebChannel.framework -DQT_WEBCHANNEL_LIB -I/opt/homebrew/lib/QtQml.framework/Headers -I/opt/homebrew/lib/QtQml.framework -DQT_QML_LIB -I/opt/homebrew/include/QtQmlIntegration -I/opt/homebrew/include -DQT_QMLINTEGRATION_LIB -I/opt/homebrew/lib/QtNetwork.framework/Headers -I/opt/homebrew/lib/QtNetwork.framework -DQT_NETWORK_LIB -I/opt/homebrew/lib/QtPositioning.framework/Headers -I/opt/homebrew/lib/QtPositioning.framework -DQT_POSITIONING_LIB -I/opt/homebrew/lib/QtPrintSupport.framework/Headers -I/opt/homebrew/lib/QtPrintSupport.framework -DQT_PRINTSUPPORT_LIB -I/opt/homebrew/lib/QtWidgets.framework/Headers -I/opt/homebrew/lib/QtWidgets.framework -DQT_WIDGETS_LIB -I/opt/homebrew/lib/QtGui.framework/Headers -I/opt/homebrew/lib/QtGui.framework -DQT_GUI_LIB -I/opt/homebrew/lib/QtCore.framework/Headers -I/opt/homebrew/lib/QtCore.framework -DQT_CORE_LIB -I/opt/homebrew/share/qt/mkspecs/macx-clang -F/opt/homebrew/lib -framework QtWebEngineWidgets -framework QtWebEngineCore -framework QtQuick -framework QtQmlModels -framework QtOpenGL -framework QtWebChannel -framework QtQml -framework QtNetwork -framework QtPositioning -framework QtPrintSupport -framework QtWidgets -framework QtGui -framework QtCore
COMPILER_FLAGS      =   -Wall -c -O2 -std=c++17 -fpic -v
LINKER_FLAGS        =   -shared -v
LINKER_DEPENDENCIES =   -lphpcpp

COMPILER_FLAGS     += ${QT_FLAGS} -o
LINKER_FLAGS       += ${QT_FLAGS}

#
#   Command to remove files, copy files and create directories.
#
#   I've never encountered a *nix environment in which these commands do not work. 
#   So you can probably leave this as it is
#

RM    = rm -f
CP    = cp -f
MKDIR = mkdir -p

#
#   All source files are simply all *.cpp files found in the current directory
#
#   A built-in Makefile macro is used to scan the current directory and find 
#   all source files. The object files are all compiled versions of the source
#   file, with the .cpp extension being replaced by .o.
#

SOURCES             =   $(wildcard *.cpp)
SOURCES				+= $(wildcard ./src/*/*.cpp)
OBJECTS             =   $(SOURCES:%.cpp=%.o)

#
#   From here the build instructions start
#

all:                    ${OBJECTS} ${EXTENSION}

${EXTENSION}:			${OBJECTS}
						${LINKER} ${LINKER_FLAGS} -o $@ ${OBJECTS} ${LINKER_DEPENDENCIES}

${OBJECTS}:
						${COMPILER} ${COMPILER_FLAGS} $@ ${@:%.o=%.cpp}

install:        
						${CP} ${EXTENSION} ${EXTENSION_DIR}
						${CP} ${INI} ${INI_DIR}

clean:
						${RM} ${EXTENSION} ${OBJECTS}