.PHONY: clean

TARGET = asm
SOURCE = ../stk/source.s
EXEC = ../stk/exec.se
SRCS = ../tools/vararray.c ./s_asm.c
OBJS = $(foreach path, $(SRCS), $(patsubst %.c, %.o, $(join $(join $(dir $(path)), bin/), $(notdir $(path)))))
HEADERS = $(SRCS:.c=.h) $(wildcard ../s_common/*.h)


$(TARGET): $(OBJS)
	g++ -o ./bin/$@ $^
%.o: ../%.c $(HEADERS)
	g++ -c -o $@ $<
compile:
	./bin/$(TARGET) $(SOURCE) $(EXEC)
clean:
	rm $(OBJS) ./bin/$(TARGET)
test:
	echo $(OBJS)

