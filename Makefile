EXEC= unnamed.out
SOURCE=$(wildcard src/*.cpp)
OBJ=$(subst .cpp,.o,$(subst src,bin,$(SOURCE)))

CC = g++
CC_FLAGS= `wx-config --cxxflags` -c
LINK_FLAGS= `wx-config --libs`

all: obj_folder $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LINK_FLAGS)

bin/%.o: src/%.cpp src/%.h
	$(CC) $< $(CC_FLAGS) -o $@

bin/main.o: src/main.cpp $(SOURCE)
	$(CC) $< $(CC_FLAGS) -o $@

obj_folder:
	@ mkdir -p bin

clean:
	@ rm -rf bin/*.o $(EXEC) *~
	@ rmdir bin

.PHONY: all clean