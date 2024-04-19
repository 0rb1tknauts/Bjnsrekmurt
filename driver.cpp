/*
Author: Anthony Hardy, Gabriel, Matthew
Date: 4/12/2024
Purpose: Hash table and linked list classes
Files: parkingLot.h, driver.cpp
*/
#include <iostream>
#include <fstream>
#include "parkingLot.h"
#include "Data.h"

int main() {
//Open file
std::ifstream file("students.txt");
if (!file.is_open()) { //check if file failed to open
    std::cout << "Failed to open the file! :P" << std::endl;
    return 1;
}
/*while (true) {//basically reads each line for data.
    // Read student data
    if (!(std::getline(file, name, '#') &&
          std::getline(file, makeModel, '#') &&
          std::getline(file, plateNum, '#') &&
          std::getline(file, color, '#') &&
          std::getline(file, passTypeStr))) {
        //Checks if at end of file
        if (file.eof()) {
            //End of file
            break;
        } else {
            //Erorr
            std::cerr << "Could not read rest of the file." << std::endl;
            return 1;
        }
    }
    */
//Hashtable object
HashTable<Student> parkingLot;

std::string name, makeModel, plateNum, color, passTypeStr; //Name, make(not really model), plate, color, PASS

while(std::getline(file, name, '#')){
    std::getline(file, makeModel, '#');
    std::getline(file, plateNum, '#');
    std::getline(file, color, '#');
    std::getline(file, passTypeStr);

    //passType to int
    int passTypeINT;
    passTypeINT = std::stoi(passTypeStr); //converts it

    //Figure out pass type
    Student::Pass passType;
    switch (passTypeINT) {
        case 0:
            passType = Student::PURPLE; //uses enum stuff btw!
            break;
        case 1:
            passType = Student::RED;
            break;
        case 2:
            passType = Student::GREEN;
            break;
        default:
            std::cerr << "Invalid pass type: " << passTypeINT << std::endl;
    }

    //vehicle object
    Student::Vehicle vehicle = {makeModel, plateNum, color};

    //Student object
    Student student(name, vehicle, passType);
    parkingLot.insert(student);
}
//Display
parkingLot.display();

//It go bye bye
file.close();

return 0;

}