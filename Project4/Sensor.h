//
//  Sensor.h
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#ifndef Sensor_h
#define Sensor_h

#include <stdio.h>

class Sensor {

private:
    char m_type[255]; //name of sensor type- gps, camera, lidar, radar, none
    float m_extracost; //additional rent cost per day for the car that carries the sensor
    void setType(const char* type);

public:
    static int gps_cnt; //a static int member (keeps track of existing gps-type sensors)
    static int camera_cnt; //a static int member (keeps track of existing camera-type sensors)
    static int lidar_cnt; //a static int member (keeps track of existing lidar-type sensors)
    static int radar_cnt; //a static int member (keeps track of existing radar-type sensors)
    Sensor();
    Sensor(const char*);
    //Get/Set methods for appropriate data member(s)
    const char* getType() const;
    float getExtraCost() const;
    //A Get and a Reset static member function to return and to reset each of the static member variables
    int getGpsCount();
    int getCameraCount();
    int getLidarCount();
    int getRadarCount();
    void resetGpsCount();
    void resetCameraCount();
    void resetLidarCount();
    void resetRadarCount();
    void printAllSensors();
    //A Method to check if 2 Sensor Objects are the same. You should make this an operator overload of (operator==).
    friend bool operator==(const Sensor& sensor1, const Sensor& seonsor2);
};

#endif // Sensor_h
