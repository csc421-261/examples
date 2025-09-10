#include<stdio.h>

int f(void) {
	int i ;
	printf("%d\n", i );
	i++ ;
	return 0 ;
}

int main(int argc, char * argv[]) {	
	int i ;
	for (i=0;i<10;i++) 
		f(); 
	return 0 ;
}
