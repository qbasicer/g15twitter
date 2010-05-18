#include <cstdlib>
#include <cstdio>
#include <unistd.h>
#include "SampleTwitterScreen.hpp"

SampleTwitterScreen::SampleTwitterScreen(CanvasManager *cm):G15Widget(cm){
	init();
}

SampleTwitterScreen::SampleTwitterScreen(VirtualCanvas *vc):G15Widget(vc){
	init();
}

char* wordWrapString(char* foo, int max){
	char* newString = (char*)malloc(strlen(foo) + strlen(foo)/max + 1);
	int i;
	int lptr = 0;
	int j = 0;
	int col = 0;
	for(i = 0; i < strlen(foo); i++,col++,j++){
		newString[j] = foo[i];
		if(foo[i] == '\n'){
			col = -1;
		}else if(foo[i] != ' '){
			if(lptr == -1){
				lptr = j;
			}
			if(col == max){
				if(i - lptr > max){
					//rebase long
					col = 0;
					newString[j+1] = newString[j];
					newString[j] = '\n';
					j++;
					lptr = j;
					
				}else{
					col = j-lptr;
					//printf("***\ni: %d, j: %d, col: %d, lptr: %d, foo[%d]: %c, newString[%d]: %c (%d)\n",i,j,col,lptr,i,foo[i],j,newString[j],newString[j]);
					//printf("Rebasing string to be at col %d\n",col);
					int k;

					j++;
					for(k = j; k > lptr; k--){
						newString[k] = newString[k-1];
						//printf("Carrying %c forward from %d to %d\n",newString[k],k-1,k);
					}
					newString[lptr] = '\n';
					//printf("i: %d, j: %d, col: %d, lptr: %d, foo[%d]: %c, newString[%d]: %c (%d)\n***\n",i,j,col,lptr,i,foo[i],j,newString[j],newString[j]);
				}
			}else{
				
			}
		}else{
			lptr = -1;
			if(col == max){
				col = 0;
				newString[j] = '\n';
			}else if(col == 0){
				newString[j] = newString[j++];
				j--;
			}
		}
		//printf("i: %d, j: %d, col: %d, lptr: %d, foo[%d]: %c, newString[%d]: %c (%d)\n",i,j,col,lptr,i,foo[i],j,newString[j],newString[j]);
	}
	newString[++j] = '\0';
	return newString;
}

void SampleTwitterScreen::init(){
	layout = new G15StandardLayout(this,"<NobodyActually> (2h)");
	char* str = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Pellentesque vel tortor id massa aliquam interdum. In eu neque sed ligula molestie faucibus vitae eu quam. Integer elit orci, sagittis non consequat consectetur, semper eu erat. Donec est dui, dignissim nec molestie eu, volutpat vel nunc. Suspendisse potenti. Etiam est velit, semper vitae feugiat nec, porta sed nisi. Nunc eleifend mollis turpis a pretium. Duis commodo, metus vel volutpat tincidunt, nunc odio aliquam magna, nec scelerisque ante ligula vitae risus. Maecenas et lectus tortor, a auctor orci. Etiam laoreet vehicula ipsum, non egestas augue mollis a. Phasellus convallis feugiat dolor vel condimentum.\n\n  Fusce erat mauris, commodo sed pharetra at, aliquet sit amet turpis. Cum sociis natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus. Duis convallis, justo ac iaculis dictum, mauris eros suscipit eros, ac iaculis nulla lorem eu tortor. Aliquam at lorem est, id gravida risus. Vestibulum tellus est, imperdiet id volutpat sit amet, ornare id tellus. Etiam viverra ullamcorper quam, eget ultricies ipsum sagittis sed. Pellentesque non eros dolor, ac porta purus. Nam justo felis, imperdiet sit amet congue ut, volutpat vel elit. Fusce auctor fringilla dignissim. Ut leo quam, ultrices vel vulputate in, pharetra placerat nibh.";
	char* wrapped = wordWrapString(str,30);
	body = new G15TextLabel(wrapped, this);
	layout->setMainWidget(body);
	free(wrapped);
	
}

int SampleTwitterScreen::paint(){
	int i;
	int lines = 8;
	int eend = 0;
	int scrolls = lines - 3;
	if (scrolls > 0){
		eend = 0-(scrolls*7);
	}
	for(i = 0; i >= eend; i--){
		clearScreen(G15_PIXEL_NOFILL);
		body->move(0, 9+i);
		
		layout->render();
		
		drawBar(0, 34, 160, 42, G15_PIXEL_NOFILL, 1, 1, 0);
		drawRoundedBox(0, 35, 38, 50, G15_PIXEL_NOFILL, G15_PIXEL_FILL);
				
		getCanvas()->getCanvas()->send();
		if(i % 7){
			usleep(50000);
		}else{
			sleep(3);
		}
	}
	return 0;
}
