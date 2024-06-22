# Klibrary.c


## klog
一个基于C语言的轻量级日志库。

### klog使用流程
klog的使用类似于printf输出日志的方式。不同等级的日志输出函数是：
```c
klogd("This is a debug log.");
klogi("This is a info log.");
klogw("This is a warning log.");
kloge("This is a error log.");
klogf("This is a fatal log.");
```

