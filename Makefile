CC = gcc
CFLAGS = -Wall
MY_GRAPH = my_graph
MY_KNAPSACK = my_Knapsack

my_graph: my_graph.c my_mat.c
	$(CC) $(CFLAGS) -o $@ $^

my_Knapsack: my_knapsack.c
	$(CC) $(CFLAGS) -o $@ $^

all: my_graph my_Knapsack

clean:
	rm -f $(MY_GRAPH) $(MY_KNAPSACK)