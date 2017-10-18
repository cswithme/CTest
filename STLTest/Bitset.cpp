/*
 * Bitset.cpp
 *
 *  Created on: 2017-10-18
 *      Author: root
 */

#include <stdio.h>
#include <stdlib.h>

#include <bitset>

using namespace std;


void bitSetTest(unsigned int uiBitVal)
{
	bitset<32> uiBitset(uiBitVal);
	printf("uiBitVal have [%u] 1.\n",uiBitset.count());
	string sTemp = uiBitset.to_string();

	printf("uiBitVal is [%s]\n",sTemp.c_str());
}
