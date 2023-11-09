#include <iostream>
#include <string>
#include <fstream>

/*
Дан файл из n целых чисел. Найти количество положительных чисел, 
расположенных после последнего числа, оканчивающегося на 7
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
        
        int i;
        int count = 0;
        bool c7 = false;
        while (file >> i)
        {
            if ((abs(i) % 10 != 7) && (i > 0))
            {
                ++count;
            }
            if (abs(i) % 10 == 7)
            {
                count = 0;
                c7 = true;
            }
        }
        if (c7 == false) count = 0;
        std::cout << count << '\n';
    }
    
    file.close();
    return 0;
}

