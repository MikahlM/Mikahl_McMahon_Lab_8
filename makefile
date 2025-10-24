# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Targets
all: Football_scores Temperature

Football_scores: Football_scores.c
	$(CC) $(CFLAGS) -o Football_scores Football_scores.c

Temperature: Temperature.c
	$(CC) $(CFLAGS) -o Temperature Temperature.c

clean:
	rm -f Football_scores Temperature