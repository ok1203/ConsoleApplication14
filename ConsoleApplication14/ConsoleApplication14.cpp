#include <iostream>
#include <thread>
#include "Text_Preprocessor.h"
#include "Task2.h"
using namespace std;

int main()
{
    Task2 task2("Task_2.txt");
    task2.calculateAvg();

    thread thread1(&Task2::writeResultToFiles, ref(task2));
    thread thread2(&Task2::writeResultToFiles, ref(task2));

    thread1.join();
    thread2.join();
}
