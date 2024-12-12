#include <stdio.h>
#include <string.h>

int main() {
	int a = 15;
	float b = 5;
	int ret = -1;
	char symC = 'C';
	char sym65 = 65;
	char sym9 = 9;
	char *str = "aaaaaaaaaaaaaaaaa";

	printf("a = %d, b = %f\n", a, b);
	printf("ret = %u\n", ret);
	printf("%c\n%c\n%c<tab\n", symC, sym65, sym9);
	printf("string = '%s', len = %i\n", str, (int)strlen(str));
	
	printf("a hex = 0x%x\n", a);
	
	scanf("%d", &a);
	printf("user entered: '%d'\n", a);
	
	return ret;
}
