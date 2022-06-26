#include <cstdlib>
#include <sys/time.h>
using namespace std;

//produce million s random
int myrandom(int start, int end){
    unsigned int currentTime;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    currentTime = tv.tv_usec;
	srand(currentTime);
	return start + rand() % (end - start);
}