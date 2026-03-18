#include "utils.h"
#include <iostream>

void Utils::init() {
  // 调用自身的日志打印
  log_info("初始化模块成功");
}

//打印普通日志信息
void Utils::log_info(const char *msg) {
  // 专业格式输出 [模块名] 信息
  std::cout << "[Utils INFO] " << msg << std::endl;
}

// 打印错误信息（预留）
void Utils::log_error(const char *msg) {
  std::cout << "[Utils ERROR]" << msg << std::endl;
}