cmake_minimum_required(VERSION 4.0)

project(CppDesignPattern LANGUAGES CXX)


file(GLOB CreationalPatterns 
    RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/CreationalPatterns/*
)
foreach(_dir_name IN ITEMS ${CreationalPatterns})
    get_filename_component(_project_name ${_dir_name} NAME)
    message(STATUS " ${_dir_name}/${_project_name}.cpp is going to be built")
    add_executable(${_project_name} "${_dir_name}/${_project_name}.cpp")
    message("${_dir_name}/${_project_name}.cpp")
endforeach()
