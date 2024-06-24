#include "klog.h"

pthread_t multithread_demo_1;
pthread_t multithread_demo_2;

void * multithread_demo_1_func(void * arg)
{
    for (int i = 0; i < 10; i++) {
        klogd("%p klogd", pthread_self());
    }
}

void * multithread_demo_2_func(void * arg)
{
    for (int i = 0; i < 10; i++) {
        klogd("%p klogd", pthread_self());
    }
}

int main()
{
    KLOG_TAG = "VISION_CABINET";
    
    klogi("version = %s", VERSION);
    klogd("This is a debug level log!");
    klogi("This is a info level log!");
    klogw("This is a warning level log!");
    kloge("This is a error level log!");
    klogf("This is a fatal level log!");

    pthread_create(&multithread_demo_1, NULL, multithread_demo_1_func, NULL);
    pthread_create(&multithread_demo_2, NULL, multithread_demo_2_func, NULL);

    pthread_join(multithread_demo_1, NULL);
    pthread_join(multithread_demo_2, NULL);
    
    return 0;
}