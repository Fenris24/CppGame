cmake_minimum_required(VERSION 3.28)
project(CppGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS})

add_executable(CppGame Core/main.cpp
        Core/Loop/Game.cpp
        Core/Loop/Game.hpp
        Core/Context/GameContext.cpp
        Core/Context/GameContext.hpp
        Logic/Logic.hpp
        GameElements/Map.cpp
        GameElements/Map.hpp
        GameElements/Entities.cpp
        GameElements/Entities.hpp
        GameElements/Layout.cpp
        GameElements/Layout.hpp
        Persistance/Save.cpp
        Persistance/Save.hpp
        Logic/Game/NewGameLogic.cpp
        Logic/Game/NewGameLogic.hpp
        Logic/Menu/MenuLogic.cpp
        Logic/Menu/MenuLogic.hpp
        Persistance/SaveData/Data.cpp
        Persistance/SaveData/Data.hpp
        Renderer/Renderer.cpp
        Renderer/Renderer.hpp
        Renderer/Canvas/Canvas.cpp
        Renderer/Canvas/Canvas.hpp
        Renderer/Canvas/Graphics/GraphicElement.hpp
        Renderer/TextureManager/TextureManager.cpp
        Renderer/TextureManager/TextureManager.hpp
        Renderer/Canvas/Graphics/TileMap.cpp
        Renderer/Canvas/Graphics/TileMap.hpp
        Renderer/Camera/Camera.hpp
)

target_link_libraries(CppGame SDL2 SDL2_image)