
#include "../../include/gui/window.h"

#include <stdexcept>

Window::Window(std::string title, int width, int height)
{
    createWindow(title, width, height);
}

Window::Window(const Window & w)
{
    createWindow(w.getTitle(), w.getWidth(), w.getHeight());
}

Window::~Window()
{
    destroyWindow();
}

Window & Window::operator=(const Window & w)
{
    if(this != &w){
        destroyWindow();
        createWindow(w.getTitle(), w.getWidth(), w.getHeight());
    }

    return *this;
}

void Window::show()
{
    SDL_ShowWindow(window);
}

void Window::hide()
{
    SDL_HideWindow(window);
}

void Window::createWindow(std::string title, int width, int height)
{
    this->title = title;
    this->width = width;
    this->height = height;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_HIDDEN);
    if(window == NULL){
        throw std::runtime_error("Error: Could not create window.");
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == NULL){
        throw std::runtime_error("Error: Could not create renderer for window.");
    }
}

void Window::destroyWindow()
{
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
    SDL_DestroyWindow(window);
    window = NULL;
}

bool Window::checkClose()
{
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        if(event.type == SDL_QUIT){
            return true;
        }
    }

    return false;
}

void Window::clearWindow()
{
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
}

void Window::drawRect(int x, int y, int w, int h)
{
    SDL_Rect rect = {x, y, w, h};
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &rect);
}

void Window::render()
{
    SDL_RenderPresent(renderer);
}

std::string Window::getTitle() const
{
    return title;
}

int Window::getWidth() const
{
    return width;
}

int Window::getHeight() const
{
    return height;
}
