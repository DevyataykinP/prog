TARGET = ./main
HDRS_DIR = \
		src
SRCS = \
		src/main.c \
		src/coder.c \
		src/command.c
.PHONY: all, build, clean

$(TARGET):
		gcc -Wall -Werror -I $(HDRS_DIR) $(SRCS) -o $(TARGET)

all: clean build

build: $(TARGET)

clean:
		rm -rf $(TARGET)