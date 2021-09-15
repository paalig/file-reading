#include <iostream>
#include <fstream>

/*
 Составьте небольшой текстовый файл «words.txt», в котором последовательно,
 через пробелы и переносы строк расположены различные слова. Можете использовать любые англоязычные слова.
 Разработайте программу, которая искала бы среди этих слов нужное пользователю
 и выводила бы общее количество повторений этого слова. 0 — если слово вообще не присутствует в файле.
 */

int main() {

    std::ifstream words;
    words.open("..\\words.txt", std::ios::binary);

    if (!words.is_open()) {
        std::cout << "Wrong file path" << std::endl;
    } else {
        std::string text;
        int count = 0;
        while (!words.eof()) {
            words >> text;
            if (text == "text") {
                count++;
            }
        }
        std::cout << count;
    }
    words.close();
}