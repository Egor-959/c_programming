CC := gcc

FLAGS := -std=c99 -Werror  -Wpedantic -Wextra 

SRC := $(wildcard *.c)
OBJ := $(SRC:%.c=%.o)

.PHONY: run build clean

run:
	./app.exe

build: app.exe
	./app.exe

clean:
	rm $(OBJ_PATH)/*.o *.exe

app.exe: $(OBJ)
	$(CC) $^ -o $@  --coverage -lm

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $<