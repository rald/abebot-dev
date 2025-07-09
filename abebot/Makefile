exe = abebot
objs = main.o utils.o graphics.o canvas.o imgui.o board.o editor.o commands.o
CFLAGS = -g

$(exe): $(objs)
	gcc $(objs) -o $(exe) -lSDL2 -lm

main.o: main.c palette.h
utils.o: utils.c utils.h
graphics.o: graphics.c graphics.h
canvas.o: canvas.c canvas.h
imgui.o: imgui.c imgui.h
board.o: board.c board.h
editor.o: editor.c editor.h
commands.o: commands.c commands.h

clean:
	rm *.o $(exe)
