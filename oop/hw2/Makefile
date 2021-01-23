DEPS = main.o game.o software.o movie.o torrent.o server.o

all: ${DEPS}
	g++ ${DEPS} -o torrent_server

%.o: %.cpp
	g++ -Wall -c $< -o $@

clean:
	rm -f a.out torrent_server *.o
