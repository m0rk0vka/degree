CC = g++
CFLAGS = -g -O2 -Wall -std=c++11

all: fraction.o big_number.o big_number_test fraction_test

clean:
	rm fraction.o big_number.o str.o big_number_test fraction_test str_test

fraction.o: fraction.cpp fraction.h
	$(CC) $(CFLAGS) -c fraction.cpp

big_number.o: big_number.cpp big_number.h
	$(CC) $(CFLAGS) -c big_number.cpp

str.o: str.cpp str.h
	$(CC) $(CFLAGS) -c str.cpp

fraction_test: fraction.o big_number.o str.o fraction_test.cpp
	$(CC) $(CFLAGS) fraction.o big_number.o str.o fraction_test.cpp -o fraction_test

big_number_test: big_number.o str.o big_number_test.cpp
	$(CC) $(CFLAGS) big_number.o str.o big_number_test.cpp -o big_number_test

str_test: str.o str_test.cpp
	$(CC) $(CFLAGS) str.o str_test.cpp -o str_test
