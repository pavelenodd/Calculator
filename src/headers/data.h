#pragma once
#include <string>

using namespace std;
struct Day {
  int year;
  int month;
  int day;
  int hours;
  int minutes;
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
