#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include "common.h"


int data_save(int count, struct student *s, const char *file){
	int fd;
	ssize_t bw = 0;
	int data_size = 0;
	
	data_size = count * sizeof(struct student);
	
	if (count <1){
		return 0;
	}
	
	if (!s || !file){
		return -DATA_SAVE_ERR_INPUT;
	}
	
	fd = open(file, O_CLOEXEC | O_CREAT | O_WRONLY | O_APPEND, 0777);
	if (fd<0){
		return -DATA_SAVE_ERR_OPEN;
	}
	
	bw = write(fd, s, data_size);
	if (bw<data_size) {
		close(fd);
		return -DATA_SAVE_ERR_WRITE;
	}

	close(fd);
	return DATA_SAVE_OK;
}

struct student *data_read(const char *file, int *count){
	int fd;
	ssize_t br = 0;
	*count = 0;
	struct student *data = NULL;
	
	if (!file)
		return data;
	
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return data;
	
	data = (struct student *)malloc(sizeof(struct student));
	if (!data)
		return data;
		
	while(1){
		br = read(fd, data + count, sizeof(struct student));
		if (br < sizeof(struct student))
			break;
		*count++;
		data = (struct student *)realloc(data, sizeof(struct student)*(*count + 1));
		if (!data)
			break;
	}
	
	return data;
}