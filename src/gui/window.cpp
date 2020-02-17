
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

void Window::createWindow(std::string title, int width, int height)
{
    showWindow = false;
    this->title = title;
    this->width = width;
    this->height = height;
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
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

void Window::render()
{
    if(showWindow){
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer);
    /*
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderDrawPoint(renderer, 10, 10);
    */
        SDL_RenderPresent(renderer);
    }
}

void Window::show()
{
    showWindow = true;
}

void Window::hide()
{
    showWindow = false;
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
