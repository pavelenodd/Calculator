#pragma once
#include <string>

using namespace std;
struct Day {
  int year = 0;
  int month = 0;
  int day = 0;
  int hours = 0;
  int minutes = 0;
};
struct Data {
  string adress;             // адресс аппарата
  Day day;                   // день продажи воды
  float bills = 0;           // оплачено купюрами
  float coins = 0;           // оплачено монетами
  float banc_card = 0;       // оплачено банк.картой
  float client_card = 0;     // оплачено клиетн.картой
  float mobile_aplicat = 0;  // оплачено моб.приложением
  float change = 0;          // выплачено сдачи
  float ammount = 0;         // проданно на сумму
  float sold_water = 0;      // проданно воды
};
enum ComandAdressSwicer {
  ALL_ADRESS = 0,   // все адреса аппаратов
  KNISHA_15 = 1,    // Генерала Кныша, д 15
  NOVOSELOV_7 = 2,  // Новоселов, д 7
  ZVEREVOI_3 = 3,   // ул Зверевой, д 3
};
enum ComandDataSwitcher {
  ALL_DATA = 0,         // все данные
  SOLD_WATER = 1,       // проданно воды
  AMMOUNT = 2,          // проданно на сумму
  BILLS = 3,            // купюрами
  COINS = 4,            // монетами
  BANC_CARD = 5,        // банк.картой
  CLIENT_CARD = 6,      // клиентской картой
  MOBILE_APPLICAT = 7,  // моб приложентием
};
enum TypeInfo {
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