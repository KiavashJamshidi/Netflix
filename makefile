CC = g++
FLAGS = -std=c++11
COMPILE_FLAGS = $(FLAGS) -c

a.out: main.o netflix.o user.o film.o comment.o exception.h hash.h publisher.o defines.h
	$(CC) main.o netflix.o user.o film.o comment.o exception.h hash.h publisher.o defines.h $(FLAGS) -o a.out

main.o: main.cpp netflix.h defines.h
	$(CC) $(COMPILE_FLAGS) main.cpp

NetflixSystem.o: netflix.cpp netflix.h user.h hash.h defines.h
	$(CC) $(COMPILE_FLAGS) netflix.cpp

user.o: user.cpp user.h film.h 
	$(CC) $(COMPILE_FLAGS) user.cpp

film.o: film.cpp film.h comment.h
	$(CC) $(COMPILE_FLAGS) film.cpp

comment.o: comment.cpp comment.h
	$(CC) $(COMPILE_FLAGS) comment.cpp

publisher.o: publisher.cpp publisher.h user.h
	$(CC) $(COMPILE_FLAGS) publisher.cpp	

.PHONY: clean

clean:
	rm *.o
	rm *.out