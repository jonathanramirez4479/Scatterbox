CC = g++
CFLAGS = -Wall -g
TARGET = main

$(TARGET): main.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp

clean:
	rm -f $(TARGET)
