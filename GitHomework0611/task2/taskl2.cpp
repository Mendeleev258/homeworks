#include <iostream>
#include <string>
#include <fstream>

/*
Дан файл из n целых чисел. 
Найти сумму чисел, расположенных до последнего четного числа.
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

        int i, tempsum = 0, sum = 0;
        while (file >> i)
        {
            if (abs(i) % 2 != 0)
            {
                tempsum += i;
            }
            else
            {
                sum = tempsum;
                tempsum += i;
            }
        }
        std::cout << sum << '\n';
    }
    
    file.close();
    return 0;
}

