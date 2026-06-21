find_package(Threads REQUIRED)

set(CORE_EXAMPLES
    ownership
    value_semantics
    algorithms
    error_handling
    concurrency
)

foreach(example IN LISTS CORE_EXAMPLES)
    add_executable(${example} ${example}.cpp)
    cpp_notes_target(${example})
    add_test(NAME example_${example} COMMAND ${example})
endforeach()

target_link_libraries(concurrency PRIVATE Threads::Threads)
