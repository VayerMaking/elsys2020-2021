DEPS = main.o mine.o worker.o mine_company.o basic_worker.o greedy_worker.o antisocial_worker.o

all: ${DEPS}
	g++ ${DEPS} -o kontrolno2

%.o: %.cpp
	g++ -Wall -c $< -o $@

clean:
	rm -f a.out kontrolno2 *.o
