#ifndef RENTALCAR_H_
#define RENTALCAR_H_
#include "RentalCar.cpp"
/**
* RentalCar class
*/
class RentalCar {
private:
   int m_year; //year of production
   char m_make[255]; //make of car
   char m_model[255]; //model of car
   float m_price; //price per day
   bool m_available; //whether available
public:
   RentalCar(); //default constructor
   RentalCar(int,const char*,const char*,float,bool); //parameterized constructor
   //getters and setters
   bool isAvailable() const;
   void setAvailable(bool available);
   const char* getMake() const;
   const char* getModel() const;
   float getPrice() const;
   void setPrice(float price);
   int getYear() const;
   void setYear(int year);

   void print(); //prints car data
   float estimateCost(int); //estimates car rental cost

   friend std::istream& operator >> (std::istream& in, RentalCar& car);
};

#endif /* RENTALCAR_H_ */
