OBJS = main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG) `pkg-config --cflags opencv`
LFLAGS = -Wall $(DEBUG) -ljpeg -lcurl `pkg-config --libs opencv`

electricity-monitoring-opencv: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o electricity-monitoring-opencv

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

clean:
	rm *.o *~ electricity-monitoring-opencv *.jpg
