#include <iostream>
#include <vector>
#include <fstream>

/*
 Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе, который сейчас играет.
Всего таких секторов 13. Сектор выбирается так: с клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане.
Исходя из этого офсета вычисляется новый активный сектор, который и будет играть в этом ходе.
Если выпавший сектор уже играл, выбирает следующий неигравший за ним. В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то есть считывается из файла данного сектора.
Вопрос показывается на экране.
После того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот ответ с помощью стандартного ввода.
То, что он ввёл, сравнивается с ответом, который хранится во втором файле, ассоциированном с активным сектором.
Данный файл должен содержать лишь одно слово-ответ.
Если ответ знатока-игрока был правильным, ему начисляется один балл. Если неверен, то балл уходит телезрителям.
Игра продолжается до тех пор, пока или игрок, или зрители не наберут шесть баллов.
После этого называется победитель и программа заканчивает работу.

 */
std::vector<int> field;

std::vector<int> InitField(std::vector<int> vec) {
    for (int i = 1; i < 14; i++) {
        vec.push_back(i);
    }
    return vec;
}

int ChangeSector(int pos, int delta) {
    int a = field.size();
    int step = (pos + delta) % a;
    while (field[step] == 99) {
        step = (step + 1) % a;
    }
    std::cout << "Current position is " << field[step] << std::endl;
    field[step] = 99;
    return step;
}

bool CheckField(std::vector<int> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 99) {
            return true;
        }
    }
    return false;
}

bool CheckWinner (int a, int b) {
    return !(a == 6 || b == 6);
}

int main() {
    field = InitField(field);
    std::vector<std::string> answers;
    std::vector<std::string> questions;
    std::ifstream quest;
    std::ifstream ans;
    quest.open("C:\\Users\\Ana\\ClionProjects\\file-reading\\005_Task5\\questions.txt", std::ios::binary);
    ans.open("C:\\Users\\Ana\\ClionProjects\\file-reading\\005_Task5\\answers.txt", std::ios::binary);


    if (!quest.is_open() || !ans.is_open()) {
        std::cout << "Wrong file path" << std::endl;
    } else {
        std::string str;
        while (!ans.eof()) {
            ans >> str;
            answers.push_back(str);
        }
        ans.close();

        std::string str2;
        std::string phrase;
        while (!quest.eof()) {
            do {
                quest >> str2;
                phrase += str2;
                phrase += " ";
            } while (str2[str2.length() - 1] != '?');
            questions.push_back(phrase);
            phrase = "";
        }
        quest.close();

        int pos = 0;
        int delta;
        int playerPoints = 0;
        int audiencePoints = 0;
        std::string playerAnswer;

        while (CheckField(field) && CheckWinner(playerPoints, audiencePoints)) {
            std::cout << "Input new delta" << std::endl;
            std::cin >> delta;
            pos = ChangeSector(pos, delta);
            std::cout << questions[pos] << std::endl;
            std::cout << "Input your answer: " << std::endl;
            std::cin >> playerAnswer;
            if (playerAnswer == answers[pos]) {
                playerPoints++;
            } else {
                audiencePoints++;
            }
            std::cout << "Player points: " << playerPoints << " " << "Audience points: " << audiencePoints << std::endl;
        }

        std::cout << "Game finished. The winner is: ";
        if (playerPoints == 6) {
            std::cout << "Player" << std::endl;
        } else if (audiencePoints == 6){
            std::cout << "Audience" << std::endl;
        } else {
            std::cout << "Nobody" << std::endl;
        }
    }
}
