# Klibrary.c

C语言编程中必用的自定义库。


## klog
基于C语言的日志库。

### klog使用

1. 设置日志标志名，一般用项目名。例如这里设置日志标志名为`VISION_CABINET`.

2. 打印不同级别的日志：

    - `klogi(...)` 代表info等级日志；
    - `klogd(...)` 代表debug等级日志；
    - `klogw(...)` 代表warning等级日志；
    - `kloge(...)` 代表error等级日志；
    - `klogf(...)` 代表fatal等级日志。

3. 日志打印示例：

    ```c
    int main()
    {
        KLOG_TAG = "VISION_CABINET";  // 变量名是固定的KLOG_TAG. 可以根据需要修改对应的值
        
        klogi("version = %s", VERSION);
        klogd("This is a debug level log!");
        klogi("This is a info level log!");
        klogw("This is a warning level log!");
        kloge("This is a error level log!");
        klogf("This is a fatal level log!");
        
        return 0;
    }
    ```

    上面的程序执行效果如下：

    ![image-20240622105408166](https://klelee-images.oss-cn-qingdao.aliyuncs.com/typora/image-20240622105408166.png)
