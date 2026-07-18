cmake_minimum_required(VERSION 3.12)
project(DesignPatterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 扫描仓库内所有 .cpp，按所在目录各自生成一个可执行文件
file(GLOB_RECURSE ALL_CPP CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/*/*.cpp"
)

set(EXAMPLE_DIRS "")
foreach(cpp_file IN LISTS ALL_CPP)
    get_filename_component(dir "${cpp_file}" DIRECTORY)
    # 跳过 build 目录中的文件
    if(dir MATCHES "/build(/|$)")
        continue()
    endif()
    list(APPEND EXAMPLE_DIRS "${dir}")
endforeach()
list(REMOVE_DUPLICATES EXAMPLE_DIRS)

foreach(dir IN LISTS EXAMPLE_DIRS)
    file(RELATIVE_PATH rel_path "${CMAKE_SOURCE_DIR}" "${dir}")

    # 目标名用叶子目录名（如 1.3 -> 1_3），避免中文路径导致非法 target 名
    get_filename_component(leaf "${dir}" NAME)
    string(REPLACE "." "_" target_name "${leaf}")

    file(GLOB sources CONFIGURE_DEPENDS "${dir}/*.cpp")
    file(GLOB headers CONFIGURE_DEPENDS "${dir}/*.h" "${dir}/*.hpp")

    add_executable(${target_name} ${sources} ${headers})
    message(STATUS "示例目标: ${target_name} <- ${rel_path}")
endforeach()
