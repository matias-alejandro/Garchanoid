#Makefile

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJS = main.o juego.o jugador.o pelota.o

all: Garchanoid

%.o: %.cpp
	g++ -c $< -o $@

%.o: %.hpp
	g++ -c $< -o $@

Garchanoid: $(OBJS)
	g++ -o $@ $(OBJS) $(LIBS)

clean:
	rm -f Garchanoid *.o