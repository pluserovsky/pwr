#include <stdio.h>

int main()
{
	int i,n;

	printf("Dzielna: ");
	scanf("%d", &n);

	for(i=0;i<=10000;i++){
		if(i%n==0){
			printf("%d, ",i);
		}
	}
	getchar();
	getchar();
	return 0;
}