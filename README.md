# tinytcad - 微型 TCAD 半导体仿真框架
![C++](https://img.shields.io/badge/C++-17/20-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.20+-green.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

### 项目简介
基于 C++17/20 + CMake 开发的**微型 TCAD（半导体器件仿真）框架**，支持一维均匀网格生成、数值求解、结果文件导出。
项目结合**半导体物理研究需求**，构建工业级仿真工程，可作为半导体仿真的基础工具。

### 核心功能
✅ **模块化架构**：Utils（工具）/ Mesh1D（网格）/ Solver（求解器）/ IO（文件）全模块解耦
✅ **一维网格生成**：STL vector 版安全实现，支持自定义节点数/坐标范围
✅ **数值求解引擎**：对接网格数据，支持扩展真实半导体物理模型（泊松方程/载流子输运）
✅ **结果导出**：生成标准化 `result.txt`，支持仿真数据可视化对接
✅ **工程化规范**：CMake 构建、Git 版本管理、.gitignore 隔离、统一代码注释

### 技术栈
- 编程语言：C++17/20（STL 容器、面向对象、RAII 机制）
- 构建工具：CMake 3.20+
- 版本控制：Git/GitHub（SSH 免密推送）
- 数值计算：一维有限差分法、线性代数基础运算

### 快速开始
#### 环境依赖
- Linux (Ubuntu 20.04+/CentOS) 或 Windows (MinGW)
- CMake 3.20 及以上
- C++ 编译器 (GCC 9+/Clang 10+/MSVC 19.28+)

#### 编译运行（Ubuntu 示例）
```bash
# 1. 克隆仓库
git clone git@github.com:Xiangkun-hit/tinytcad.git
cd tinytcad

# 2. 创建构建目录
mkdir build && cd build

# 3. CMake 配置
cmake ..

# 4. 编译（-j4 对应CPU核心数，加速编译）
make -j4

# 5. 运行仿真程序
src/tinytcad