#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {

	int x, i = 0;

	while(scanf("%d", &x) == 1){
		i++;
	}

	printf("%d\n", i);

	return 0;
}