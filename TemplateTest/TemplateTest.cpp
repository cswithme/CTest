#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <stdint.h>
#include <map>
#include <math.h>
#include <iconv.h>
#include <set>
#include <pthread.h>
#include <vector>
#include <algorithm>    // std::sort

template <typename T>
int compare(const T& v1, const T& v2)
{
	if(v1 < v2) return -1;
	else if(v1 > v2) return 1;
	else return 0;
}

int main()
{
	using namespace std;
	puts("Test begin111!");

	printf("1 2 %d\n", compare(1, 2));
	printf("aa bb %d\n", compare(string("aa"), string("aa")));

	puts("Test end111!");
	return 0;

}
