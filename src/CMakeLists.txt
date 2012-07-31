#include_directories (${TEST_SOURCE_DIR}/include) 
#include_directories (${TEST_SOURCE_DIR}/lib/vc_dll/msw) 

#link_directories (${TEST_SOURCE_DIR}/lib/vc_dll)

SET(mySrcs MyApp.h MyApp.cpp MyFrame.h MyFrame.cpp)
add_executable (test ${mySrcs})


#SET (myDeps wxmsw28_adv.lib wxmsw28_core.lib wxbase28.lib wxtiff.lib wxjpeg.lib wxpng.lib wxzlib.lib wxregex.lib wxexpat.lib)

target_link_libraries (test ${wxWidgets_LIBRARIES})
#${myDeps}) 
