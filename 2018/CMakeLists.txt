project(2018_03)

cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")


find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Add your test files
file(GLOB TEST_FILES
  "*/*_test.cpp"
)
add_executable(aoc_2018_test
    ${TEST_FILES}
    )

# Link GTest libraries
target_link_libraries(aoc_2018_test GTest::GTest GTest::Main)


# Find all header files with the specified pattern
file(GLOB HEADER_FILES "*/01.h" "*/02.h")


# Create an empty list to store namespace declarations
set(NAMESPACE_DECLARATIONS "")
set(MAP_ITEMS "")

# Loop through each header file to generate namespace declarations
foreach(HEADER ${HEADER_FILES})
    message(${HEADER})
    string(REGEX MATCH "([0-9][0-9])\/([0-9][0-9]).h" extracted_values "${HEADER}")
    set(NAMESPACE_DAY ${CMAKE_MATCH_1})
    set(NAMESPACE_PART ${CMAKE_MATCH_2})
    list(APPEND NAMESPACE_DECLARATIONS "\nnamespace day_${NAMESPACE_DAY}_part_${NAMESPACE_PART} { std::string run(FileReader&); }")
    list(APPEND MAP_ITEMS "{{${NAMESPACE_DAY}, ${NAMESPACE_PART}}, day_${NAMESPACE_DAY}_part_${NAMESPACE_PART}::run},")
endforeach()

# Generate the header file
string(REPLACE ";" "\n" MAP_ITEMS "${MAP_ITEMS}")
configure_file(forward_declared_functions.h.in forward_declared_functions.h @ONLY)

# Add a custom target to ensure the header is generated
add_custom_target(generate_header DEPENDS ${CMAKE_CURRENT_BINARY_DIR}/forward_declared_functions.h)



file(GLOB MAIN_FILES
  "*/main.cpp"
)
add_executable(aoc_2018 main.cpp ${MAIN_FILES} )
target_include_directories(aoc_2018 PRIVATE common ${CMAKE_CURRENT_BINARY_DIR})



file(GLOB INPUT_FILES
  "*/input_*"
)
file(COPY ${INPUT_FILES} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
