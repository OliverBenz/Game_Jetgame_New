add_library(models SHARED
	entity.hpp entity.cpp
	player.hpp player.cpp
	bullet.hpp bullet.cpp
)

add_library(app SHARED
	app.hpp app.cpp
	evHandler.hpp evHandler.cpp
)
