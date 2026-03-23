CXX=g++
CXXFLAGS=-std=c++17
TARGET=movie
SRCS=main.cpp Movie.cpp

$(TARGET):$(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)