CC = g++
CFLAGS = -g -O2 -Wall -std=c++17

all: fraction.o big_number.o big_number_test fraction_test

clean:
	rm fraction.o big_number.o big_number_test fraction_test

fraction.o: fraction.cpp fraction.h
	$(CC) $(CFLAGS) -c fraction.cpp

big_number.o: big_number.cpp big_number.h
	$(CC) $(CFLAGS) -c big_number.cpp

fraction_test: fraction.o fraction_test.cpp
	$(CC) $(CFLAGS) fraction.o fraction_test.cpp -o fraction_test

big_number_test: big_number.o big_number_test.cpp
	$(CC) $(CFLAGS) big_number.o big_number_test.cpp -o big_number_test
