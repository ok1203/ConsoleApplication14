//
// Created by Professional on 09.11.2021.
//

#ifndef HW10WEEK_TASK2_H
#define HW10WEEK_TASK2_H
#include <string>
#include <fstream>
#include <ostream>
#include <iostream>
#include <mutex>
using namespace std;

class Task2 {
public:

    Task2(const string& name) {
        obj.open( name );
    }
    ~Task2() {
        obj.close();
    }

    void calculateAvg(){
        double number;
        double avg = 0;
        double count = 0;
        if(obj.is_open()){
            cout<< "File is opened" << endl;
            while (obj >> number){
              avg = avg + number;
              count++;
            }
            avg = avg/count;
            average = avg;
            cout << "The average of this file is: " << avg << endl;
        }

    }

    void writeResultToFiles() {
      lock_guard<mutex> lockGuard(mu);

      obj.clear();
      obj.seekg(0);
      cout << obj.tellg();

      ofstream obj2{"Thread_1.txt"};
      ofstream obj3{"Thread_2.txt"};

      string newNumber;
      while(getline(obj, newNumber)) {
        if (stod(newNumber) > average) {
          obj2 << newNumber;
        } else {
          obj3 << newNumber;
        }

      }
      obj.close();
      obj2.close();
      obj3.close();
    }

private:
  mutex mu;
  ifstream obj;
  double average{};
};


#endif //HW10WEEK_TASK2_H
