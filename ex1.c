#include <stdio.h>

int main()
{
	char *str1;
	char *str2;
	char *str;
	
	printf("Please enter 2 strings\n");
	scanf("%s", str1);
	scanf("%s", str2);
	printf("USer entered:\n\tstr1 = '%s'\n'\tstr2 = '%s'\n", str1, str2);
	
	slen = strlen(str1) + strlen(str2);
	
	return 0;
}