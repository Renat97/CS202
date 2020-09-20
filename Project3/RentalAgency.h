//
//  RentalAgency.h
//  Project 5
//
//  Created by Renat Norderhaug on 9/10/17.
//  Copyright © 2017 Renat Norderhaug. All rights reserved.
//


#ifndef RENTALAGENCY_H_
#define RENTALAGENCY_H_

#include "RentalCar.h"

//RentalAgency ADT

typedef struct {
   char name[255]; //name of agency
   int zipcode[5]; //zipcode of agency
   RentalCar inventory[5]; //inventory of rental agency i.e. number of cars with rental agency
} RentalAgency;

#endif /* RENTALAGENCY_H_ */
