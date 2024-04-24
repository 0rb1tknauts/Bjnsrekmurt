    /*
    Author: Anthony Hardy, Gabriel, Matthew
    Date: 4/12/2024
    Purpose: Hash table and linked list classes
    Files: parkingLot.h, driver.cpp
    */

    #ifndef PARKINGLOT_H
    #define PARKINGLOT_H

    #include <iostream>
    #include <string>
    #include "Data.h"

    using namespace std; //got lazy


    //Linked list portion
    template<typename T>
    class LinkedList {
        public:
        //node
            struct Node {
                    T data;
                    Node* nextPtr; //next pointer

                    Node(T value) : data(value), nextPtr(nullptr) {}
                    //constructor to set data to value and nextptr to null
            };

        private:

            Node* head; //head of list
            Node* tail; //tail of list

        public:
            //constructor
            LinkedList() { //initializes to nullptr
                head = nullptr;
                tail = nullptr;
            }

            //destructor
            ~LinkedList() {
                Node* current = head;
                while (current != nullptr) {
                    Node* next = current->nextPtr;
                    delete current;
                    current = next;
                }
                head = nullptr;
                tail = nullptr;
            }

            Node* getHead() { //gets head
                return head; //this was needed for something, however, due to time, can't remove it and fix it.
            }

            //append into linked list
            void append(T value) { //this appends new node with given value at the end of the list.
                Node* newNode = new Node(value);
                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                    //alternatively, could do head = tail = newNode;
                } else {
                    tail->nextPtr = newNode;
                    tail = newNode;
                }
            }
            //displays data stored in each node!!! :o
            friend ostream &operator <<(ostream &output, LinkedList &S){
                Node* temp = S.head;
                while (temp != nullptr) {
                    output << temp->data << endl;
                    temp = temp->nextPtr;
                }
                return output;
            }
    };

    //Hash table class

    template<typename T>
    class HashTable {
        private:
            static const int numParkingLots = 3; //static num of parking lots
            LinkedList<T> parking[numParkingLots]; //array of linked lists to store data for each parking lot!

            //hash function to get index
            /*size_t hashFunc(const T& KEY) { //determines index of parking lot
                return KEY.getPass() % numParkingLots;
            }*/

        public:
            //destructor
            ~HashTable() {}
            //insert function
            void insert(const T& value) {
                //size_t index = hashFunc(value);
                size_t index;
                for(int i = 0; i < numParkingLots; i++){
                    if(value == i){
                        index = i;
                    }
                }
                std::cout << "appending student: " << value.getName() << " into parking lot " << index << std::endl;
                parking[index].append(value);
            }

            void display() { //displlay function
                const std::string passColors[] = {"PURPLE", "RED", "GREEN"}; //pass stuff

                for (int i = 0; i < numParkingLots; ++i) { //loop to display everything
                    std::cout << "Parking Lot " << passColors[i] << ":" << std::endl;
                    /*typename LinkedList<T>::Node* current = parking[i].getHead(); //this is where I needed head ;')
                    //the above has current as pointer to the head of parking at i, pointing at the list's start basically.
                    while (current != nullptr) { //prints out information
                        std::cout << current->data.getName() << " (" << current->data.getVehicleInfo().makeModel << " " << current->data.getVehicleInfo().color << " " << current->data.getVehicleInfo().plateNum << ")" << std::endl;
                        current = current->nextPtr;
                    }*/
                    cout << parking[i];

                    std::cout << std::endl; //newline stuff
                }
        }

    };

    #endif