#include "klog.h"

int main()
{
    KLOG_TAG = "VISION_CABINET";
    
    klogi("version = %s", VERSION);
    klogd("This is a debug level log!");
    klogi("This is a info level log!");
    klogw("This is a warning level log!");
    kloge("This is a error level log!");
    klogf("This is a fatal level log!");
    
    return 0;
}