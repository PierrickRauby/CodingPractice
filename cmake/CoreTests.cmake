# Core test directory
set(TESTS_CORE_DIR ${CMAKE_SOURCE_DIR}/tests/core)

# Build test_builder tests
add_executable(test_test_builder ${TESTS_CORE_DIR}/test_test_builder.cpp)
target_link_libraries(test_test_builder test_builder)
add_test(NAME test_test_builder COMMAND test_test_builder)

# Build test_runner tests
add_executable(test_test_runner ${TESTS_CORE_DIR}/test_test_runner.cpp)
target_link_libraries(test_test_runner test_runner)
add_test(NAME test_test_runner COMMAND test_test_runner)

# Custom target to run only `test_test_builder`
add_custom_target(run_test_builder
    COMMAND test_test_builder
    DEPENDS test_test_builder
)

# Custom target to run only `test_test_runner`
add_custom_target(run_test_runner
    COMMAND test_test_runner
    DEPENDS test_test_runner
)
