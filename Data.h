/*
Author: Anthony Hardy, Gabriel, Matthew
Date: 4/12/2024
Purpose: Hash table and linked list classes
Files: parkingLot.h, driver.cpp, Data.h
*/

#include <iostream>
#include <string>

#ifndef DATA_H
#define DATA_H

class Student { //student class
    public:
        struct Vehicle { //vehicle struct
            std::string makeModel;
            std::string plateNum;
            std::string color;
        };

        enum Pass {
            PURPLE,
            RED,
            GREEN
        }; //the enum takes this stuff and makes it 0, 1, 2!

    private:
        std::string name;
        Vehicle vehicleInfo;
        Pass parkingPass;

    public:
        //constructor
        Student(const std::string& nameStudent, const Vehicle& vehicle, Pass pass) {
             name = nameStudent;
             vehicleInfo = vehicle;
             parkingPass = pass;
        }

        //getters
        std::string getName() const {
            return name;
        }

        Vehicle getVehicleInfo() const {
            return vehicleInfo;
        }

        Pass getPass() const {
            return parkingPass;
        }
        bool operator ==(const int& S) const {
            return S == parkingPass;
        }
        operator int() {
            return parkingPass;
        }
        friend std::ostream&operator <<(std::ostream &output, const Student &S){
           output << S.name << " (" << S.vehicleInfo.makeModel << " " << S.vehicleInfo.color << " " << S.vehicleInfo.plateNum << ")" << std::endl;
           return output;
        }

};


#endif