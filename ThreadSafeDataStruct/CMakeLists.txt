cmake_minimum_required (VERSION 3.22)

project ("ThreadSafeDataStruct")

include_directories(${CMAKE_INSTALL_PREFIX}/include/)
link_directories(${CMAKE_INSTALL_PREFIX}/lib)

target_link_libraries()

file(GLOB H_File ./*.h)
file(GLOB CPP_File ./*.cpp)

install(FILES ${H_File} DESTINATION .\include)