CC			= g++
SOURCES 	= cgrafos.cc cnodos.cc GCPAlgorithms.cc GreedyAlgorithm.cc LocalSearch.cc
LDFLAGS	= -c
CFLAGS	= -Wall -std=c++11 -g -Wdelete-non-virtual-dtor
PROGRAM	= main
OBJECTS	= (SOURCES: .cc = .o)
GREEDYDEPEND = cnodos.o genericGraph.o cgrafos.o Experiment.o GCPAlgorithms.o GreedyAlgorithm.o
DSATURDEPEND = DSatur.o Experiment.o genericGraph.o GCPAlgorithmsDSatur.o cgrafoDSatur.o cnodosDSatur.o
BIDEPEND = BestImprovement.o Experiment.o Improvement.o genericGraph.o cgrafosBI.o cnodos.o cnodosBI.o
FIDEPEND = FirstImprovement.o Experiment.o Improvement.o genericGraph.o cgrafosBI.o cnodos.o cnodosBI.o
RANDOMWALK = Experiment.o GCPAlgorithms.o LocalSearch.o RandomWalk.o cgrafos.o genericGraph.o cnodos.o
RANDOMSAMPLING = Experiment.o GCPAlgorithms.o LocalSearch.o RandomSampling.o cgrafos.o genericGraph.o cnodos.o

all : $(PROGRAM)

genericGraph.o :  genericGraph.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) genericGraph.cc

cgrafos.o : genericGraph.o cgrafos.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafos.cc

cgrafoDSatur.o : genericGraph.o cnodosDSatur.o cgrafoDSatur.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafoDSatur.cc

cgrafosBI.o : genericGraph.o cnodosBI.o cgrafosBI.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) cgrafosBI.cc

cnodos.o : cnodos.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) cnodos.cc

cnodosDSatur.o : cnodosDSatur.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) cnodosDSatur.cc

cnodosBI.o : cnodos.o cnodosBI.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) cnodosBI.cc

GCPAlgorithms.o : GCPAlgorithms.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) GCPAlgorithms.cc

Experiment.o : Experiment.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) Experiment.cc

Improvement.o : Improvement.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) Improvement.cc

FirstImprovement.o : FirstImprovement.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) FirstImprovement.cc

GCPAlgorithmsDSatur.o : GCPAlgorithmsDSatur.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) GCPAlgorithmsDSatur.cc

GreedyAlgorithm.o : GreedyAlgorithm.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) GreedyAlgorithm.cc

LocalSearch.o : LocalSearch.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) LocalSearch.cc

DSatur.o : DSatur.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) DSatur.cc

RandomWalk.o : RandomWalk.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) RandomWalk.cc

RandomSampling.o : RandomSampling.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) RandomSampling.cc

BestImprovement.o : BestImprovement.cc ../include/registers.h
	$(CC) $(LDFLAGS) $(CFLAGS) BestImprovement.cc

greedy : $(GREEDYDEPEND) ../include/registers.h
	$(CC) $(CFLAGS) $(GREEDYDEPEND) maingreedy.cc -o $(PROGRAM)

dsatur : $(DSATURDEPEND) maindsatur.cc ../include/registers.h
	g++ $(CFLAGS) $(DSATURDEPEND) maindsatur.cc -o $(PROGRAM)

bi : $(BIDEPEND) mainbi.cc ../include/registers.h
	g++ $(CFLAGS) $(BIDEPEND) mainbi.cc -o $(PROGRAM)

fi : $(FIDEPEND) mainfi.cc ../include/registers.h
	g++ $(CFLAGS) $(FIDEPEND) mainfi.cc -o $(PROGRAM)

rwalk : $(RANDOMWALK) mainrwalk.cc ../include/registers.h
	g++ $(CFLAGS) $(RANDOMWALK) mainrwalk.cc -o $(PROGRAM)

rsampling : $(RANDOMSAMPLING) mainsampling.cc ../include/registers.h
	g++ $(CFLAGS) $(RANDOMSAMPLING) mainsampling.cc -o $(PROGRAM)

clean :
	rm *.o $(PROGRAM)
