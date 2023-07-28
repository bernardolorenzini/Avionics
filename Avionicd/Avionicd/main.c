//
//  main.c
//  Avionicd
//
//  Created by Bernardo Lorenzini on 28/07/23.
//

#include "global.h"

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    int getStatus;
    getStatus = global.turbine1.power.status = 1;
    
    printf("%d \n", getStatus);
    return 0;
}
