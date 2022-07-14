PREFIX = $(HOME)
LIB_DIR = $(PREFIX)/lib
INC_DIR = $(PREFIX)/include

OBJS = main.o nrlmsise.o nz_1.o integral.o beta.o
LIB_OPTS = -Wl,-R$(LIB_DIR)

.PHONY: all clean

main: $(OBJS)
	g++ -o $@ $(OBJS) $(LIB_OPTS) -L$(LIB_DIR) -lnrlmsise_20

%.o: %.cpp optical_depth.h
	g++ -c $< -Wall -O3 -I$(INC_DIR)

clean:
	rm -f *.o main
