//
//  turbine.h
//  Avionicd
//
//  Created by Bernardo Lorenzini on 28/07/23.
//

#ifndef turbine_h
#define turbine_h

#include "power.h"


typedef struct turbine {
    Power power;
    int gas;
    int temperat;
} Turbine;


#endif /* turbine_h */
