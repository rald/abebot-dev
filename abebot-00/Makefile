exe = abebot
objs = main.o graphics.o canvas.o editor.o commands.o board.o mouse.o utils.o button.o
CFLAGS = -g

$(exe): $(objs)
	gcc $(objs) -o $(exe) -lSDL2 -lm

main.o: main.c palette.h
graphics.o: graphics.c graphics.h
canvas.o: canvas.c canvas.h
editor.o: editor.c editor.h
commands.o: commands.c commands.h
board.o: board.c board.h
mouse.o: mouse.c mouse.h
utils.o: utils.c utils.h
button.o: button.c button.h

clean:
	rm *.o $(exe)
