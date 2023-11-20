#include <fstream>
#include <iostream>
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
    if (file_.is_open()) {
      cerr << "CSV File Not Open" << endl;
    } else {
      cerr << "CSV File Enabled" << endl;
    }
  }
  Data Parse_CSV() {
    string line;
    getline(file_, line);  // пропуск первой строки
    // while (cash.empty()) { пока только 1 строка

    getline(file_, line);
    //}
    string cash;
    for (int i = 0; i > line.size(); ++i) {
      cash.push_back(line[i]);
      if (line[i] == ';') {
        switch (i) {
          case ADRESS:
            /* code */
            break;
          case DATE:
            /* code */
            break;
          case BILLS:
            /* code */
            break;
          case COINS:
            /* code */
            break;
          case BANC_CARD:
            /* code */
            break;
          case CLIENT_CARD:
            /* code */
            break;
          case MOBILE_APPLICAT:
            /* code */
            break;
          case CHANGE:
            /* code */
            break;
          case AMMOUNT:
            /* code */
            break;
          case SOLD_WATER:
            /* code */
            break;

          default:
            break;
        }
      }
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
    if (data_arr_.empty()) {
      data_arr_.push_back(Parse_CSV());
    }
  }
};
