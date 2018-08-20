//============================================================================
// Name        : FileFlushTest.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


using namespace std;

int main() {
	puts("Test Begin!");

	const char *pszWrite = "12345";

	system("rm -f ./test");

	int iRet = access("./test", R_OK);
	printf("access return %d\n", iRet);

	FILE *file = fopen("./test", "w+");
	if(file == NULL)
	{
		printf("fopen <./test> file error, %s \n",strerror(errno));
	}

	if(fwrite(pszWrite, sizeof(pszWrite), 1, file) != 1)
	{
		printf("fwrite <./test> file error, %s \n",strerror(errno));
	}

	fflush(file); //flush 并不会调用fsync
//	int fdtemp = fileno(file);
//	fsync(fdtemp);
	fclose(file);

	puts("Test end!");


	puts("Test2 Begin!");
//	int fd = open("./test2", O_WRONLY|O_EXCL|O_CREAT);
	int fd = open("./test2", O_WRONLY|O_CREAT);
	if(-1 == fd)
	{
		printf("open <./test2> file error, %s \n",strerror(errno));
	}

	size_t wirteCnt =  write(fd, pszWrite, sizeof(pszWrite));
	if(wirteCnt != sizeof(pszWrite))
	{
		printf("write <./test2> file error,writeCnt<%u>, %s \n", wirteCnt ,strerror(errno));
	}

	fsync(fd);
	close(fd);

	puts("Test2 end!");


	return 0;
}
