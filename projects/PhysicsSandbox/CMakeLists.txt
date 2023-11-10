#--------------------------------------------------------------------------
# PhysicsSandbox project
#--------------------------------------------------------------------------

PROJECT(PhysicsSandbox)
FILE(GLOB project_headers code/*.hpp)
FILE(GLOB project_sources code/*.cpp)

SET(files_project ${project_headers} ${project_sources})
SOURCE_GROUP("PhysicsSandbox" FILES ${files_project})

ADD_EXECUTABLE(PhysicsSandbox ${files_project})
TARGET_LINK_LIBRARIES(PhysicsSandbox core render)
ADD_DEPENDENCIES(PhysicsSandbox core render)

IF(MSVC)
    set_property(TARGET PhysicsSandbox PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/bin")
ENDIF()