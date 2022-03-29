#include <stdio.h>

int main(int argc, char *argv[])
{
	int array[5] = { 1, 2, 3, 4, 5 };
	int x;
	for (x = 0; x < 5; x++){
		printf("打印数组元素: %d \n", array[x]);
	}
	return 0;
}
