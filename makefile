DEBUG = yes
PROFILE = no
PEDANTIC = no
OPTIMIZATION = -O3

CC = gcc
LD = gcc

CFLAGS = -pipe -lm
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wno-unused-result
CFLAGS += -Werror# all warnings are ERRORS
CFLAGS += -Wuninitialized
CFLAGS += -Winit-self
CFLAGS += -Werror-implicit-function-declaration


ifeq ($(DEBUG), yes)
	CFLAGS += -g
	OPTIMIZATION = -O0
endif

ifeq ($(PROFILE), yes)
	CFLAGS += -pg
endif

OPTIMIZATION = -O0 
CFLAGS += $(OPTIMIZATION)

OFLAGS = -c -I/usr/include

LFLAGS = $(CFLAGS) -L/usr/lib/

OBJ_DIR = obj
LIB_DIR = lib
BIN_DIR = .
INC_DIR = .

SOURCE_FILES = $(wildcard *.c)
OBJ_FILES = $(SOURCE_FILES:.c=.o)


OBJ_DIR_FILES = $(addprefix obj/, $(OBJ_FILES))

all: pann

pann: $(OBJ_DIR_FILES)
	$(info ------BUILDING----------)
	$(CC) $(OBJ_DIR_FILES) $(CFLAGS) -o pann

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(info ------CLEANING----------)
	rm -rf $(OBJ_DIR)/*.o pann

rebuild: clean all

.PHONY : clean
.SILENT : clean

