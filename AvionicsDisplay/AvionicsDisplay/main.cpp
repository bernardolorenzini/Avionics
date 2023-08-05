//
//  main.c
//  AvionicsDisplay
//
//  Created by Bernardo Lorenzini on 05/08/23.
//

#include <stdio.h>

#include "render.hpp"



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    InitProgram();
    MainLoop();
    
    CleanUp();
    
    return 0;
}
