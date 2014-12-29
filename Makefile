CC=clang++
CFLAGS = -std=c++11 -c -Wall -fPIC -g
LDFLAGS =
LIBS = -L /usr/local/lib -lImath -lIex -L/usr/local/dist/linux64/lib
SOURCES=$(wildcard src/*.cpp)
BOOST_INC = /usr/include
BOOST_LIB = /usr/lib
INCLUDES = -I ./include -I/usr/local/dist/linux64/include -I/usr/local/include
LIB_VERSION = 0.1.0
OBJECTS=$(SOURCES:.cpp=.o)
LIBBASENAME=libcoloring
STATICLIBNAME=$(LIBBASENAME).$(LIB_VERSION).a
STATICLIB=lib/$(STATICLIBNAME)
STATICSIMLIB=$(LIBBASENAME).a
MKDIR_P = mkdir -p

.PHONY : makelib

all: makelib $(SOURCES) $(OBJECTS) $(STATICLIB).$(LIB_VERSION)

makelib:
	mkdir -p lib

%.o: %.cpp
	$(CC) $(INCLUDES)  -o $@ $< $(CFLAGS)

$(STATICLIB).$(LIB_VERSION): $(OBJECTS)
	ar rvs $(STATICLIB) $(OBJECTS)
	ln -f -s $(LIBBASENAME).$(LIB_VERSION).a $(STATICSIMLIB)
	mv $(STATICSIMLIB) lib/$(STATICSIMLIB)

clean:
	rm -fr $(OBJECTS)
	rm -fr $(STATICLIB)
	rm -fr lib
