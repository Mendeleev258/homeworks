#include <iostream>
#include <iomanip>
#include <cmath>
#include <functional>

void print_answer(const char* message, double s);
double sumseries(double x, int n);
double sumseries(double x, double eps, int& i);
template<typename T, typename Predicat>
void Read_and_check(T& x, Predicat condition, const char* message);
int main_menu_choice();


int main()
{
    setlocale(LC_ALL, "Russian");

    short choice;
    do
    {
        choice = main_menu_choice();

        if (choice != 3)
        {
            // input x
            double x;
            Read_and_check(x, [](double x) -> bool {return std::abs(x) < 1; }, "Введите x (|x| < 1): ");

            if (choice == 1)
            {
                // task 1
                int n;
                Read_and_check(n, [](int x) -> bool {return x > 0; }, "Введите количество слагаемых: ");
                print_answer("Приближенное значение", sumseries(x, n));
            }
            else
            {
                // task 2
                double eps, res;
                int i = 0;
                Read_and_check(eps, [](double x) -> bool {return true; }, "Введите точность вычисления: ");
                
                res = sumseries(x, eps, i);
                
                print_answer("Количество слагаемых", i);
                print_answer("Приближенное значение", res);
            }
            print_answer("Точное значение", 1.0 / sqrt(1 + x));

            std::cout << "\nЗавершить работу? (Y/любая клавиша): ";

            char isExit;
            std::cin >> isExit;

            if (isExit == 'Y' || isExit == 'y')
                choice = 3;
        }

    } while (choice != 3);
}




double sumseries(double x, int n)
{
    double s = 0, a = 1;
    for (int i = 0; i < n; ++i)
    {
        s += a;
        a *= -x * (2. * i + 1) / (2. * i + 2);
    }
    return s;
}

double sumseries(double x, double eps, int& i)
{
    double s = 0, a = 1;
    while (std::abs(a) > eps)
    {
        s += a;
        a *= -x * (2. * i + 1) / (2. * i + 2);
        ++i;
    }
    return s;
}

int main_menu_choice()
{
    std::cout << "1. Сумма заданного количества слагаемых\n";
    std::cout << "2. Сумма с заданной точностью\n";
    std::cout << "3. Завершение работы\n";

    std::function<bool(int)> Lambda = [](int x) -> bool {return x >= 1 && x <= 3; };
    int choice = 0;
    Read_and_check(choice, Lambda, ">>> ");
    return choice;
}

void print_answer(const char* message, double s)
{
    if (std::floor(s) == s) 
        std::cout << std::setw(26) << std::left << message << " = " << s << '\n';
    else
        std::cout << std::setw(26) << std::left << message << " = " << std::fixed << std::setprecision(11) << s << '\n';
}

template<typename T, typename Predicat>
void Read_and_check(T& x, Predicat condition, const char* message)
{
    std::cout << message;
    while (!(std::cin >> x && condition(x)))
    {
        std::cout << "Ошибка ввода!\n";
        std::cin.clear();
        std::cin.ignore(std::cin.rdbuf()->in_avail());
        std::cout << message;
    }
}
