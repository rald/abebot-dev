#include "board.h"

Board* Board_New(char *filename,int x,int y,Canvas* sprite,SDL_Color* palette) {
	Board* b=malloc(sizeof(*b));

	b->x=x;
	b->y=y;
	b->sprite=sprite;
	b->palette=palette;

	int ch;
	int i=0;
	int j=0;

	FILE* fh=fopen(filename,"r");

	fscanf(fh,"%d,%d,%d,%d,%d",&b->w,&b->h,&b->px,&b->py,&b->pd);

	b->p=calloc(b->w*b->h,sizeof(*(b->p)));

	while((ch=fgetc(fh))!=EOF) {
		switch(ch) {
			case '0': j=0; break;
			case '1': j=1; break;
			case '2': j=2; break;
			case '3': j=3; break;
			case '4': j=4; break;
			case '5': j=5; break;
			case '6': j=6; break;
			case '7': j=7; break;
			default: j=-1;
		}
		if(j!=-1) {
			b->p[i++]=j;
		}
	}

	fclose(fh);

	return b;
}

void Board_Draw(Board* b,SDL_Renderer* renderer) {
	for(int i=0;i<b->w*b->h;i++) {
		int x=(i%b->w)*16+b->x;
		int y=(i/b->w)*16+b->y;
		Canvas_Draw(renderer,b->sprite,b->palette,x,y,1,(b->p[i] & 0b00000011)+26);
		if(b->p[i] & 0b00000100) Canvas_Draw(renderer,b->sprite,b->palette,x,y,1,30);
	}

	int d=31;
	switch(b->pd) {
		case 0: d=31; break;
		case 1: d=32; break;
		case 2: d=33; break;
		case 3: d=34; break;
	}
	Canvas_Draw(renderer,b->sprite,b->palette,b->px*16+b->x,b->py*16+b->y,1,d);

}
