.PHONY: clean

TARGET = proc
EXEC = ../stk/exec.se
SRCS = ../tools/list.c ../tools/stack.c ./s_register.c ./s_proc.c
OBJS = $(foreach path, $(SRCS), $(patsubst %.c, %.o, $(join $(join $(dir $(path)), bin/), $(notdir $(path)))))
HEADERS = $(SRCS:.c=.h) $(wildcard ../s_common/*.h)


$(TARGET): $(OBJS)
	g++ -o ./bin/$@ $^
%.o: ../%.c $(HEADERS)
	g++ -c -o $@ $<
run:
	./bin/proc $(EXEC)
clean:
	rm $(OBJS) ./bin/$(TARGET)
test:
	echo $(OBJS)

