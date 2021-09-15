#include <iostream>
#include <fstream>

/*
 Реализуйте программу чтения информации из ведомости по учёту выплат. Сама ведомость представляет собой следующую таблицу:
- имя и фамилия человека;
- количество денег, которые были выплачены лицу;
- дата выплаты в формате ДД.ММ.ГГГГ.
 На основе данных из ведомости следует подсчитать общее количество выплаченных средств
 и определить человека с максимальной суммой выплат.

Пример данных ведомости:

Tom Hanks 35500 10.11.2020
Rebecca Williams 85000 1.1.2021
Sally Field 15600 15.8.2021
Michael Humphreys 29400 23.5.2020
Harold Herthum 74300 9.6.2019
George Kelly 45000 12.3.2018
Bob Penny 12500 13.5.2020
John Randall 23400 2.10.2020
Sam Anderson 6500 15.7.2020
Margo Moorer 12350 24.2.2019
 */

int main() {
    std::ifstream file;
    std::string path = "..\\bill.txt";
    file.open(path, std::ios::binary);

    std::string personName, personSurname, personDate;
    int max = 0;
    int sum = 0;

    if(!file.is_open()) {
        std::cout << "Opening file error" << std::endl;
    } else {
        while(!file.eof()) {

            std::string name;
            std::string surname;
            int money;
            std::string date;

            file >> name >> surname >> money >> date;

            sum += money;
            if (money > max) {
                max = money;
                personName = name;
                personSurname = surname;
                personDate = date;
            }
        }
        std::cout << "Total amount is " << sum<< std::endl;
        std::cout << "Person with max payment is " << personName << " " << personSurname << std::endl;
        std::cout << "Max payment is " << max << std::endl;
    }
    file.close();
}
