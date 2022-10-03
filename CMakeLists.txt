#--------------------------------------------------------------------------
# spaceengine
#--------------------------------------------------------------------------
PROJECT(spaceengine)
CMAKE_MINIMUM_REQUIRED(VERSION 3.2)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

MACRO(TARGET_PCH target path)
        target_precompile_headers(${target} PRIVATE ${path}config.h)
#IF(WIN32)
#    IF(MSVC)
#        SET_TARGET_PROPERTIES(${target}
#            PROPERTIES 
#            COMPILE_FLAGS "/Yuconfig.h /Fp${CMAKE_CFG_INTDIR}/${target}.pch")
#        SET_SOURCE_FILES_PROPERTIES(${path}config.cc
#            PROPERTIES
#            COMPILE_FLAGS "/Ycconfig.h")
#    ENDIF()
#ENDIF()
ENDMACRO(TARGET_PCH)

SET(OPENGL_LIBS $<$<PLATFORM_ID:Windows>: opengl32.lib>
                $<$<PLATFORM_ID:Linux>: GL GLU X11 Xxf86vm pthread Xrandr Xi Xinerama Xcursor>)

SET(GSCEPT_LAB_ENV_ROOT ${CMAKE_CURRENT_DIR})

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<$<CONFIG:Debug>:${CMAKE_SOURCE_DIR}/bin>)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<$<CONFIG:RelWithDebug>:${CMAKE_SOURCE_DIR}/bin>)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY $<$<CONFIG:Release>:${CMAKE_SOURCE_DIR}/bin>)

SET_PROPERTY(DIRECTORY APPEND PROPERTY COMPILE_DEFINITIONS GLEW_STATIC _CRT_SECURE_NO_WARNINGS _WINSOCK_DEPRECATED_NO_WARNINGS)
ADD_SUBDIRECTORY(exts)
ADD_SUBDIRECTORY(engine)
ADD_SUBDIRECTORY(projects)

