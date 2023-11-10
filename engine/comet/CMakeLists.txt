#--------------------------------------------------------------------------
# Comet Physics Engine
#--------------------------------------------------------------------------

SET(files_comet
	CometSimplePoly.cpp
	CometSimplePoly.hpp
	)
SOURCE_GROUP("comet" FILES ${files_comet})
	
SET(files_pch ../config.h ../config.cc)
SOURCE_GROUP("pch" FILES ${files_pch})
ADD_LIBRARY(comet STATIC ${files_comet} ${files_pch})
TARGET_PCH(comet ../)
ADD_DEPENDENCIES(comet core exts glew enet)
TARGET_LINK_LIBRARIES(comet PUBLIC engine exts glew enet soloud)
