CC			= g++
SOURCES 	= cgrafos.cc cnodos.cc GCPAlgorithms.cc GreedyAlgorithm.cc LocalSearch.cc
LDFLAGS	= -c
CFLAGS	= -Wall -std=c++11 -g
PROGRAM	= main
OBJECTS	= (SOURCES: .cc = .o)
MAINDEPEND = cnodos.o genericGraph.o cgrafos.o GCPAlgorithms.o GreedyAlgorithm.o LocalSearch.o RandomWalk.o
DSATURDEPEND = DSatur.o genericGraph.o GCPAlgorithmsDSatur.o cgrafoDSatur.o cnodosDSatur.o
BIDEPEND = BestImprovement.o genericGraph.o cgrafosBI.o cnodos.o cnodosBI.o

all : $(PROGRAM) 

genericGraph.o :  genericGraph.cc 
	$(CC) $(LDFLAGS) $(CFLAGS) genericGraph.cc

cgrafos.o : genericGraph.o cgrafos.cc 
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafos.cc

cgrafoDSatur.o : genericGraph.o cnodosDSatur.o cgrafoDSatur.cc 
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafoDSatur.cc

cgrafosBI.o : genericGraph.o cnodosBI.o cgrafosBI.cc 
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafosBI.cc

cnodos.o : cnodos.cc	
	$(CC) $(LDFLAGS) $(CFLAGS) cnodos.cc

cnodosDSatur.o : cnodosDSatur.cc	
	$(CC) $(LDFLAGS) $(CFLAGS) cnodosDSatur.cc

cnodosBI.o : cnodos.o cnodosBI.cc	
	$(CC) $(LDFLAGS) $(CFLAGS) cnodosBI.cc

GCPAlgorithms.o : GCPAlgorithms.cc
	$(CC) $(LDFLAGS) $(CFLAGS) GCPAlgorithms.cc

GCPAlgorithmsDSatur.o : GCPAlgorithmsDSatur.cc
	$(CC) $(LDFLAGS) $(CFLAGS) GCPAlgorithmsDSatur.cc

GreedyAlgorithm.o : GreedyAlgorithm.cc
GreedyAlgorithm.o : GreedyAlgorithm.cc
	$(CC) $(LDFLAGS) $(CFLAGS) GreedyAlgorithm.cc

LocalSearch.o : LocalSearch.cc
	$(CC) $(LDFLAGS) $(CFLAGS) LocalSearch.cc

DSatur.o : DSatur.cc
	$(CC) $(LDFLAGS) $(CFLAGS) DSatur.cc

RandomWalk.o : RandomWalk.cc
	$(CC) $(LDFLAGS) $(CFLAGS) RandomWalk.cc

BestImprovement.o : BestImprovement.cc
	$(CC) $(LDFLAGS) $(CFLAGS) BestImprovement.cc

$(PROGRAM) : $(MAINDEPEND)
	$(CC) $(CFLAGS) $(MAINDEPEND) main.cc -o $(PROGRAM)

dsatur : $(DSATURDEPEND) maindsatur.cc 
	g++ $(CFLAGS) $(DSATURDEPEND) maindsatur.cc -o $(PROGRAM)

bi : $(BIDEPEND) mainbi.cc 
	g++ $(CFLAGS) $(BIDEPEND) mainbi.cc -o $(PROGRAM)

clean :
	rm *.o $(PROGRAM)
