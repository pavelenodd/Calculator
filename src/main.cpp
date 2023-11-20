#include <iostream>
#include <string>

#include "headers/json_parser.h"

using namespace std;

int main() {
  setlocale(LC_ALL, "");
  string input_data;
  JsonParser json_parser(
      "E:\\Projects\\CPP_Projects\\Calculator\\src\\init\\init.json");
  cout << json_parser.GetDescription() << endl;
  cin >> input_data;
  while (true) {
    if (input_data == "q" || input_data == "Q") {
      break;
    }
    // json_parser.
  }
}
