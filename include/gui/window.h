
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
    void show();
    void hide();
    bool checkClose();
    void clearWindow();
    void drawRect(int x, int y, int w, int h);
    void render();
    std::string getTitle() const;
    int getWidth() const;
    int getHeight() const;
private:
    SDL_Window * window = NULL;
    SDL_Renderer * renderer = NULL;
    std::string title;
    int width, height;
    void createWindow(std::string, int, int);
    void destroyWindow();
};

#endif // WINDOW_H
