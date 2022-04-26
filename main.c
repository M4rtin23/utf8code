#include<stdio.h>

char* getCode(unsigned char *argv[]){
	unsigned char values[4] = {0,0,0,0};
	unsigned char *val_ptr = values;

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
		values[i] = argv[1][i];
	}
	return val_ptr;
}

void printCode(unsigned char code[]){
	for(int i = 0; i < 4; i++){
		if(code[i]){
			printf("%d ", code[i]);
		}
	}
}

void printCharacter(unsigned char code[]){
	printf("%c%c%c%c", code[0], code[1], code[2], code[3]);
}

int main(int argc, unsigned char *argv[]){
	printCode(getCode(&argv[0]));
	
	return 0;
}