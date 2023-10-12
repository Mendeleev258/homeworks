#include <iostream>

int main()
{
    setlocale(LC_ALL, "Russian");
    int t;
    bool endflag = 0;
    char answer;

    while (endflag == 0) {
        
        std::cout << "Введите количество треугольников: ";
        std::cin >> t;
        std::cout << "У вас есть ";

        if (t % 10 > 4 and t % 10 <= 9 or t % 10 == 0 or (t % 100 > 10 and t % 100 < 20)) std::cout << t << " треугольников\n";
        else if (t % 10 != 1) std::cout << t << " треугольника\n";
        else std::cout << t << " треугольник\n";
        
        bool correctans = 1;
        while (correctans == 1 and endflag == 0) {
            std::cout << "Завершить выполнение программы? (Y/N)\n-> ";
            std::cin >> answer;
            std::cin.ignore(std::cin.rdbuf()->in_avail());
            if (answer == 'y' or answer == 'Y') endflag = 1;
            if (answer == 'n' or answer == 'N') correctans = 0;
            else correctans = 1;
        }
    }
    
    return 0;
}