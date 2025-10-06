//
//  window.hpp
//  Game
//
//  Created by BaianoDaBahia on 03/10/25.
//

#pragma once
#include <iostream>
#include <exception>
#include <functional>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <types.hpp>
#include <utils.hpp>

struct SDL_State {
    SDL_Window *winHandler;
    SDL_Renderer *rendHandler;
    SDL_Event mainWinEvent;
};

struct KeyboardKeyCallbacks {
    key_press_handler press_callback;
    key_release_handler release_callback;
};

class Engine {
    private:
        SDL_State windowState;
        KeyboardKeyCallbacks callbacks;

        std::function<void(void)> mainLoop;

        void cleanup(void);
        void windowEventHandler(void);
        void refreshScreen(void);
        
        public:
        void setLoop(std::function<void(void)> newMainLoop);
        void setupHandlers(const KeyboardKeyCallbacks &callbacksPtrs);
        void run(void);
        Engine(const char *name, int w, int h);
};

