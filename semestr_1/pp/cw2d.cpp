#include <stdio.h>
#include <iostream>


int main()
{
	int i;
	std::cin>>i;
	
	switch(i)
	{
		case 1:{

			int i=0,j=0;
			do
			{
				scanf("%d", &i);
				j=j+i;
		
				}
			while(j<=100);
			printf("\nSuma przekroczyla 100.");
			getchar();
			getchar();
			break;
			}
			
		case 2:{
			
			int i,n;
			while(i<=10)
			{
				scanf("%d", &n);
				if(n<0) i++;
			}
			printf("\nWpisales 10 liczb ujemnych.");
			
			break;
		}
		
		case 3:{
			
			int n,k;
			
			do
			{
				
				scanf("%d", &n);
				if(k==n) {
					printf("\nWpisales dwie takie same liczby.");
					break;
				}
				scanf("%d", &k);
					if(k==n) {
					printf("\nWpisales dwie takie same liczby.");
					break;
				}
			}
			
			while(n!=k);
			break;

		}
	}
}
