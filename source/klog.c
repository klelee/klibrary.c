#include "klog.h"

char * KLOG_TAG;

void klog_message(klog_level level, const char * filename, int line, const char * format, ...)
{
    va_list args;
    va_start(args, format);
    char buffer[1024];
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    time_t current_time = time(NULL);
    struct tm * tm_info = localtime(&current_time);

    char time_str[26];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);

    const char * level_str;
    switch (level)
    {
    case DEBUG:
        level_str = "DEBUG";
        break;
    case INFO:
        level_str = "INFO";
        break;
    case WARNING:
        level_str = "WARNING";
        break;
    case ERROR:
        level_str = "ERROR";
        break;
    case FATAL:
        level_str = "FATAL";
        break;
    default:
        level_str = "UNKNOWN";
        break;
    }

    fprintf(stderr, "%s %s %s\t%s:%d %s\n", (KLOG_TAG == NULL ? "KLOG" : KLOG_TAG), time_str, level_str, filename, line, buffer);
}
