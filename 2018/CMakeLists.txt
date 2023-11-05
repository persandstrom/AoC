project(2018_03)

cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Add your test files
file(GLOB TEST_FILES
  "*_test.cpp"
)
add_executable(aoc_2018_test
    ${TEST_FILES}
    )

# Link GTest libraries
target_link_libraries(aoc_2018_test GTest::GTest GTest::Main)


# Find all header files with the specified pattern
file(GLOB HEADER_FILES "*_part_01.h" "*_part_02.h")


# Create an empty list to store namespace declarations
set(NAMESPACE_DECLARATIONS "")
set(MAP_ITEMS "")

# Loop through each header file to generate namespace declarations
foreach(HEADER ${HEADER_FILES})
    message(${HEADER})
    string(REGEX MATCH "day_([0-9][0-9])_part_([0-9][0-9]).h" extracted_values "${HEADER}")
    set(NAMESPACE_DAY ${CMAKE_MATCH_1})
    set(NAMESPACE_PART ${CMAKE_MATCH_2})
    list(APPEND NAMESPACE_DECLARATIONS "\nnamespace day_${NAMESPACE_DAY}_part_${NAMESPACE_PART} { std::string run(FileReader&); }")
    list(APPEND MAP_ITEMS "{{${NAMESPACE_DAY}, ${NAMESPACE_PART}}, day_${NAMESPACE_DAY}_part_${NAMESPACE_PART}::run},")
    set(INCLUDE_PATH "day_${NAMESPACE_DAY}_part_${NAMESPACE_PART}.h")
    configure_file(day_xx_part_xx_main.cpp.in day_${NAMESPACE_DAY}_part_${NAMESPACE_PART}_main.cpp @ONLY)
    add_executable(aoc_2018_day_${NAMESPACE_DAY}_part_${NAMESPACE_PART} build/day_${NAMESPACE_DAY}_part_${NAMESPACE_PART}_main.cpp)

endforeach()


# Add a custom target to ensure the header is generated
add_custom_target(generate_header DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/forward_declared_functions.h)


file(GLOB INPUT_FILES
  "*_input"
)
file(COPY ${INPUT_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
