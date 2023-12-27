#include <windows.h>

#include <iostream>
#include <map>
#include <string>

#include "headers/csv_parser.h"
#include "headers/data.h"
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
  // Установить кодировку консоли на UTF-8
  SetConsoleOutputCP(CP_UTF8);

  setlocale(LC_ALL, "en_US.UTF-8");

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
  map<string, Data> cash;
  switch (inpt_adrr_cmd) {
    case ComandAdressSwicer::ALL:
      switch (inpt_data_cmd) {
        case ComandDataSwitcher::GET_ALL:

          cash = csv_parser.Get_Info(inpt_adrr_cmd, inpt_data_cmd);
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "проданно на сумму: \t\t" << i.second.ammount << '\n'
                 << "оплачено банк.картой: \t\t" << i.second.banc_card << '\n'
                 << "оплачено купюрами: \t\t" << i.second.bills << '\n'
                 << "выплачено сдачи: \t\t" << i.second.change << '\n'
                 << "оплачено клиетн.картой: \t" << i.second.client_card << '\n'
                 << "оплачено монетами: \t\t" << i.second.coins << '\n'
                 << "оплачено моб.приложением: \t" << i.second.mobile_aplicat
                 << '\n'
                 << "проданно воды: \t\t\t" << i.second.sold_water << "\n\n";
          }

          break;

        default:
          break;
      }
      break;

    default:
      break;
  }
}
