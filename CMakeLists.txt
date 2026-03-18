cmake_minimum_required(VERSION 3.16)

# 项目名称：你自定义的 tinytcad
project(tinytcad)

# 使用 C++17 标准（强制，稳定）
SET(CMAKE_CXX_STANDARD 17)
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)

# 开启测试功能（第四周用）
ENABLE_TESTING()

# 加载三个子模块
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(tests)
ADD_SUBDIRECTORY(pythonapi)
