#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "data.h"
using namespace std;
enum ComandSwitcher {
  ADRESS = 1,           // адресс
  DATE = 3,             // день
  BILLS = 4,            // купюрами
  COINS = 5,            // монетами
  BANC_CARD = 6,        // банк.картой
  CLIENT_CARD = 7,      // клиентской картой
  MOBILE_APPLICAT = 8,  // моб приложентием
  CHANGE = 9,           // сдача
  AMMOUNT = 10,         // итого
  SOLD_WATER = 11,      // проданно воды

};

class CSV_Parser {
 private:
  ifstream file_;
  vector<Data> data_arr_;
  void OpenFile(const string& file_adress) {
    file_.open(file_adress);
    if (!file_.is_open()) {
      cerr << "CSV File Not Open" << endl;
    } else {
      cerr << "CSV File Enabled" << endl;
    }
  }
  void Parse_CSV() {
    string line;
    getline(file_, line);  // пропуск первой строки

    while (file_.peek() != EOF) {  // проверка не достигнут конец строки
      getline(file_, line);
      string cash;
      Data L_data;
      int collum = 1;
      for (int i = 0; line.size() > i; ++i) {
        cash.push_back(line[i]);
        if (line[i + 1] == ';') {
          i += 2;
          switch (collum) {
            case ADRESS:
              L_data.adress = cash;
              cash.clear();
              ++collum;
              break;
            case DATE:
              /* code */
              cash.clear();
              ++collum;
              break;
            case BILLS:
              L_data.bills = stof(cash);
              cash.clear();
              ++collum;
              break;
            case COINS:
              L_data.coins = stof(cash);
              cash.clear();
              ++collum;
              break;
            case BANC_CARD:
              L_data.banc_card = stof(cash);
              cash.clear();
              ++collum;
              break;
            case CLIENT_CARD:
              L_data.client_card = stof(cash);
              cash.clear();
              ++collum;
              break;
            case MOBILE_APPLICAT:
              L_data.mobile_aplicat = stof(cash);
              cash.clear();
              ++collum;
              break;
            case CHANGE:
              L_data.change = stof(cash);
              cash.clear();
              ++collum;
              break;
            case AMMOUNT:
              L_data.ammount = stof(cash);
              cash.clear();
              ++collum;
              break;
            case SOLD_WATER:
              L_data.sold_water = stof(cash);
              cash.clear();
              ++collum;
              break;
            default:
              cash.clear();
              ++collum;
              break;
          }
        }
      }
      data_arr_.push_back(L_data);
      collum = 1;
      cash.clear();
    }
  }

 public:
  CSV_Parser(const string& file_adress) { OpenFile(file_adress); };
  ~CSV_Parser() {
    if (file_.is_open()) {
      file_.close();
    }
  };
  void AddData() {
    if (!data_arr_.empty()) {
      data_arr_.clear();
    }
    Parse_CSV();
  }
  string Get_Info(const int comand_adress, const int comand_info) const {
    const map<int, string> L_comand_adress_switch{
        {0, "all"},
        {1, "г Гатчина, ул Генерала Кныша, д 15"},
        {2, "г Гатчина, ул Новоселов, д 7"},
        {3, "г Гатчина, ул Авиатриссы Зверевой, д 3"}};
    const string comand = L_comand_adress_switch.at(comand_adress);
    string out;
    if (comand == "all") {
      for (Data L_data : data_arr_) {
        out += L_data.adress;
        out.push_back('\n');
      }
    } else {
      for (Data L_data : data_arr_) {
        if (L_data.adress == comand) {
          out += L_data.adress;
          out.push_back('\n');
        }
      }
    }

    return out;
  }
};
