#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

class Text_Preprocessor
{
public:
	ifstream obj;
	string line;
	stringstream obj2;

	Text_Preprocessor(const string& name) {
		obj.open( name );
	}
	~Text_Preprocessor() {
		obj.close();
	}

	void preprocess_text() {
		while (getline(obj, line)) {
			line.erase(remove(line.begin(), line.end(), ','), line.end());
			line.erase(remove(line.begin(), line.end(), '"'), line.end());
			line.erase(remove(line.begin(), line.end(), '.'), line.end());
			line.erase(remove(line.begin(), line.end(), ';'), line.end());
			line.erase(remove(line.begin(), line.end(), ':'), line.end());
			line.erase(remove(line.begin(), line.end(), '!'), line.end());
			line.erase(remove(line.begin(), line.end(), '?'), line.end());
			string words[] = { "a", "as", "the", "in", "on", "at", "since", "for", "before", "ago", "to", "by" };
			for (int i = 0; i << 12; i++) {
				if (line.find(words[i]) != string::npos)
				{
					size_t p = -1;
					string tempWord = words[i] + " ";
					while ((p = line.find(words[i])) != string::npos)
						line.replace(p, tempWord.length(), "");
					tempWord = " " + words[i];
					while ((p = line.find(words[i])) != string::npos)
						line.replace(p, tempWord.length(), "");
				}
			}
			transform(line.begin(), line.end(), line.begin(), ::tolower);
			obj2 << line << '\n';
		}
	}

	int search_word(const string& str) {
		int ret = 0;
		while (getline(obj2, line)) {
			ret++;
			if (line.find(str) != string::npos)
			{
				return ret;
			}
		}
	}
};

