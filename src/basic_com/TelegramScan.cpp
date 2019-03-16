//
// Created by asphox on 10/10/18.
//

#include "basic_com/TelegramScan.h"

const std::string& TelegramScan::getCommandType() const
{
    return part[COMMAND_TYPE];
}

const std::string& TelegramScan::getCommand() const
{
    return part[COMMAND];
}

uint16_t TelegramScan::getVersion() const
{
    return std::stoul(part[VERSION],nullptr,16);
}


uint16_t TelegramScan::getDeviceNumber() const
{
    return std::stoul(part[DEVICE_NUMBER],nullptr,16);
}

uint32_t TelegramScan::getSerialNumber() const
{
    return std::stoul(part[SERIAL_NUMBER],nullptr,16);
}

uint8_t  TelegramScan::getDeviceStatus() const
{
    return std::stoul(part[DEVIS_STATUS],nullptr,16);
}

uint16_t TelegramScan::getTelegramCounter() const
{
    return std::stoul(part[TELEGRAM_COUNTER],nullptr,16);
}

uint16_t TelegramScan::getScanCounter() const
{
    return std::stoul(part[SCAN_COUNTER],nullptr,16);
}

uint32_t TelegramScan::getTimeSinceStartup() const
{
    return std::stoul(part[TIME_SINCE_START],nullptr,16);
}

uint32_t TelegramScan::getTimeTransmission() const
{
    return std::stoul(part[TIME_TRANSMISSION],nullptr,16);
}

uint32_t TelegramScan::getScanFreq() const
{
    return std::stoul(part[SCAN_FREQ],nullptr,16);
}

uint32_t TelegramScan::getMesFreq() const
{
    return std::stoul(part[MES_FREQ],nullptr,16);
}

const std::string& TelegramScan::getContent() const
{
    return part[CONTENT];
}

float TelegramScan::getScaleFactor() const
{
    uint32_t tmp = std::stoul(part[SCALE_FACTOR],nullptr,16);
    std::cout << tmp << std::endl;
    return *(reinterpret_cast<float*>(&tmp));
}

uint32_t TelegramScan::getStartAngle() const
{
    return std::stoul(part[START_ANGLE],nullptr,16);
}

uint16_t TelegramScan::getAngularStep() const
{
    return std::stoul(part[ANGULAR_STEP,nullptr,16]);
}

uint16_t TelegramScan::getAmountData() const
{
    return std::stoul(part[AMOUNT_DATA],nullptr,16);
}