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
 * Initializes the camera with specified starting position and default values for other parameters.
 *
 * @param camera Pointer to a Camera object.
 * @param position Camera start position.
 */
void initCamera(Camera* camera, vec3 position);

/**
 * @brief Get the view matrix for the camera.
 *
 * Calculates the view matrix based on the camera's position, front, and up vectors.
 *
 * @param camera Pointer to a Camera object.
 * @param view Output view matrix of type mat4.
 */
void getViewMatrix(Camera* camera, mat4 view);

/**
 * @brief Get the projection matrix for the camera.
 *
 * Calculates the projection matrix based on the camera's zoom level and the specified aspect ratio.
 *
 * @param camera Pointer to a Camera object.
 * @param projection Output projection matrix of type mat4.
 * @param aspectRatio Ratio of the screen's width to its height.
 */
void getProjectionMatrix(Camera* camera, mat4 projection, float aspectRatio);

/**
 * @brief Process camera movement via keyboard input.
 *
 * Updates the camera's position based on the specified direction and the elapsed time.
 *
 * @param camera Pointer to a Camera object.
 * @param direction Movement direction.
 * @param deltaTime Time interval between the current and previous frame.
 */
void processKeyboard(Camera* camera, Direction direction, float deltaTime);

/**
 * @brief Process camera movement via mouse input.
 *
 * Updates the camera's orientation based on mouse movement.
 *
 * @param camera Pointer to a Camera object.
 * @param xoffset Mouse movement in the X axis.
 * @param yoffset Mouse movement in the Y axis.
 * @param constrainPitch If true, limits the pitch angle to prevent camera flip.
 */
void processMouseMovement(Camera* camera, float xoffset, float yoffset, bool constrainPitch);

#endif //CAMERA_H
