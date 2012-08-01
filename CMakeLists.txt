cmake_minimum_required (VERSION 2.6)

project (TEST) 

if (MSVC)
  set(wxWidgets_ROOT_DIR "c:\\wxWidgets-2.8.12" CACHE STRING "wxWidgets root dir" FORCE)
  set(wxWidgets_LIB_DIR "c:\\wxWidgets-2.8.12\\lib\\vc_dll" CACHE STRING "wxWidgets lib dir" FORCE)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /D__WXMSW__ /DWXUSINGDLL" CACHE STRING "wx Flags for all builds" FORCE)
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS" CACHE STRING "wx Flags for all builds" FORCE)
endif()


FIND_PACKAGE(wxWidgets REQUIRED core base)
INCLUDE(${wxWidgets_USE_FILE})

add_subdirectory (src)

