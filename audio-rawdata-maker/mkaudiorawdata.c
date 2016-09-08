#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#define BUFFER_SIZE 10485760

static char data[BUFFER_SIZE] = { 0x0 };

int main(int argc, char **argv)
{
	int fd = 0, size;
	unsigned char fliter[] = {"\xAA\xAA\x00\x00"};
	int count  = BUFFER_SIZE;
	char *p = data;

	if ((fd = open("rawdata", O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1) {
		printf("Open Error：%s\n", strerror(errno));  
		return -1;
	}
	//memset(data, 0xAA, BUFFER_SIZE);

	while(count > 0){
		memcpy(p, fliter, 4);
		count -= 4;
		p += 4;
	}

	size = write(fd, data, BUFFER_SIZE);
	close(fd); 
	return 0;
}  
