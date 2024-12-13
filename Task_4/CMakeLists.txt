cmake_minimum_required(VERSION 3.20)
project(NumberDivisibility)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

# Включение clang-tidy
#set(CMAKE_CXX_CLANG_TIDY "clang-tidy;--config={Checks: '*, -clang-analyzer-*'}")

# Основной исполняемый файл
add_executable(NumberDivisibility main.cpp number_divisibility.cpp)

# # Подключение Google Test
# enable_testing()
# find_package(GTest REQUIRED)
# include_directories(${GTEST_INCLUDE_DIRS})

# # Добавление тестов
# add_executable(NumberDivisibilityTests test_number_divisibility.cpp number_divisibility.cpp)
# target_link_libraries(NumberDivisibilityTests ${GTEST_LIBRARIES} pthread)

# add_test(NAME NumberDivisibilityTests COMMAND NumberDivisibilityTests)

# # Проверка main.cpp с помощью clang-tidy без исправлений
# add_custom_target(lint_test
#     COMMAND clang-tidy main.cpp -- -std=c++11
#     DEPENDS NumberDivisibility
#     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#     COMMENT "Running clang-tidy on main.cpp"
# )
