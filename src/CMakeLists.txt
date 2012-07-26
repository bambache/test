include_directories (${TEST_SOURCE_DIR}/include/msvc) 
include_directories (${TEST_SOURCE_DIR}/include) 

link_directories (${TEST_SOURCE_DIR}/lib/vc_lib)
link_directories (${TEST_SOURCE_DIR}/lib/vc_dll)

add_executable (test MyApp.h MyApp.cpp MyFrame.h MyFrame.cpp)

target_link_libraries (test wxbase28) 
