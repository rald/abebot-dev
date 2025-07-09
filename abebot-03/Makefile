exe = abebot
objs = main.o utils.o graphics.o canvas.o mouse.o imgui.o board.o editor.o commands.o button.o
CFLAGS = -g

$(exe): $(objs)
	gcc $(objs) -o $(exe) -lSDL2 -lm

main.o: main.c palette.h
utils.o: utils.c utils.h
graphics.o: graphics.c graphics.h
canvas.o: canvas.c canvas.h
mouse.o: mouse.c mouse.h
imgui.o: imgui.c imgui.h
board.o: board.c board.h
editor.o: editor.c editor.h
commands.o: commands.c commands.h
button.o: button.c button.h

clean:
	rm *.o $(exe)
