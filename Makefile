# g15twitter makefile - handcrafted by QBasicer

C             = gcc
CXX           = g++
DEFINES       = 
CFLAGS        = -g -pipe -march=native -O2 -pipe -fno-ident -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS	  = $(CFLAGS)
INCPATH       = -Iinclude
LIBS          = -lg15render -lg15daemon_client
LINK          = g++
LFLAGS        = -Wl,-O1
OBJFILES      = g15twitter.o CanvasManager.o AnimationManager.o VirtualCanvas.o G15Widget.o

all: g15twitter

clean:
	rm -rvf *.o
	rm -rvf g15twitter

cleanse:
	rm -rvf src/*~
	rm -rvf include/*~
	rm -rvf *~

g15twitter: $(OBJFILES)
	$(LINK) $(OBJFILES) -o g15twitter $(LIBS) $(LFLAGS)
	
g15twitter.o: src/g15twitter.cpp
	$(CXX) -c src/g15twitter.cpp -o g15twitter.o $(CXXFLAGS) $(INCPATH)

CanvasManager.o: src/CanvasManager.cpp include/CanvasManager.hpp
	$(CXX) -c src/CanvasManager.cpp -o CanvasManager.o $(CXXFLAGS) $(INCPATH)

AnimationManager.o: src/AnimationManager.cpp include/AnimationManager.hpp
	$(CXX) -c src/AnimationManager.cpp -o AnimationManager.o $(CXXFLAGS) $(INCPATH)

VirtualCanvas.o: src/VirtualCanvas.cpp include/VirtualCanvas.hpp
	$(CXX) -c src/VirtualCanvas.cpp -o VirtualCanvas.o $(CXXFLAGS) $(INCPATH)

G15Widget.o: src/G15Widget.cpp include/G15Widget.hpp
	$(CXX) -c src/G15Widget.cpp -o G15Widget.o $(CXXFLAGS) $(INCPATH)