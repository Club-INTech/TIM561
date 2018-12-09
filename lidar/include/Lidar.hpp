#ifndef LIDARS_FUSION_LIDAR_HPP
#define LIDARS_FUSION_LIDAR_HPP

#include <string>
#include <array>
#include "DataPoint.h"

class Lidar {

public:
    constexpr static uint16_t NBR_DATA = 808;

    virtual bool connect(const std::string &ip, int port);

    virtual bool start();

    virtual const std::array<DataPoint, NBR_DATA> &getDataPoints() const;

    virtual void update();

    virtual void close();
};


#endif //LIDARS_FUSION_LIDAR_HPP
