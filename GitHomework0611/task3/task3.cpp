#include <iostream>
#include <string>
#include <fstream>

/*
Дан файл из n целых чисел. В первой строке записаны числа B и n, 
в последующих строках – возрастающая последовательность из n целых чисел. 
Распечатать эту последовательность, вставив число B так, чтобы она осталась возрастающей
*/

int main()
{
    setlocale(LC_ALL, "Russian");

    std::string path = "test.txt";
    
    std::ifstream file;
    file.open(path);

    if (!file.is_open())
    {
        std::cout << "Ошибка открытия файла!\n";
    }
    else 
    {
        std::cout << "Файл открыт\n";

        int i, b, n;
        file >> b;
        file >> n;
        while (file >> i)
        {
            if (i < b) std::cout << i << '\n';
            else
            {
                std::cout << b << '\n' << i << '\n';
                b = INT_MAX;
            }
        }
        if (b != INT_MAX) std::cout << b << '\n';
    }

    file.close();
    return 0;
}

