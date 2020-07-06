target := sort
objs := sort.o
deps := $(objs:%.o=.%.o.d)
CC := gcc
CFLAGS := -g


all: $(target)


$(target): $(objs)
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c -MMD -MF .$@.d $<


.PHONY: clean
clean:
	-rm -f $(target) $(objs)

-include $(deps)
