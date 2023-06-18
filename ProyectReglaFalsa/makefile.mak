CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

SRCS = Proyecto_ReglaFalsa.cpp ReglaFalsa.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = proyecto_regla_falsa

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

Proyecto_ReglaFalsa.o: Proyecto_ReglaFalsa.cpp ReglaFalsa.h colors.h
	$(CXX) $(CXXFLAGS) -c Proyecto_ReglaFalsa.cpp -o Proyecto_ReglaFalsa.o

ReglaFalsa.o: ReglaFalsa.cpp ReglaFalsa.h colors.h
	$(CXX) $(CXXFLAGS) -c ReglaFalsa.cpp -o ReglaFalsa.o

clean:
	rm -f $(OBJS) $(TARGET)

