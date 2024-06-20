#ifndef CAMERA_H
#define CAMERA_H

#include <stdbool.h>
#include <cglm/cglm.h>

/**
 * @brief Camera-Keyboard direction keys.
 *
 * Representation of camera movement using a keyboard.
 */
typedef enum {
    FORWARD,                  ///< Key: W
    BACKWARD,                 ///< Key: S
    LEFT,                     ///< Key: A
    RIGHT                     ///< Key: D
} Direction;

/**
 * @brief Camera structure.
 *
 * Contains all the information you need about your camera data.
 */
typedef struct {
    vec3 position;            ///< Camera position in world space.
    vec3 front;               ///< The direction in which the camera is pointing.
    vec3 up;                  ///< Camera "top" vector.
    float yaw;                ///< Camera rotation angle around the Y axis (left-right). Azimuth angle.
    float pitch;              ///< Camera rotation angle around the X axis (up-down). Elevation angle.
    float speed;              ///< Camera movement speed.
    float sensitivity;        ///< Camera sensitivity to mouse movement.
    float zoom;               ///< Camera zoom level.
} Camera;

/**
 * @brief Initialize camera information such as position, speed, angles, etc.
 *
 * @param camera Camera Pointer.
 * @param position Camera start position.
 */
void initCamera(Camera* camera, vec3 position);

/**
 * @brief Get view matrix.
 * 
 * @param camera Camera pointer.
 * @param view View matrix.
 */
void getViewMatrix(Camera* camera, mat4 view);

void getProjectionMatrix(Camera* camera, mat4 projection, float aspectRatio);
void processKeyboard(Camera* camera, Direction direction, float deltaTime);
void processMouseMovement(Camera* camera, float xoffset, float yoffset, bool constrainPitch);

#endif //CAMERA_H
