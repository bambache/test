CPP = g++
CPPFLAGS = `wx-config --cxxflags`
LIBS = `wx-config --libs`
OFLAG = -o
PROGNAME = test

.SUFFIXES : .o .cpp
.cpp.o :
	$(CPP) $(CPPFLAGS) -c $<

all: MyApp

MyApp: MyApp.o MyFrame.o
	$(CPP) MyApp.o MyFrame.o $(LIBS) $(OFLAG) $(PROGNAME)

clean:
	rm -rf *.o *.exe
