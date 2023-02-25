CC=g++
CFLAGS= 

OPTFLAGS =-O3

TARGET = MPS_SOLVER.o mps
.PHONY: all clean

all:



mps: src/mps.cpp src/mps_solver.o
      $(CC) $(CFLAGS) $(OPTFLAGS) $(LDFLAGS) $^ -o $@
	  @echo "done ."
mps_solver.o :

clean:
