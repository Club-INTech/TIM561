//
// Created by asphox on 10/10/18.
//

#ifndef TIM561_TELEGRAM_H
#define TIM561_TELEGRAM_H

#include <iostream>
#include <vector>
#include <string>

/**
 * \struct TelegramScan
 * \brief Contains and parse received data
 * \author SOTON "Asphox" Dylan
 * \contact dylan.soton@telecom-sudparis.eu
 */
struct TelegramScan
{
    /**
     * \public
    * \enum ID
    * \brief Position of the information in the received data
    */
    enum ID
    {
        COMMAND_TYPE=0,
        COMMAND=1,
        VERSION=2,
        DEVICE_NUMBER=3,
        SERIAL_NUMBER=4,
        DEVIS_STATUS=5,
        TELEGRAM_COUNTER=6,
        SCAN_COUNTER=7,
        TIME_SINCE_START=8,
        TIME_TRANSMISSION=9,
        //10-11-12 always 0
        SCAN_FREQ=13,
        MES_FREQ=14,
        //15 always 0
        //16 always 1
        CONTENT=20,
        SCALE_FACTOR=21,
        //22 always 0
        START_ANGLE=23,
        ANGULAR_STEP=24,
        AMOUNT_DATA=25,
        DATA_1=26
    };

    /**
    * \public
    * \brief Contains all parts of the received message
    */
    std::vector<std::string> part;

    const std::string& getCommandType() const;
    const std::string& getCommand() const;
    uint16_t getVersion() const;
    uint16_t getDeviceNumber() const;
    uint32_t getSerialNumber() const;
    uint8_t  getDeviceStatus() const;
    uint16_t getTelegramCounter() const;
    uint16_t getScanCounter() const;
    uint32_t getTimeSinceStartup() const;
    uint32_t getTimeTransmission() const;
    uint32_t getScanFreq() const;
    uint32_t getMesFreq() const;
    const std::string& getContent() const;
    float    getScaleFactor() const;
    uint32_t getStartAngle() const;
    uint16_t getAngularStep() const;
    uint16_t getAmountData() const;
};

#endif //TIM561_TELEGRAM_H
