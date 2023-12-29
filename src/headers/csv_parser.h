#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "data.h"
using namespace std;

class CSV_Parser {
 private:
  enum ComandSwitcher {
    ADRESS = 1,           // адресс
    DATA_DATE = 3,        // день
    BILLS = 4,            // купюрами
    COINS = 5,            // монетами
    BANC_CARD = 6,        // банк.картой
    CLIENT_CARD = 7,      // клиентской картой
    MOBILE_APPLICAT = 8,  // моб приложентием
    CHANGE = 9,           // сдача
    AMMOUNT = 10,         // проданно на сумму
    SOLD_WATER = 11,      // проданно воды

  };
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
          if (cash != ";" || cash.size() > 1) {
            if (cash[0] == ';') {
              cash.erase(0, 1);
            }
            if (cash[cash.size() - 1] == ';') {
              cash.pop_back();
            }
          }
          switch (collum) {
            case ADRESS:
              L_data.adress = cash;
              cash.clear();
              ++collum;
              break;
            case DATA_DATE:
              /* будет позже  */
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
  map<string, Data> Get_Info(const int comand_adress, const int comand_info) {
    // нужен для получения информации из data_arr_
    const map<int, string> L_comand_adress_switch{
        {0, "all"},
        {1, "г Гатчина, ул Генерала Кныша, д 15"},
        {2, "г Гатчина, ул Новоселов, д 7"},
        {3, "г Гатчина, ул Авиатриссы Зверевой, д 3"}};
    const string comand = L_comand_adress_switch.at(comand_adress);
    map<string, Data> result{
        {"г Гатчина, ул Генерала Кныша, д 15", Data{}},
        {"г Гатчина, ул Новоселов, д 7", Data{}},
        {"г Гатчина, ул Авиатриссы Зверевой, д 3", Data{}}};
    if (data_arr_.empty()) {
      cerr << "файл пуст" << endl;
      abort();
    }
    if (comand == "all") {
      for (const auto& L_data : data_arr_) {
        result.at(L_data.adress).ammount += L_data.ammount;
        result.at(L_data.adress).banc_card += L_data.banc_card;
        result.at(L_data.adress).bills += L_data.bills;
        result.at(L_data.adress).change += L_data.change;
        result.at(L_data.adress).client_card += L_data.client_card;
        result.at(L_data.adress).coins += L_data.coins;
        result.at(L_data.adress).mobile_aplicat += L_data.mobile_aplicat;
        result.at(L_data.adress).sold_water += L_data.sold_water;
      }
    }

    return result;
  }
};
