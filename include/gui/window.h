
#ifndef WINDOW_H
#define WINDOW_H

#include <string>

#include "SDL.h"

class Window{
public:
    Window(std::string, int, int);
    Window(const Window &);
    ~Window();
    Window & operator=(const Window &);
    bool checkClose();
    void render();
    void show();
    void hide();
    std::string getTitle() const;
    int getWidth() const;
    int getHeight() const;
private:
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    bool showWindow;
    std::string title;
    int width, height;
    void createWindow(std::string, int, int);
    void destroyWindow();
};

#endif // WINDOW_H
