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

lib: build libresistance libpower libcomponent

libresistance:
	$(CC) $(LIBFLAGS) $(LDFLAGS) $(SRC_PATH)/$@.c -o $(BUILD_PATH)/$@.so

libpower:
	$(CC) $(LIBFLAGS) $(LDFLAGS) $(SRC_PATH)/$@.c -o $(BUILD_PATH)/$@.so
	
libcomponent:
	$(CC) $(LIBFLAGS) $(LDFLAGS) $(SRC_PATH)/$@.c -o $(BUILD_PATH)/$@.so

electrotest:
	$(CC) $(SRC_PATH)/$@.c $(CFLAGS) $(BUILDFLAGS) -o $(BUILD_PATH)/$@

install:
	cp $(BUILD_PATH)/*.so $(LIB_DIR)
	cp $(INC_PATH)/*.h $(INCLUDE_DIR)

uninstall:
	rm $(LIB_DIR)/libcomponent.so
	rm $(INCLUDE_DIR)/libcomponent.so
	rm $(LIB_DIR)/libresistance.so
	rm $(INCLUDE_DIR)/libresistance.h
	rm $(LIB_DIR)/libpower.so
	rm $(INCLUDE_DIR)/libpower.so

clean:
	rm $(BUILD_PATH)/*

build:
	mkdir -p $@
