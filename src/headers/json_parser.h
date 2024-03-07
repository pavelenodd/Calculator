#pragma once
#include <fstream>
#include <iostream>
#include <string>

#include "../libs/nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

class JsonParser {
 private:
  ifstream curr_file_;
  const string file_adress_;
  json json_file_;

  void OpenFile(const string& file_adress) {
    curr_file_.open(file_adress);
    if (!curr_file_.is_open()) {
      cerr << "Init File Not Open" << endl;
    } else {
      cerr << "Init File Enabled" << endl;
    }
  }

 public:
  JsonParser(const string& L_file_adress) : file_adress_{L_file_adress} {
    OpenFile(file_adress_);
    curr_file_ >> json_file_;
  };
  ~JsonParser() {
    if (curr_file_.is_open()) {
      curr_file_.close();
    }
  };

  string GetDescription(const string& description_query) {
    vector<string> cash = json_file_[description_query];
    string out;
    for (string str : cash) {
      out += str;
      out += '\n';
    }
    return out;
  }
};