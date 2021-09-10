#include <iostream>
#include <fstream>
#include <vector>

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
    std::string path = "C:\\Users\\Ana\\ClionProjects\\file-reading\\003_Task3\\bill.txt";
    file.open(path, std::ios::binary);

    std::vector<std::string> firstName;
    std::vector<std::string> lastName;
    std::vector<int> purse;
    std::vector<std::string> dates;

    if(!file.is_open()) {
        std::cout << "Opening file error" << std::endl;
    } else {
        while(!file.eof()) {
            std::string name;
            std::string surname;
            int money;
            std::string date;

            file >> name >> surname >> money >> date;

            firstName.push_back(name);
            lastName.push_back(surname);
            purse.push_back(money);
            dates.push_back(date);
        }
        int amount = 0;
        for (int i = 0; i < purse.size(); i++) {
            amount += purse[i];
        }
        std::cout << "Total amount is " << amount << std::endl;

        int max = 0;
        int number;
        for (int i = 0; i < purse.size(); i++) {
            if (purse[i] > max) {
                max = purse[i];
                number = i;
            }
        }
        std::cout << "Person with max payment is " << firstName[number] << " " << lastName[number] << std::endl;
        std::cout << "Max payment is " << purse[number] << std::endl;
    }
    file.close();
}
