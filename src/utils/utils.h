#ifndef TINYTCAD_UTILS_H
#define TINYTCAD_UTILS_H

class Utils{
public:
    //初始化函数
    void init();

    //打印普通日志信息
    void log_info(const char* msg);

    // 打印错误信息（预留）
    void log_error(const char* msg);
};

#endif