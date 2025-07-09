exe = abebot
objs = main.o imgui.o
CFLAGS = -g

$(exe): $(objs)
	gcc $(objs) -o $(exe) -lSDL2 -lm

main.o: main.c palette.h
imgui.o: imgui.c imgui.h

clean:
	rm *.o $(exe)
