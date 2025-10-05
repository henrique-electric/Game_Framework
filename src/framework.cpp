#include <framework.hpp>

void Engine::windowEventHandler(void) {
    while (SDL_PollEvent(&windowState.mainWinEvent)) {
        switch (windowState.mainWinEvent.type)
        {
        case SDL_EVENT_WINDOW_CLOSE_REQUESTED:
            cleanup();
            exit(0);
            break;

        case SDL_EVENT_KEY_DOWN:
            char keyPressed = windowState.mainWinEvent.key.key;
            this->callbacks.press_callback(keyPressed);
            break;
        

        case SDL_EVENT_KEY_UP:
            char keyReleased = windowState.mainWinEvent.key.key;
            this->callbacks.release_callback(keyReleased);
            break;
        }
    }
}

void Engine::cleanup(void) {
    SDL_DestroyRenderer(windowState.rendHandler);
    SDL_DestroyWindow(windowState.winHandler);
}

Engine::Engine(const char *name, int w, int h)
{
    this->windowState.winHandler = SDL_CreateWindow(name, w, h, 0);
    if (windowState.winHandler == nullptr)
        std::runtime_error("Error creating window");

    this->windowState.rendHandler = SDL_CreateRenderer(windowState.winHandler, RENDERER_NAME);
    if (windowState.rendHandler == nullptr)
        std::runtime_error("Error creating main window renderer");
}

void Engine::setLoop(std::function<void(void)> newMainLoop) {
    this->mainLoop = mainLoop;
}

void Engine::setupHandlers(const KeyboardKeyCallbacks &callbacksPtrs) {
    this->callbacks = {
        .press_callback   = callbacksPtrs.press_callback,
        .release_callback = callbacks.release_callback,
    };
}
