//
// Created by Professional on 09.11.2021.
//

#ifndef HW10WEEK_TASK2_H
#define HW10WEEK_TASK2_H
#include <string>
#include <fstream>
#include "ostream"
#include "iostream"
using namespace std;

class Task2 {
public:
    ifstream obj{"../Task_2.txt"};

    Task2(const string& name) {
        obj.open( name );
    }
    ~Task2() {
        obj.close();
    }

    void calculateAvg(){
        double number;
        int amountOfNumbers = 0;
        double avg = 0;
        double count = 0;
        if(obj.is_open()){
            cout<< "File is opened" << endl;
            while (!obj.eof()){
                obj >> number;
                amountOfNumbers = amountOfNumbers + number;
                count++;
            }
            avg = amountOfNumbers/count;

            cout << "The average of this file is: " << avg << endl;

        }
        ofstream obj2{"Thread_1.txt"};
        ofstream obj3{"Thread_2.txt"};

            string newNumber;
            while(getline(obj, newNumber)) {
                if (stod(newNumber) > avg) {
                    obj2 << newNumber;
                } else obj3 << newNumber;

            }
        obj.close();
        obj2.close();
        obj3.close();
    }




};


#endif //HW10WEEK_TASK2_H
