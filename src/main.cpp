#include <iostream>
#include <string>

#include "libs/nlohmann/json.hpp"
using namespace std;
using json = nlohmann::json;

class JsonParser {
 private:
  const string file_adress_;
  json json_file_;

 public:
  JsonParser(const string& s) : file_adress_(s) { cout << "test"; };
  void Test() { cout << file_adress_ << endl; }
};
int main() {
  JsonParser json_parser("src\\init\\init.json");
  json_parser.Test();
}