#include <stdio.h>
#include <string.h>

#include "checksum.h"


int main(int argc, char *argv[]) {
//	uint8_t context[] = {0x7B, 0x22, 0x63, 0x6F, 0x6D, 0x6D, 0x61, 0x6E, 0x64, 0x22,
//			0x3A, 0x31, 0x30, 0x30, 0x31, 0x2C, 0x22, 0x64, 0x61, 0x74, 0x61, 0x22,
//			0x3A, 0x22, 0x7B, 0x7D, 0x22, 0x2C, 0x22, 0x74, 0x69, 0x6D, 0x65, 0x22,
//			0x3A, 0x22, 0x32, 0x30, 0x31, 0x39, 0x2D, 0x30, 0x37, 0x2D, 0x33, 0x30,
//			0x20, 0x31, 0x36, 0x3A, 0x31, 0x33, 0x3A, 0x32, 0x36, 0x22, 0x2C, 0x22,
//			0x6D, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x5F, 0x69, 0x64, 0x22, 0x3A, 0x31, 0x7D, 0};

	uint8_t context[] = {123, 34, 99, 111, 109, 109, 97, 110, 100, 34, 58, 49, 48, 48, 49, 44, 34, 100, 97, 116, 97, 34,
			58, 34, 123, 125, 34, 44, 34, 116, 105, 109, 101, 34, 58, 34, 50, 48, 49, 57, 45, 48, 55, 45, 51, 48, 32, 49,
			54, 58, 49, 51, 58, 50, 54, 34, 44, 34, 109, 101, 115, 115, 97, 103, 101, 95, 105, 100, 34, 58, 49, 125, 0};
	uint16_t crckermit = crc_kermit(context, strlen(context));
	fprintf(stdout, "crc context:%s\ncrc sum:%04X\n", context, crckermit);
	
	return 0;
}