# CMakeList.txt: проект CMake для CMakeProject7; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)
# Tell CMake to run moc when necessary:

# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_AUTOMOC ON)




find_package(Iconv)
# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMakeProject7 "CMakeProject7.cpp" "CMakeProject7.h")

target_link_libraries(CMakeProject7 PRIVATE  Iconv::Iconv)
#target_link_libraries(CMakeProject7 Qt5:QtCore)
#target_link_libraries(CMakeProject7 Qt5:QtCore) # )





# TODO: Добавьте тесты и целевые объекты, если это необходимо.
