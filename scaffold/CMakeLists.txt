cmake_minimum_required (VERSION 2.8.11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x " )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Woverloaded-virtual -Wpointer-arith -Wwrite-strings -Werror=format -march=native " )


include_directories( 
        ${PROJECT_SOURCE_DIR}/../include/
        ${PROJECT_SOURCE_DIR}/../include/google/
        ${PROJECT_SOURCE_DIR}/../include/curl_7.53.1/
)

link_directories( /usr/lib64/mysql/
        ${PROJECT_SOURCE_DIR}/../libs/
        ${PROJECT_SOURCE_DIR}/../libs/boost/
        ${PROJECT_SOURCE_DIR}/../libs/google/
        ${PROJECT_SOURCE_DIR}/../libs/leveldb/
        ${PROJECT_SOURCE_DIR}/../libs
)

aux_source_directory( ./ SCAFFOLD_SRCS )
add_executable( test ${SCAFFOLD_SRCS} )


set (EXTRA_LIBS ${EXTRA_LIBS} glog_syslog )
set (EXTRA_LIBS ${EXTRA_LIBS} tinyxml )
set (EXTRA_LIBS ${EXTRA_LIBS} jsoncpp )
set (EXTRA_LIBS ${EXTRA_LIBS} leveldb snappy )
set (EXTRA_LIBS ${EXTRA_LIBS} pthread gtest gmock)
target_link_libraries( test -lrt -rdynamic -ldl
    ${EXTRA_LIBS}
)

