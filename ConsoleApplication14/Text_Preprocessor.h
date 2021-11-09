#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

class Text_Preprocessor
{
public:
  explicit Text_Preprocessor(const string& name);
	~Text_Preprocessor();

	void preprocess_text();

	int search_word(const string& str);

private:
  ifstream inFile;
  string line;
  stringstream buffer;
};