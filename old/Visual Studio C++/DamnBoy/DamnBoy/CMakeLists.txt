# CMakeList.txt: проект CMake для DamnBoy; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#

# Добавьте источник в исполняемый файл этого проекта.
add_executable (DamnBoy "DamnBoy.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET DamnBoy PROPERTY CXX_STANDARD 20)
endif()

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
