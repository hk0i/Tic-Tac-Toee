CXX=g++
SOURCE=../tttboard.cpp main.cpp
OBJS:=$(SOURCE:.cpp=.o)

test: $(OBJS)
	$(CXX) -o test $(OBJS)

main.o: tttboard.o
	$(CXX) -c main.cpp -o main.o

tttboard.o:
	$(CXX) -c ../tttboard.cpp -o ../tttboard.o


clean:
	rm -rf $(OBJS) test
