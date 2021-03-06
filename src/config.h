//
// Created by Michał Łaszczewski on 06/09/16.
//

#ifndef FGFX_CONFIG_H
#define FGFX_CONFIG_H

#ifdef EMSCRIPTEN

  #include <emscripten.h>
  #define fgfx_log(...) emscripten_log(EM_LOG_ERROR, __VA_ARGS__);
  #define FGFX_API EMSCRIPTEN_KEEPALIVE

#endif
#ifdef __ANDROID

  #include <android/asset_manager.h>
  #include <android/asset_manager_jni.h>
  #include <android/log.h>
  #define fgfx_log(...) __android_log_print(ANDROID_LOG_INFO, "FastGFX", __VA_ARGS__);
  #define FGFX_API

#endif
#ifndef EMSCRIPTEN
#ifndef __ANDROID

  #include <stdio.h>
  #define fgfx_log(...) { printf(__VA_ARGS__); printf("\n"); }
  #define FGFX_API

#endif
#endif

#ifdef __USE_OPENGL

  #ifndef EMSCRIPTEN
    #include <GLFW/glfw3.h>
  #define USE_GLFW
  #endif

  #ifdef __APPLE__
    #include <OpenGL/gl.h>
    #include <OpenGL/glu.h>
    #include <OpenGL/glext.h>
  #else
    #include <GL/gl.h>
  #endif

#endif
#ifndef __USE_OPENGL

  #include <GLES2/gl2.h>
  #include <EGL/egl.h>

#endif

#endif //FGFX_CONFIG_H
