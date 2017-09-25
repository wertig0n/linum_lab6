INC_PATH=./src
SRC_PATH=./src
BUILD_PATH=lib
CC=gcc
LIBFLAGS=-fPIC -Wall -Wextra -O2 -g
CFLAGS=-I$(INC_PATH) -O3
LDFLAGS=-shared
BUILDFLAGS=-Llib -lresistance -lpower -lcomponent -Wl,-rpath,$(BUILD_PATH)
INSTALLFLAGS=-L$(LIB_DIR) -lresistance -lpower -lcomponent -Wl,-rpath,$(LIB_DIR)
EXECUTABLE=electrotest
LIB_DIR=/usr/local/lib
INCLUDE_DIR=/usr/local/include
INSTALL_DIR=/usr/local/bin

# Lägger alla binärer i ./lib
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
	$(CC) $(SRC_PATH)/$@.c $(CFLAGS) $(BUILDFLAGS) -o ./$@

install:
	cp $(BUILD_PATH)/*.so $(LIB_DIR)
#	cp $(INC_PATH)/*.h $(INCLUDE_DIR)
	$(CC) $(SRC_PATH)/electrotest.c $(CFLAGS) $(INSTALLFLAGS) -o $(INSTALL_DIR)/electrotest

uninstall:
	rm $(LIB_DIR)/libcomponent.so
#	rm $(INCLUDE_DIR)/libcomponent.h
	rm $(LIB_DIR)/libresistance.so
#	rm $(INCLUDE_DIR)/libresistance.h
	rm $(LIB_DIR)/libpower.so
#	rm $(INCLUDE_DIR)/libpower.h
	rm $(INSTALL_DIR)/electrotest

clean:
	rm -R $(BUILD_PATH)*
	rm ./electrotest

build:
	mkdir -p lib
