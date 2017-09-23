INC_PATH=./src
SRC_PATH=./src
BUILD_PATH=build
CC=gcc
LIBFLAGS=-fPIC -Wall -Wextra -O2 -g
CFLAGS=-I$(INC_PATH) -O3
LDFLAGS=-shared
BUILDFLAGS=-Lbuild -lresistance -lpower -lcomponent -Wl,-rpath,$(BUILD_PATH)
EXECUTABLE=electrotest
LIB_DIR=/usr/local/lib
INCLUDE_DIR=/usr/local/include

# Lägger alla binärer i ./build
# installerar biblioteken och headerfiler till
# /usr/local/lib och /usr/local/include respektive

all: lib electrotest
.PHONY: all

lib: build libresistance libpower libcomponent

libresistance:

libpower:

libcomponent:
	$(CC) $(LIBFLAGS) $(LDFLAGS) $(SRC_PATH)/libcomponent.c -o $(BUILD_PATH)/libcomponent.so

electrotest:
	$(CC) $(SRC_PATH)/electrotest.c $(CFLAGS) $(BUILDFLAGS) -o $(BUILD_PATH)/electrotest

install:
	cp $(BUILD_PATH)/*.so $(LIB_DIR)
	cp $(INC_PATH)/*.h $(INCLUDE_DIR)

clean:
	rm $(BUILD_PATH)/*

build:
	mkdir -p $@
