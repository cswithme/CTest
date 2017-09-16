#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main()
{
    int iRet = 3;
        {
                    int iRet = 666;
                            printf("iRet in if is %d\n", iRet);
            }
                                    printf("iRet out if is %d\n", iRet);
}
