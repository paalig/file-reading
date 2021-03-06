#include <iostream>
#include <fstream>

/*
 Разработайте простейший просмотрщик текстовых файлов.
 В начале программы пользователь вводит путь к текстовому файлу, который требуется открыть и просмотреть.
 Внутренности файла необходимо вывести в стандартный вывод.
 Программа должна работать для любых текстовых файлов в формате TXT, но вы можете создать и свой отдельный файл для теста.
 Главное, чтобы файл был англоязычным, дабы избежать проблем с кодировками.

Советы и рекомендации
- Для проверки того, был ли на самом деле открыт файл, используйте метод is_open.
 Он вернёт true, если файл был благополучно открыт, и false, если что-то пошло не так, к примеру, если путь к файлу невалидный.
- Файл надо считывать постепенно, отдельными фрагментами, ведь он может быть весьма большим.
 Для этого лучше всего пользоваться методом gcount, так как он ещё вернёт количество байт,
 которые были считаны по факту методом read.
 Сами эти фрагменты могут храниться в специальном буфере, как и в примере из лекций,
 но его размер и второй аргумент к функции read надо рассчитать так, чтобы выводились все символы, без обрезки последней буквы.
- Файл можно открыть в бинарном формате.
 */

int main() {
    std::ifstream file;
    std::string path;

    std::cout << "Input file path:" << std::endl;
    std::cin >> path;
    file.open(path, std::ios::binary);
    //  "C:\\Users\\Ana\\ClionProjects\\file-reading\\001_Task1\\words.txt"

    char buffer[20];
    if (!file.is_open()) {
        std::cout << "Wrong file path" << std::endl;
    } else {
        int a = 19;
        while(file.is_open() && !file.eof()) {
            file.read(buffer, a);
            a = file.gcount();
            buffer[a] = 0;
            std::cout << buffer;
        }
    }
    file.close();
}
