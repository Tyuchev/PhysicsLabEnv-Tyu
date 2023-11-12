#--------------------------------------------------------------------------
# Manta Raytracer
#--------------------------------------------------------------------------

SET(files_manta
	Raytracer.cpp
	Raytracer.hpp
	MantaSimplePoly.cpp
	MantaSimplePoly.hpp
	)
SOURCE_GROUP("manta" FILES ${files_manta})
	
SET(files_pch ../config.h ../config.cc)
SOURCE_GROUP("pch" FILES ${files_pch})
ADD_LIBRARY(manta STATIC ${files_manta} ${files_pch})
TARGET_PCH(manta ../)
ADD_DEPENDENCIES(comet core exts glew enet)
TARGET_LINK_LIBRARIES(manta PUBLIC engine exts glew enet soloud)
