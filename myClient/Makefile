TARGET = client
COMP = g++

PREF_OBJ = ./obj/
VPATH = ..

SRC = $(wildcard *.cpp) $(wildcard ../*.cpp)
OBJ = $(addprefix $(PREF_OBJ), $(notdir $(SRC:.cpp=.o)))

$(TARGET): $(OBJ)
	$(COMP) $^ -o $@

$(PREF_OBJ)%.o: %.cpp | obj_dir
	$(COMP) -c $< -o $@ -I..

obj_dir:
	mkdir -p $(PREF_OBJ)

.PHONY: clean

clean:
	rm -f $(TARGET) $(PREF_OBJ)*.o
