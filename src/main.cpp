#include <windows.h>

#include <chrono>
#include <iostream>
#include <map>
#include <string>

#include "headers/csv_parser.h"
#include "headers/data.h"
#include "headers/json_parser.h"

using namespace std;

void ClearScreen() {
#if defined(_WIN32) || defined(_WIN64)
  system("cls");
#else
  system("clear");
#endif
}
int main() {
  // Установить кодировку консоли на UTF-8
  SetConsoleOutputCP(CP_UTF8);

  setlocale(LC_ALL, "en_US.UTF-8");

  int inpt_adrr_cmd;  // команда для получения адреса
  int inpt_data_cmd;  // команда для получения информации

  JsonParser json_parser(
      "E:/Projects/LernProjects/Calculator/src/init/init.json");
  cout << json_parser.GetDescription("description_to_adress_comand");
  cin >> inpt_adrr_cmd;

  cout << json_parser.GetDescription("description_to_DATA_comand");
  cin >> inpt_data_cmd;
  //
  CSV_Parser csv_parser("E:/Projects/LernProjects/Calculator/test/test.csv");
  csv_parser.AddData();

  map<string, Data> cash;
  switch (inpt_adrr_cmd) {
    case ComandAdressSwicer::ALL_ADRESS:
      switch (inpt_data_cmd) {
        /*добавить итоговое значение по полученным данным , добавить
         * форматировщик для вывода в банковоском стиле */
        case ComandDataSwitcher::ALL_DATA:
          cash = csv_parser.Get_Info(inpt_adrr_cmd, inpt_data_cmd);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "проданно на сумму: \t\t" << i.second.ammount << " руб."
                 << '\n'
                 << "оплачено банк.картой: \t\t" << i.second.banc_card
                 << " руб." << '\n'
                 << "оплачено купюрами: \t\t" << i.second.bills << " руб."
                 << '\n'
                 << "выплачено сдачи: \t\t" << i.second.change << " руб."
                 << '\n'
                 << "оплачено клиетн.картой: \t" << i.second.client_card
                 << " руб." << '\n'
                 << "оплачено монетами: \t\t" << i.second.coins << " руб."
                 << '\n'
                 << "оплачено моб.приложением: \t" << i.second.mobile_aplicat
                 << " руб." << '\n'
                 << "проданно воды: \t\t\t" << i.second.sold_water << " литров "
                 << "\n\n";
          }
          break;
        case ComandDataSwitcher::SOLD_WATER:
          cash = csv_parser.Get_Info(inpt_adrr_cmd, inpt_data_cmd);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "проданно воды: \t\t\t" << i.second.sold_water << " литров "
                 << "\n\n";
          }
          break;
        case ComandDataSwitcher::AMMOUNT:
          cash = csv_parser.Get_Info(inpt_adrr_cmd, inpt_data_cmd);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "проданно на сумму: \t\t" << i.second.ammount << " руб."
                 << "\n\n";
          }
          break;

        case ComandDataSwitcher::BILLS:
          cash = csv_parser.Get_Info(inpt_adrr_cmd, ComandDataSwitcher::BILLS);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "оплачено купюрами: \t\t" << i.second.bills << " руб."
                 << "\n\n";
          }
          break;

        case ComandDataSwitcher::COINS:
          cash = csv_parser.Get_Info(inpt_adrr_cmd, ComandDataSwitcher::COINS);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "оплачено монетами: \t\t" << i.second.coins << " руб."
                 << "\n\n";
          }
          break;

        case ComandDataSwitcher::BANC_CARD:
          cash =
              csv_parser.Get_Info(inpt_adrr_cmd, ComandDataSwitcher::BANC_CARD);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "оплачено банк.картой: \t\t" << i.second.banc_card
                 << " руб."
                 << "\n\n";
          }
          break;

        case ComandDataSwitcher::CLIENT_CARD:
          cash = csv_parser.Get_Info(inpt_adrr_cmd,
                                     ComandDataSwitcher::CLIENT_CARD);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "оплачено клиетн.картой: \t" << i.second.client_card
                 << " руб."
                 << "\n\n";
          }
          break;

        case ComandDataSwitcher::MOBILE_APPLICAT:
          cash = csv_parser.Get_Info(inpt_adrr_cmd,
                                     ComandDataSwitcher::MOBILE_APPLICAT);
          ClearScreen();
          for (const auto &i : cash) {
            cout << "адресс аппарата: " << i.first << '\n'
                 << "оплачено моб.приложением: \t" << i.second.mobile_aplicat
                 << " руб."
                 << "\n\n";
          }
          break;

        default:
          cerr << "Неизвестная команда" << endl;
          break;
      }
      break;

    case ComandAdressSwicer::KNISHA_15:
      break;

    default:
      cerr << "Неизвестная команда" << endl;
      break;
  }
  // Sleep(5000000); //пока отключен

  return 0;
}
