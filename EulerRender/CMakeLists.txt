add_library(EulerRender SHARED 
    src/Api.h
    src/Euler.h


    src/Application.h
    src/Application.cpp


    src/graphics/Material.h
    src/graphics/Material.cpp
    
    src/graphics/Mesh.h
    src/graphics/Mesh.cpp
    
    src/graphics/MeshMaterial.h
    src/graphics/MeshMaterial.cpp
    
    src/graphics/Model.h
    src/graphics/Model.cpp
    
    src/graphics/Shader.h
    src/graphics/Shader.cpp
    
    src/graphics/Skybox.h
    src/graphics/Skybox.cpp
    
    src/graphics/Texture.h
    src/graphics/Texture.cpp
    
    src/graphics/Vertex.h
    src/graphics/Vertex.cpp
    
    src/graphics/primitives/Cube.h
    src/graphics/primitives/Cube.cpp
    
    src/graphics/primitives/Plane.h
    src/graphics/primitives/Plane.cpp
    
    src/graphics/primitives/Sphere.h
    src/graphics/primitives/Sphere.cpp
    
    src/graphics/shaders/WorldShader.h
    src/graphics/shaders/BasicShader.h


    src/input/GLFWInputHandler.h
    src/input/GLFWInputHandler.cpp

    src/input/Input.h
    src/input/Input.cpp

    src/input/InputHandler.h
    src/input/Key.h


    src/math/Mat4.h
    src/math/Mat4.cpp

    src/math/Quaternion.h
    src/math/Quaternion.cpp

    src/math/Transformation.h
    src/math/Transformation.cpp

    src/math/Vec2.h
    src/math/Vec2.cpp

    src/math/Vec3.h
    src/math/Vec3.cpp


    src/resources/Disposable.h
    src/resources/Resources.h
    src/resources/Resources.cpp


    src/scene/Camera.h
    src/scene/Camera.cpp

    src/scene/Component.h
    src/scene/Component.cpp

    src/scene/DirectionalLight.h
    src/scene/DirectionalLight.cpp

    src/scene/FreeCamera.h
    src/scene/FreeCamera.cpp

    src/scene/Scene.h
    src/scene/Scene.cpp

    src/scene/WorldModel.h
    src/scene/WorldModel.cpp
)

target_compile_definitions(EulerRender PRIVATE 
    EULER_EXPORTS
)

target_include_directories(EulerRender PRIVATE 
    ../thirdparty/assimp/include
    ../thirdparty/glfw/include
    ../thirdparty/stb
    ../thirdparty/glad/include
)

target_link_libraries(EulerRender
    assimp
    glfw
    glad
)

set_target_properties(EulerRender
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "../binaries/"
    LIBRARY_OUTPUT_DIRECTORY "../binaries/"
    RUNTIME_OUTPUT_DIRECTORY "../binaries/"
)