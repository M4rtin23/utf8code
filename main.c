#include<stdio.h>

unsigned char* getFromChar(unsigned char *argv[]){
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

unsigned char* getFromInt(int argc, unsigned char *argv[]){
	unsigned char values[4] = {0,0,0,0};
	unsigned char *val_ptr = values;

	for(int i = 1; i < argc; i++){
		sscanf(argv[i], "%hhd", &values[i-1]);
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
	_Bool isChar = 1, showMessage = 1;
	int position = -1;
	for(int i = 1; i < argc; i++){
		if(argv[i][0] != '-' && position == -1){
			position = i-1;
		}else{
			switch(argv[i][1]){
				case 'a':
					showMessage = 1;
					break;
				case 'b':
					showMessage = 0;
					break;
				case 'c':
					isChar = 1;
					break;
				case 'u':
					isChar = 0;
					break;
			}
		}
	}
	unsigned char *values;
	if(isChar){
		values = getFromChar(&argv[position]);
	}else{
		values = getFromInt(argc-position, &argv[position]);
	}
	if(showMessage){
		printf("The utf8 code ");
		printCode(values);
		printf("represents the character ");
		printCharacter(values);
		printf(".\n");
	}else{
		if(isChar){
			printCode(values);
			printf("\n");
		}else{
			printCharacter(values);
			printf("\n");
		}
	}
	return 0;
}
