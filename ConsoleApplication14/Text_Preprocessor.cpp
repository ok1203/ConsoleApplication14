#include "Text_Preprocessor.h"

Text_Preprocessor::Text_Preprocessor(const string &name) {
  inFile.open(name);
}

Text_Preprocessor::~Text_Preprocessor() {
  inFile.close();
}

void Text_Preprocessor::preprocess_text() {
  while (getline(inFile, line)) {
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
    buffer << line << '\n';
  }
}

int Text_Preprocessor::search_word(const string &str) {
  int ret = 0;
  while (getline(buffer, line)) {
    ret++;
    if (line.find(str) != string::npos)
    {
      return ret;
    }
  }

  return -1;
}