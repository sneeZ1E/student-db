#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "common.h"

void data_input(int count, struct student *s);
void data_output(int count, struct student *s);
int data_save(int count, struct student *s, const char *file);
struct student *data_read(const char *file, int *count);

int main() {
	int c = 0;
	int  yn = 0;
	char *file = "data.bin";
	struct student *s;
	struct student *data;

	printf("Do you want to see existing student database?\n");
	scanf("%d", &yn);
	if (yn == 1){
		data = data_read(file, &c);
		if (!data)
			printf("Error reading database: %m\n");
		else
			data_output(data, c);
	}
	
	printf("Please enter number of students: ");
	scanf("%d", &c);
	
	s = (struct student *)malloc( sizeof(struct student) * c);
	
	data_input(c, s);
	data_output(c, s);
	
	printf("Do you want to save the data? (1/0)");
	scanf("%d", &yn);
	if (yn == 1){
		printf("Saving data to %s ...\n", file);
		data_save(c, s, file);
	}
	
	free(s);
	return 0;
}

