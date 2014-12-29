CC=clang++
CFLAGS  = -g -Wall -Weffc++ -std=c++11
SOURCES = $(wildcard *.cpp)
LDFLAGS = -L ../lib/ /usr/local/lib -L/usr/local/dist/linux64/lib
INCLUDES = -I ../include/ -I /usr/local/include -I/usr/local/dist/linux64/include -I/usr/local/include
EXECUTABLE = grapher

all: $(EXECUTABLE)

.PHONY : $(EXECUTABLE)
$(EXECUTABLE):
	$(CC) $(CFLAGS) $(SOURCES) $(INCLUDES) $(LDFLAGS) -o $@

.PHONY : clean
clean:
	rm -fr $(EXECUTABLE)
