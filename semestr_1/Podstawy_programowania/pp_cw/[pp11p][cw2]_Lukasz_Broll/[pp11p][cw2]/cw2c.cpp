#include <stdio.h>

int main()
{
	for(int k=0; k<=3;k++)	//petla 1
	{
		for(int i=0;i<=10;i++){ //petla 2
			for(int l=0;l<=100000000;l++); // petla 3 (przy mniejszej liczbie nie widac u mnie roznicy)
			printf("%d, ", i);
		}
		printf("\n");
		for(int i=10;i>=0;i--){ //petla 4
			for(int l=0;l<=100000000;l++); //petla 5
			printf("%d, ", i);
		}
	printf("\n");
	}
	getchar();
	return 0;
	// po³¹czenia sekwencyjne: pêtle 2 i 4
	//po³¹czenia zagnie¿d¿one: pêtla 1 do wszystkich, 2 i 3, 4 i 5
}
