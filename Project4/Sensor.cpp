//
//  Sensor.cpp
//  Project4
//
//  Created by Renat Norderhaug on 9/23/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//

#include "Sensor.h"
#include <iostream>
#include <cstring>
#include <cstdio>


using namespace std;

int Sensor::gps_cnt = 0;
int Sensor::camera_cnt = 0;
int Sensor::lidar_cnt = 0;
int Sensor::radar_cnt = 0;

Sensor::Sensor() {
	setType("none");
}

Sensor::Sensor(const char* type) {
	setType(type);
}

const char* Sensor::getType() const {
	return m_type;
}

void Sensor::setType(const char* type){
	if(strcmp("gps", type)) {
		strcpy(m_type, type);
		m_extracost = 5.0;
		gps_cnt++;
	} else if(strcmp("camera", type)) {
		strcpy(m_type, type);
		m_extracost = 10.0;
		camera_cnt++;
	} else if(strcmp("lidar", type)) {
		strcpy(m_type, type);
		m_extracost = 15.0;
		lidar_cnt++;
	} else if(strcmp("radar", type)) {
		strcpy(m_type, type);
		m_extracost = 20.0;
		radar_cnt++;
	} else if(strcmp("none", type)) {
		strcpy(m_type, type);
		m_extracost = 0.0;
	}
}

float Sensor::getExtraCost() const {
	return m_extracost;
}

int Sensor::getGpsCount(){
	return gps_cnt;
}

int Sensor::getCameraCount(){
	return camera_cnt;
}

int Sensor::getLidarCount(){
	return lidar_cnt;
}

int Sensor::getRadarCount(){
	return radar_cnt;
}

void Sensor::resetGpsCount(){
	gps_cnt = 0;
}

void Sensor::resetCameraCount(){
	camera_cnt = 0;
}

void Sensor::resetLidarCount(){
	lidar_cnt = 0;
}

void Sensor::resetRadarCount(){
	radar_cnt=0;
}

void Sensor::printAllSensors() {

  cout << "gps: " << gps_cnt << " ";
  cout << "camera: "<< camera_cnt << " ";
  cout << "lidar: "<< lidar_cnt << " ";
  cout << "radar: " << radar_cnt << " ";
  cout << endl;

}

bool operator == (const Sensor& sensor1, const Sensor& sensor2) {
	return strcmp(sensor1.m_type, sensor2.m_type) == 0;
}
