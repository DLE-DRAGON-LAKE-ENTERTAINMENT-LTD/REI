#pragma once

#include <stdint.h>

#ifndef __ANDROID__
#include <SDL2/SDL_events.h>
#else
typedef struct
{
} SDL_Event;
#endif

#include "REI/Renderer/Renderer.h"
#include "REI_Integration/ResourceLoader.h"

struct SDL_Window;

struct REI_Renderer;
struct REI_Queue;
struct REI_Fence;
struct REI_Semaphore;
struct REI_Cmd;
struct REI_Texture;
struct REI_SwapchainDesc;

extern SDL_Window*   window;
extern REI_Renderer* renderer;
extern REI_Queue*    gfxQueue;

enum
{
    FRAME_COUNT = 2,
};

struct FrameData
{
    uint64_t     dt;
    REI_Texture* backBuffer;
    uint32_t     setIndex;
    uint32_t     bbWidth;
    uint32_t     bbHeight;
    uint32_t     winWidth;
    uint32_t     winHeight;
};

int  sample_on_init();
void sample_on_fini();
void sample_on_swapchain_init(const REI_SwapchainDesc* swapchainDesc);
void sample_on_swapchain_fini();
void sample_on_event(SDL_Event* evt);
void sample_on_frame(const FrameData* frameDesc);

uint64_t sample_time_ns();
void     sample_quit();

void sample_request_screenshot();
void sample_cmdPrepareBackbuffer(REI_Cmd* cmd, REI_Texture* backbuffer, REI_ResourceState startState);
void sample_submit(REI_Cmd* pCmd);

enum DirectoryEnum
{
    DIRECTORY_DATA,

    DIRECTORY_COUNT
};

const char* sample_get_path(DirectoryEnum dir, const char* path, char* out, size_t size);

bool sample_mouse_was_wheel_up();
bool sample_mouse_was_wheel_down();
bool sample_key_is_pressed(int32_t key);
bool sample_key_was_pressed(int32_t key);
bool sample_key_is_released (int32_t key);
bool sample_key_was_released(int32_t key);
bool sample_mouse_is_pressed(int32_t button);
bool sample_mouse_was_pressed(int32_t button);
bool sample_mouse_is_released(int32_t button);
bool sample_mouse_was_released(int32_t button);
void sample_mouse_rel_offset(int32_t* dx, int32_t* dy);
void sample_mouse_abs_offset(int32_t* x, int32_t* y);
void sample_capture_mouse();
void sample_release_mouse();
bool sample_mouse_is_captured();

struct SimpleCamera;

void sample_update_simple_camera_with_input(SimpleCamera* cam);
