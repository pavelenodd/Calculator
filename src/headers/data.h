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
  string adress;         // адресс аппарата
  Day day;               // день продажи воды
  float bills;           // оплачено купюрами
  float coins;           // оплачено монетами
  float banc_card;       // оплачено банк.картой
  float client_card;     // оплачено клиетн.картой
  float mobile_aplicat;  // оплачено моб.приложением
  float change;          // выплачено сдачи
  float ammount;         // проданно на сумму
  float sold_water;      // проданно воды
};
