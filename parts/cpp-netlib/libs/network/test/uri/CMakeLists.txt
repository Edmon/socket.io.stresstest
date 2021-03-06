#            Copyright (c) Dean Michael Berris 2010.
# Distributed under the Boost Software License, Version 1.0.
#    (See accompanying file LICENSE_1_0.txt or copy at
#          http://www.boost.org/LICENSE_1_0.txt)

include_directories(${CPP-NETLIB_SOURCE_DIR})

if (Boost_FOUND)
    set(
        TESTS
        url_test
        url_builder_test
        url_encoding_test
        )
    foreach (test ${TESTS})
        if (${CMAKE_CXX_COMPILER_ID} MATCHES GNU)
          set_source_files_properties(${test}.cpp
            PROPERTIES COMPILE_FLAGS "-Wall")
        endif()
        add_executable(cpp-netlib-${test} ${test}.cpp)
        add_dependencies(cpp-netlib-${test} cppnetlib-uri)
        target_link_libraries(cpp-netlib-${test}
            ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} cppnetlib-uri)
        if (OPENSSL_FOUND)
            target_link_libraries(cpp-netlib-${test} ${OPENSSL_LIBRARIES})
        endif()
        set_target_properties(cpp-netlib-${test}
            PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CPP-NETLIB_BINARY_DIR}/tests)
        add_test(cpp-netlib-${test}
            ${CPP-NETLIB_BINARY_DIR}/tests/cpp-netlib-${test})
    endforeach (test)

endif()
