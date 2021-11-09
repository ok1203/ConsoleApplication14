#include <iostream>
#include <thread>
#include "Text_Preprocessor.h"
#include "Task2.h"
using namespace std;

int main()
{
    Text_Preprocessor textPreprocessor("../ConsoleApplication14/Tasks/Task_1.txt");
    textPreprocessor.preprocess_text();
    int answer = textPreprocessor.search_word("");
    if(answer != -1) {
      cout << "Word is not found";
    } else {
      cout << answer;
    }

    Task2 task2("../ConsoleApplication14/Tasks/Task_2.txt");
    task2.calculateAvg();

    thread thread1(&Task2::writeResultToFiles, ref(task2));
    thread thread2(&Task2::writeResultToFiles, ref(task2));

    thread1.join();
    thread2.join();
}
