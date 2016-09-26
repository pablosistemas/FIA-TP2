CC			= g++
SOURCES 	= cgrafos.cc cnodos.cc GCPAlgorithms.cc GreedyAlgorithm.cc LocalSearch.cc
LDFLAGS	= -c
CFLAGS	= -Wall -std=c++11 -g
PROGRAM	= main
OBJECTS	= (SOURCES: .cc = .o)
MAINDEPEND = cnodos.o genericGraph.o cgrafos.o GCPAlgorithms.o GreedyAlgorithm.o LocalSearch.o RandomWalk.o

all : $(PROGRAM) 

genericGraph.o :  genericGraph.cc 
	$(CC) $(LDFLAGS) $(CFLAGS) genericGraph.cc

cgrafos.o : genericGraph.o cgrafos.cc 
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafos.cc

#cgrafosDSatur.o : genericGraph.o cgrafosDSatur.cc 
#	$(CC) $(LDFLAGS) $(CFLAGS) cgrafosDSatur.cc

cnodos.o : cnodos.cc	
	$(CC) $(LDFLAGS) $(CFLAGS) cnodos.cc

cnodosDSatur.o : cnodosDSatur.cc	
	$(CC) $(LDFLAGS) $(CFLAGS) cnodosDSatur.cc

GCPAlgorithms.o : GCPAlgorithms.cc
	$(CC) $(LDFLAGS) $(CFLAGS) GCPAlgorithms.cc

GreedyAlgorithm.o : GreedyAlgorithm.cc
	$(CC) $(LDFLAGS) $(CFLAGS) GreedyAlgorithm.cc

LocalSearch.o : LocalSearch.cc
	$(CC) $(LDFLAGS) $(CFLAGS) LocalSearch.cc

RandomWalk.o : RandomWalk.cc
	$(CC) $(LDFLAGS) $(CFLAGS) RandomWalk.cc

$(PROGRAM) : $(MAINDEPEND)
	$(CC) $(CFLAGS) $(MAINDEPEND) main.cc -o $(PROGRAM)

dsatur : cnodosDSatur.o cgrafoDSatur.o genericGraph.o maindsatur.cc 
	g++ $(CFLAGS) cnodos.o cgrafoDSatur.o genericGraph.o maindsatur.cc -o $(PROGRAM)

clean :
	rm *.o $(PROGRAM)
