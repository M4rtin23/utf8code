#include<stdio.h>

int main(int argc, unsigned char *argv[]){
	int size = 4;

	if(argv[1][0] < 128){
		size = 1;
	}else if(argv[1][0] >= 192 && argv[1][0] < 224){
		size = 2;	
	}else if(argv[1][0] >= 224 && argv[1][0] < 240){
		size = 3;
	}else if(argv[1][0] >= 240 && argv[1][0] < 248){
		size = 4;
	}
	for(int i = 0; i < size; i++){
		printf("%u ", argv[1][i]);
	}
	printf("\n");

	return 0;
}