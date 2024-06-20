/**********************************************************************************************************************
 * Copyright (c) Prophesee S.A.                                                                                       *
 *                                                                                                                    *
 * Licensed under the Apache License, Version 2.0 (the "License");                                                    *
 * you may not use this file except in compliance with the License.                                                   *
 * You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0                                 *
 * Unless required by applicable law or agreed to in writing, software distributed under the License is distributed   *
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.                      *
 * See the License for the specific language governing permissions and limitations under the License.                 *
 **********************************************************************************************************************/

#ifndef METAVISION_SDK_UI_UTILS_OPENGL_API
#define METAVISION_SDK_UI_UTILS_OPENGL_API

// While we keep support for OpenGL, we need to provide a
// dummy implementation for Glew init function
#ifndef GLEW_OK
#define GLEW_OK 0
inline int glewInit(void) {
    return GLEW_OK;
}
#endif

#ifdef _USE_OPENGL_ES3_
#include <GLES3/gl3.h>
#else // OpenGL
#if defined(__APPLE__) && !defined(__linux__)
#include <OpenGL/glu.h>
#include <OpenGL/gl3.h>
#elif defined(__linux__)
#include <GL/glew.h>
#include <GL/gl.h>
#endif
#endif

// GLFW need to be included after OpenGL
#include <GLFW/glfw3.h>

#endif // METAVISION_SDK_UI_UTILS_OPENGL_API
