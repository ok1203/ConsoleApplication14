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
    explicit Task2(const string& name);
    ~Task2();

    void calculateAvg();

    void writeResultToFiles();

private:
  mutex mu;
  ifstream inFile;
  double average{};
};


#endif //HW10WEEK_TASK2_H
