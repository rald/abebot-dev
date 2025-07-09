#include "canvas.h"

Canvas* Canvas_Load(char* filename) {
	Canvas* c=malloc(sizeof(*c));

	char* hex="0123456789ABCDEF";
	char ch;
	FILE* fh=fopen(filename,"r");
	fscanf(fh,"%d,%d,%d,%d",&c->w,&c->h,&c->f,&c->t);

	c->p=calloc(c->f*c->w*c->h,sizeof(*c->p));
	int i=0;
	while((ch=fgetc(fh))!=EOF) {
		int j=-1;
		for(int k=0;k<16;k++) {
			if(ch==hex[k]) {
				j=k;
				break;
			}
		}
		if(j!=-1) {
			c->p[i++]=j;
		}
	}

	fclose(fh);

	return c;
}

void Canvas_Draw(SDL_Renderer* renderer,Canvas* c,SDL_Color* p,int x,int y,int s,int f) {
	for(int j=0;j<c->h;j++) {
		for(int i=0;i<c->w;i++) {
			int k=c->p[f*c->w*c->h+j*c->w+i];
			if(k!=c->t) {
				Graphics_SetColor(renderer,p[k]);
				Graphics_FillRect(renderer,i*s+x,j*s+y,s,s);
			}
		}
	}
}
