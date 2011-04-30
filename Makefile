CXX=g++
CXX_FLAGS=`sdl-config --cflags` -g -Wall
CXX_LIBS =`sdl-config --libs` -lSDL_image
SOURCES:=$(wildcard *.cpp)
OBJS:=$(SOURCES:.cpp=.o)

tictactoe: $(OBJS)
	$(CXX) -o tictactoe $(OBJS) $(CXX_LIBS)

$(OBJS): $(SOURCES)
	$(CXX) -c $(SOURCES) $(CXX_FLAGS)

debug:
	@echo sources: $(SOURCES)
	@echo objs: $(OBJS)

clean:
	rm -rf $(OBJS) tictactoe


