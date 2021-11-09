//
// Created by Professional on 09.11.2021.
//

#include "Task2.h"

Task2::Task2(const string &name) {
  inFile.open(name, std::ifstream::binary);
}

Task2::~Task2() {
  inFile.close();
}

void Task2::calculateAvg() {
  inFile.clear();
  inFile.seekg(0);

  double number;
  double avg = 0;
  double count = 0;
  if(inFile.is_open()){
    while (inFile >> number){
      avg = avg + number;
      count++;
    }
    cout<< "File is opened" << endl;
    avg = avg/count;
    average = avg;
    cout << "The average of this file is: " << avg << endl;
  }
}

void Task2::writeResultToFiles() {
  lock_guard<mutex> lockGuard(mu);

  inFile.clear();
  inFile.seekg(0);

  ofstream outThread2{"../ConsoleApplication14/Threads/Thread_1.txt"};
  ofstream outThread3{"../ConsoleApplication14/Threads/Thread_2.txt"};

  outThread2.seekp(0);
  outThread3.seekp(0);

  string newNumber;
  while(inFile >> newNumber) {
    if (stod(newNumber) > average) {
      outThread2 << newNumber << endl;
    } else {
      outThread3 << newNumber << endl;
    }
  }

  outThread2.close();
  outThread3.close();
}