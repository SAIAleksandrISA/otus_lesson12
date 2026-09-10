.PHONY: all clean

all: bin/mapper bin/reducer_mean bin/reducer_variance

bin/mapper: mapper.cpp
	if not exist bin mkdir bin
	g++ -o $@ mapper.cpp

bin/reducer_mean: reducer_mean.cpp
	if not exist bin mkdir bin
	g++ -o $@ reducer_mean.cpp

bin/reducer_variance: reducer_variance.cpp
	if not exist bin mkdir bin
	g++ -o $@ reducer_variance.cpp

clean:
	rm -rf bin output