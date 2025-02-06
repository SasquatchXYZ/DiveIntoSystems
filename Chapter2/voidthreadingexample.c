#include <pthread.h>
/*
 * an application-specific pthread main function
 * must have this function prototype: `int func_name(void *args)`
 *
 * any given implementation knows what type is really passed in
 *  args: pointer to an int value
 */
int my_thr_main(void* args)
{
    int num;

    // first recast args to an int *, then dereference to get int value
    num = *((int*)args); // num gets 6

    return num;
}

int main()
{
    int ret, x;
    pthread_t tid;

    x = 6;
    // pass the address of int variable (x) to pthread_create's void * param
    // (we recast &x as a (void *) to match the type of pthread_create's param)
    ret = pthread_create(&tid, NULL,
                         my_thr_main, // a thread main function
                         (void*)(&x)); // &x will be passed to my_thr_main

    // ...
}
