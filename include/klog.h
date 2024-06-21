#ifndef _KLOG_H_
#define _KLOG_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

typedef enum klog_level {
    DEBUG,
    INFO,
    WARNING,
    ERROR,
    FATAL
} klog_level;

void klog_message(klog_level level, const char * filename, int line, const char * format, ...);

#define klogd(format, ...) klog_message(DEBUG, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define klogi(format, ...) klog_message(INFO, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define klogw(format, ...) klog_message(WARNING, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define kloge(format, ...) klog_message(ERROR, __FILE__, __LINE__, format, ##__VA_ARGS__)
#define klogf(format, ...) klog_message(FATAL, __FILE__, __LINE__, format, ##__VA_ARGS__)

extern char * KLOG_TAG;

#endif   /* _KLOG_H_ */
