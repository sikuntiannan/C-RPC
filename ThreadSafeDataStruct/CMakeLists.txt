cmake_minimum_required (VERSION 3.22)

project ("ThreadSafeDataStruct")

include_directories(${CMAKE_INSTALL_PREFIX}/include/)#头文件目录
link_directories(${CMAKE_INSTALL_PREFIX}/lib)#库文件目录

file(GLOB H_File ./*.h)
file(GLOB CPP_File ./*.cpp)

#link_libraries()#添加连接库

#find_package()

add_library(ThreadSafeDataStruct STATIC ${CPP_File})

#target_link_libraries()

install(FILES ${H_File} DESTINATION include/ThreadSafeDataStruct)#安装头文件
install(TARGETS ThreadSafeDataStruct DESTINATION lib OPTIONAL)#安装头文件