/*
 * main.cpp
 *
 *  Created on: 2018-1-10
 *      Author: root
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int ClassCallbackTestFunc();
int ExterncCallbackTest();

int main(int argc, char *argv[])
{
	puts("Test Begin!");

//	ClassCallbackTestFunc();
	ExterncCallbackTest();

	puts("Test end!");

	return 0;
}
