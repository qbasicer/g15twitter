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
OBJFILES      = g15twitter.o CanvasManager.o AnimationManager.o VirtualCanvas.o G15Widget.o G15TextLabel.o SampleTwitterScreen.o \
				G15TitleBar.o G15StandardLayout.o G15Inputtable.o G15Button.o Animation.o AnimationGroup.o AnimationSequence.o

all: g15twitter

prepare: clean cleanse

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

G15TextLabel.o: src/G15TextLabel.cpp include/G15TextLabel.hpp
	$(CXX) -c src/G15TextLabel.cpp -o G15TextLabel.o $(CXXFLAGS) $(INCPATH)

G15TitleBar.o: src/G15TitleBar.cpp include/G15TitleBar.hpp
	$(CXX) -c src/G15TitleBar.cpp -o G15TitleBar.o $(CXXFLAGS) $(INCPATH)

G15StandardLayout.o: src/G15StandardLayout.cpp include/G15StandardLayout.hpp
	$(CXX) -c src/G15StandardLayout.cpp -o G15StandardLayout.o $(CXXFLAGS) $(INCPATH)

G15Inputtable.o: src/G15Inputtable.cpp include/G15Inputtable.hpp
	$(CXX) -c src/G15Inputtable.cpp -o G15Inputtable.o $(CXXFLAGS) $(INCPATH)

G15Button.o: src/G15Button.cpp include/G15Button.hpp
	$(CXX) -c src/G15Button.cpp -o G15Button.o $(CXXFLAGS) $(INCPATH)

SampleTwitterScreen.o: src/SampleTwitterScreen.cpp include/SampleTwitterScreen.hpp
	$(CXX) -c src/SampleTwitterScreen.cpp -o SampleTwitterScreen.o $(CXXFLAGS) $(INCPATH)

Animation.o: src/Animation.cpp include/Animation.hpp
	$(CXX) -c src/Animation.cpp -o Animation.o $(CXXFLAGS) $(INCPATH)

AnimationGroup.o: src/AnimationGroup.cpp include/AnimationGroup.hpp
	$(CXX) -c src/AnimationGroup.cpp -o AnimationGroup.o $(CXXFLAGS) $(INCPATH)

AnimationSequence.o: src/AnimationSequence.cpp include/AnimationSequence.hpp
	$(CXX) -c src/AnimationSequence.cpp -o AnimationSequence.o $(CXXFLAGS) $(INCPATH)