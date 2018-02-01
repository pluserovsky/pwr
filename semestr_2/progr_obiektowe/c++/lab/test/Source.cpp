#include <iostream>
using namespace std;

int main()
{
	int M[][4] = { { 1, 2 },{ 0 },{ 3, 4, 5, 6 } };
	for (int i = 0,j=0; i < 4; i++, j++)
	{
		cout << M[i][j] << endl;
	}
	
	
	system("pause");
}