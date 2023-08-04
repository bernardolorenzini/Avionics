// On linux compile with:
// g++ -std=c++17 main.cpp -o prog -lSDL2

// C++ Standard Libraries
#include <iostream>

// Third-party library
#include <SDL2/SDL.h>

#include "render.h"



int main(int argc, char* argv[]){

    InitializeProgram();
    
    MainLoop();
    
    CleanUp();
    
    
}
