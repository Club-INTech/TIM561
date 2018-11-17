//
// Created by asphox on 16/10/18.
//

#ifndef TIM561_DATAPOINT_H
#define TIM561_DATAPOINT_H

#include <stdint-gcc.h>

/**
* \struct
* \brief Structure representing a data to compute (angle+distance)
*/
struct DataPoint
{
    float angle = 0;
    uint16_t distance = 0;
};

#endif //TIM561_DATAPOINT_H
