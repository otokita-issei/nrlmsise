PREFIX = $(HOME)
LIB_DIR = $(PREFIX)/lib
INC_DIR = $(PREFIX)/include

OBJS = main.o nrlmsise.o nz_1.o integral.o beta.o
HEADERS = optical_depth.h nrlmsise-00.h
LIB_OPTS = -Wl,-R$(LIB_DIR)

.PHONY: all clean install

main: $(OBJS)
	g++ -o $@ $(OBJS) $(LIB_OPTS) -L$(LIB_DIR) -lnrlmsise_20

%.o: %.cpp $(HEADERS)
	g++ -c $< -Wall -O3 -I(INC_DIR)

clean:
	rm -f *.o $(TARGET) main
