//
// Created by asphox on 09/10/18.
//

#ifndef TIM561_TIM561_H
#define TIM561_TIM561_H

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <array>
#include "../../basic_com/include/TelegramScan.h"
#include "DataPoint.h"
#include "../../../Lidar.hpp"

/**
 * \class TIM561
 * \brief Controller for TIM561 Sick Lidar
 * \author SOTON "Asphox" Dylan
 * \contact dylan.soton@telecom-sudparis.eu
 */
class TIM561 : public Lidar
{
public:

    /**
    * \public
    * \brief Number of data received
    */
    constexpr static uint16_t NBR_DATA             = 808;

    /**
    * \public
    * \fn TIM561::TIM561()
    * \brief Default constructor of TIM561
    *
    * \param None
    * \return None
    */
    TIM561() = default;

    /**
    * \public
    * \fn TIM561::~TIM561()
    * \brief Destructor of TIM561
    *
    * \param None
    * \return None
    */
    ~TIM561();

    /**
    * \public
    * \fn bool TIM561::connect(const std::string& ip, int port)
    * \brief Connects to the TIM561 lidar with @ip and TCP port
    *
    * \param ip : IP address formed by a std::string
    * \return the state of the connection, true( connected ), false( not connected )
    */
    bool connect(const std::string& ip, int port);

    /**
    * \public
    * \fn void TIM561::close()
    * \brief Closes the socket between the lidar and the app
    *
    * \param None
    * \return void
    */
    void close();

    /**
    * \public
    * \fn bool TIM561::start()
    * \brief Sets the correct access mode and starts the laser rotation.
    *
    * \param None
    * \return bool : Validation of the start process, true( started ), false( not started )
    */
    bool start();

    /**
    * \public
    * \fn bool TIM561::update()
    * \brief Updates measurements and recovers them from lidar (max freq call : 15Hz)
    *
    * \param None
    * \return void
    */
    void update();

    /**
    * \public
    * \fn const std::vector<DataPoint>& TIM561::getDataPoints() const
    * \brief Get all the dataPoints from the current measure
    *
    * \param None
    * \return const reference array containing all datapoints
    */
    const std::array<DataPoint,NBR_DATA>& getDataPoints() const;

    /**
    * \public
    * \brief The number of steps between -45 degrees and 225 degrees
    */
    constexpr static const float STEP_ANGLE        = 0.3345719;



private:

    /**
    * \private
    * \fn bool TIM561::updateDataPoints()
    * \brief Creates the new vector of dataPoints from the last scan received
    *
    * \param None
    * \return void
    */
    void updateDataPoints();

    /**
    * \private
    * \fn bool TIM561::read(uint16_t nbrBytesRequired = 0)
    * \brief Reads "nbrBytesRequired" bytes on the socket. If set to 0, reads until the end character (0x03) is encounter
    *
    * \param nbrBytesRequired : Number of bytes to read on the socket
    * \return void
    */
    void read(uint16_t nbrBytesRequired = 0);

    /**
    * \private
    * \fn bool TIM561::write(const std::string& str)
    * \brief Write a string on the socket
    *
    * \param str : string to write
    * \return bool : write succeed or not
    */
    bool write(const std::string&);

    /**
    * \private
    * \fn bool TIM561::login(const char id[] , const char pwd[] , uint8_t access_id)
    * \brief Logs to mode "id" with password "pwd" and change the access_id to "access_id"
    *
    * \param id : C-string containing the mode ID
    * \param pwd : C-string containing the password of the mode
    * \param access_id : new number id
    * \return bool : logged or not
    */
    bool login( const char id[] , const char pwd[] , uint8_t access_id );

    /**
    * \private
    * \fn bool TIM561::loginAsClient()
    * \brief Logs as client access mode
    *
    * \param None
    * \return bool : logged or not
    */
    bool loginAsClient();

    /**
    * \private
    * \fn bool TIM561::loginAsService()
    * \brief Logs as service access mode
    *
    * \param None
    * \return bool : logged or not
    */
    bool loginAsService();

    /**
    * \private
    * \fn bool TIM561::loginAsMaintenance()
    * \brief Logs as maintenance access mode
    *
    * \param None
    * \return bool : logged or not
    */
    bool loginAsMaintenance();

    /**
    * \private
    * \brief Represents the characteristics of the TCP socket
    */
    sockaddr_in m_socketDescriptor;

    /**
    * \private
    * \brief Identification of the socket
    */
    int m_socketId;

    /**
    * \private
    * \brief Current access mode (5:default 4:service 3:client 2:maintenance)
    */
    uint8_t m_currentAccessMode = 5;

    /**
    * \private
    * \brief Buffer for the socket read
    */
    std::string buffer;

    /**
    * \private
    * \brief Last scan data receive
    */
    TelegramScan currentScan;

    /**
    * \private
    * \brief Start character transmission
    */
    constexpr static const char STX = 0x02;

    /**
    * \private
    * \brief End character transmission
    */
    constexpr static const char ETX = 0x03;

    /**
    * \private
    * \brief Client mode password string
    */
    constexpr static const char* CLIENT_PWD = "F4724744";

    /**
    * \private
    * \brief Client mode id string
    */
    constexpr static const char* CLIENT_ID = "03";

    /**
    * \private
    * \brief Service mode password string
    */
    constexpr static const char* SERVICE_PWD = "81BE23AA";

    /**
    * \private
    * \brief Service mode id string
    */
    constexpr static const char* SERVICE_ID = "04";

    /**
   * \private
   * \brief Maintenance mode password string
   */
    constexpr static const char* MAINTENANCE_PWD = "B21ACE26";

    /**
   * \private
   * \brief Maintenance mode id string
   */
    constexpr static const char* MAINTENANCE_ID = "02";

    /**
   * \private
   * \brief Order to get a continuous measure
   */
    constexpr static const char* CONTINUOUS_MEASURE= "sRN LMDscandata 1";

    /**
   * \private
   * \brief Order to run the lidar
   */
    constexpr static const char* RUN               = "sMN Run";

    /**
   * \private
   * \brief Order to log in a specific access mode
   */
    constexpr static const char* LOGIN             = "sMN SetAccessMode";

    /**
    * \private
    * \brief Array containing all the current DataPoints (angle+distance)
    */
    std::array<DataPoint,NBR_DATA> currentDataPoints;
};


#endif //TIM561_TIM561_H
