//
//  global.h
//  Avionicd
//
//  Created by Bernardo Lorenzini on 28/07/23.
//

#ifndef global_h
#define global_h


#include "turbine.h"

#include <stdio.h>



typedef struct global {
    Turbine turbine1;
    Turbine turbine2;
    Render_State_Internal state;
    

} Global;

extern Global global;
#endif /* global_h */
