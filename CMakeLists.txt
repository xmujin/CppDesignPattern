cmake_minimum_required(VERSION 4.0)

project(CppDesignPattern LANGUAGES CXX)


set(PATTERNS_DIR 
    CreationalPatterns 
    BehavioralPatterns
    StructuralPatterns
)



foreach(_pattern_dir IN ITEMS ${PATTERNS_DIR})
    file(GLOB PATTERNS 
        # RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
        "${CMAKE_CURRENT_SOURCE_DIR}/${_pattern_dir}/*"
    )
    if(PATTERNS)
        foreach(_dir_name IN ITEMS ${PATTERNS})
            get_filename_component(_project_name ${_dir_name} NAME)
            message(STATUS " ${_dir_name}/${_project_name}.cpp将要被构建")
            add_executable(${_project_name} "${_dir_name}/${_project_name}.cpp")
            message("${_dir_name}/${_project_name}.cpp")
        endforeach()
    endif()
endforeach()




