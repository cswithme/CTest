#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/syscall.h>   /* For SYS_xxx definitions */


void *PollStateThread(void *arg){
    

	printf("线程ID = %d\n", (long int)syscall(__NR_gettid));

    
    while(1){
        usleep(300 * 1000);
    }
}

int main(){
    int i=0;
    while(1){
        usleep(800 * 1000);
        printf("i=%d\n", i);
        ++i;
    }
    return 0;
}

    // pthread_t tidPoll = 0;
    // pthread_attr_t  attr;
	// pthread_attr_init(&attr);
	// pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    
    // m_bThreadExec = true;
	// if(0 != pthread_create(&tidPoll,&attr,PollStateThread,this))
	// {
        // m_bThreadExec = false;
		// m_pcLog->LogError("Create PollState Thread Fail!!! [%s][%s][%d]", __FILE__ , __FUNCTION__, __LINE__);
        // return false;
	// }