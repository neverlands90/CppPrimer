# CMakeList.txt: CppPrimer 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。
#
cmake_minimum_required (VERSION 3.8)

project ("CppPrimer")

configure_file(
	"${PROJECT_SOURCE_DIR}/CppPrimer.h.in"
	"${PROJECT_SOURCE_DIR}/CppPrimer.h"
)


# 将源代码添加到此项目的可执行文件。
# add_executable (CppPrimer "CppPrimer.cpp" "CppPrimer.h")
add_executable (SalesItem "SalesItem/main.cpp" "SalesItem/Sales_item.h")

# TODO: 如有需要，请添加测试并安装目标。
