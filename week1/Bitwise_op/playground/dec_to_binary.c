#include <stdio.h>

void DecToBinary();

int main(){
	DecToBinary();
	return 0;	 
}

void DecToBinary(){
	char dec = 'z';	
	int binary[8];
	int *ptr = &binary;
	for (int i=0;i<8;i++){
		*ptr = ( (int)dec ) % 2; //  *binary point to the first element of the array "binary"
		ptr++;
	}
	//while (*ptr!=NULL){
	//	printf("%d", *ptr);
	//	ptr++;
	//}
	for (int i=0; i<8; i++){
		printf("%d", *ptr);
		ptr++;
	}
	
}

