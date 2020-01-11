PROG = a
CC = g++
CPPFLAGS = -I../bcm/src/libbcm2835
LDFLAGS = -lbcm2835
OBJS = eindopdracht.o

$(PROG) : $(OBJS)
		$(CC) $(LDFLAGS) -o $(PROG) $(OBJS)
main.o :
		$(CC) $(CPPFLAGS) -c eindopdracht.cpp
clean :
		rm -f core $(PROG) $(OBJS)