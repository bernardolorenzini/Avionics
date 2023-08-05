//
//  render.cpp
//  AvionicsDisplay
//
//  Created by Bernardo Lorenzini on 05/08/23.
//



#include <SDL2/SDL.h>
#include <glad/glad.h>

#include <iostream>

#include "../render.hpp"


int height = 640;
int width = 900;

SDL_Window* window = nullptr;
SDL_GLContext context = nullptr;

bool gQuit = false;




void InitProgram(){
    
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "SDL2 could not initialize"<< std::endl;
        exit(1);
    }
    
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    
     window = SDL_CreateWindow("EFIS", 0, 0, width, height, SDL_WINDOW_OPENGL);
    
    if(window == nullptr){
        std::cout << "SDL_window could not open"<< std::endl;
        exit(1);
    }
    
    context = SDL_GL_CreateContext(window);
    
    if(context == nullptr){
        std::cout << "CONTEXT openGL not available" << std::endl;
        exit(1);
    }
    
    //INITIALIZE GLAD
    if(!gladLoadGLLoader(SDL_GL_GetProcAddress)){
        std::cout << "glad not initialize" << std::endl;
        exit(1);
    }
    
    GetGLVersionInfo();
    
};

void MainLoop(){
    
    while(!gQuit){
        
        Input();
        
        PreDraw();
        
        Draw();
        
        
        //update the screen
        SDL_GL_SwapWindow(window);
        
        
    }
    
};

void CleanUp(){
    SDL_DestroyWindow(window);
    SDL_Quit();
    
};


void Input(){
    
    SDL_Event e;
    
    while(SDL_PollEvent(&e) != 0){
        if(e.type == SDL_QUIT){
            std::cout << "SYSTEM SHUT DOWN" << std::endl;
            gQuit = true;
        }
        
    }
    
};

void PreDraw(){};

void Draw(){};

void GetGLVersionInfo(){
    
    std::cout << "Vendor: " << glad_glGetString(GL_VENDOR)<< std::endl;
    std::cout << "Renderer: " << glad_glGetString(GL_RENDERER)<< std::endl;
    std::cout << "Version: " << glad_glGetString(GL_VERSION)<< std::endl;
    std::cout << "Shading Language: " << glad_glGetString(GL_SHADING_LANGUAGE_VERSION)<< std::endl;

};
