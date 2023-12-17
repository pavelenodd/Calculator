#include <iostream>
#include <string>

#include "headers/csv_parser.h"
#include "headers/json_parser.h"

using namespace std;
enum ComandAdressSwicer {
  ALL = 0,          // все адреса
  KNISHA_15 = 1,    // Генерала Кныша, д 15
  NOVOSELOV_7 = 2,  // Новоселов, д 7
  ZVEREVOI_3 = 3,   // ул Зверевой, д 3
};
enum ComandDataSwitcher {
  GET_ALL = 0,
};
int main() {
  setlocale(LC_ALL, "");

  int inpt_adrr_cmd;  // команда для получения адреса
  int inpt_data_cmd;  // команда для получения информации
  string switch_comand;
  JsonParser json_parser(
      "E:\\Projects\\CPP_Projects\\Calculator\\src\\init\\init.json");
  cout << json_parser.GetDescription();
  cin >> inpt_adrr_cmd;
  cin >> inpt_data_cmd;
  //
  CSV_Parser csv_parser(
      "E:\\Projects\\CPP_Projects\\Calculator\\test\\test.csv");
  csv_parser.AddData();

  /*while (true) {
    if (input_data == "q" || input_data == "Q") {
      break;
    }
  }*/
  switch (inpt_adrr_cmd) {
    case ComandAdressSwicer::ALL:
      switch (inpt_data_cmd) {
        case ComandDataSwitcher::GET_ALL:
          cout << csv_parser.Get_Info(ALL, GET_ALL) << endl;
          break;

        default:
          break;
      }
      break;

    default:
      break;
  }
}
