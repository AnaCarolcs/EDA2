#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	int x, y, res = 0;
	
	scanf("%d", &x);

	for (int i = 0; i < x; ++i)
	{
		scanf("%d", &y);
		res+=y;
	}

	printf("%d\n", res);

	return 0;
}