set(lugdulov_base_SRCS  stationsplugin.cpp station.cpp)
set(lugdulov_base_MOC_HDRS  stationsplugin.h)

qt4_wrap_cpp(lugdulov_base_MOC_SOURCE ${lugdulov_base_MOC_HDRS})

add_convenience_library(lugdulov_base ${lugdulov_base_SRCS} ${lugdulov_base_MOC_SOURCE})

add_subdirectory(lyon)
#add_subdirectory(paris)
#add_subdirectory(skel)
