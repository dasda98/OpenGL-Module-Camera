# OpenGL-Module-Camera

This is an OpenGL module for handling the camera. 
It is one of many modules that can be connected independently of each other.

## Features

### Control

- [x] WASD keyboard
- [x] Mouse control
- [ ] Scroll zoom

### Other

- [ ] Bézier curve
- [ ] NURBS

## Usage

Example of use and function calls:

```c++
    ...
    Camera camera;
    
    vec3 cameraPos = {0.0f, 0.0f, 3.0f};
    initCamera(&camera, cameraPos);
    
    // For example using view, projection, model
    mat4 view, projection, model;
    glm_mat4_identity(model);
    ...
    while (!glfwWindowShouldClose(window)) {
        ...
        getViewMatrix(&camera, view);
        getProjectionMatrix(&camera, projection, (float)(WIDTH/HEIGHT));
        
        // Uniforms
        // Render
        ...    
    }
    
```