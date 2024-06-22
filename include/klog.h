#ifndef _KLOG_H_
#define _KLOG_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

#if (_WIN32||WIN64)
#define FILENAME(x) strrchr(x,'\\')?strrchr(x,'\\')+1:x
#else
#define FILENAME(x) strrchr(x,'/')?strrchr(x,'/')+1:x
#endif

typedef enum klog_level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
} klog_level;

void klog_message(klog_level level, const char * filename, int line, const char * format, ...);

#define klogd(format, ...) klog_message(DEBUG, FILENAME(__FILE__), __LINE__, format, ##__VA_ARGS__)
#define klogi(format, ...) klog_message(INFO, FILENAME(__FILE__), __LINE__, format, ##__VA_ARGS__)
#define klogw(format, ...) klog_message(WARNING, FILENAME(__FILE__), __LINE__, format, ##__VA_ARGS__)
#define kloge(format, ...) klog_message(ERROR, FILENAME(__FILE__), __LINE__, format, ##__VA_ARGS__)
#define klogf(format, ...) klog_message(FATAL, FILENAME(__FILE__), __LINE__, format, ##__VA_ARGS__)

extern char * KLOG_TAG;

#endif   /* _KLOG_H_ */
