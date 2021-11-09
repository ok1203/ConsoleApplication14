#include <iostream>
#include "Text_Preprocessor.h"
#include "Task2.h"
#include <iostream>
using namespace std;

int main()
{
    Text_Preprocessor txtchk("Task_1.txt");
    txtchk.preprocess_text();
    cout << txtchk.search_word("tiniest");
//  cout << txtchk.obj2.str();

}
