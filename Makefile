CC = gcc -g -O3
CXX = g++ -g -Werror -O3
LIBS =
OBJS = enginebase.o \
	engine.o \
	main.o 

all: nesjoker
	${CXX} -o nesjoker ${OBJS} ${LIBS}
nesjoker: ${OBJS} 
	${CXX} -c $<

clean:
	rm -f *.o nesjoker

.cc.o:
	${CC} -c $<
