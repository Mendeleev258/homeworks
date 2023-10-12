#include <iostream>
#include <cmath>

using std::cout;
using std::cin;

#define SWAP(x, y) {\
decltype(x) tmp = y;\
y = x;\
x = tmp;}

int main() {
    double x1, x2, x3, y1, y2, y3, a, b, c, S, tmp;
    double eps = 1e-10;

    setlocale(LC_ALL, "Russian");

    cout << "������� ���������� ������ �����\n";
    cout << "x = ";
    cin >> x1;
    cout << "y = ";
    cin >> y1;

    cout << "������� ���������� ������ �����\n";
    cout << "x = ";
    cin >> x2;
    cout << "y = ";
    cin >> y2;

    cout << "������� ���������� ������� �����\n";
    cout << "x = ";
    cin >> x3;
    cout << "y = ";
    cin >> y3;
    cout << '\n';

    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c = sqrt((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1));

    if (a > b) SWAP(a, b);
    if (b > c) SWAP(b, c);
    if (a > b) SWAP(a, b);

    // cout << a << ' ' << b << ' ' << c << '\n';
    // cout << (a * a + b * b - c * c) << '\n';

    if (a + b - c > eps) {
        if (abs(a * a + b * b - c * c) < eps) {
            if (abs(a - b) > eps) {
                S = 0.5 * a * b;
                cout << "����������� ������������� � ��������������\n";
                if (S > c) cout << "������� = " << S << '\n' << "���������� = " << c << '\n' << "������� ����� = " << b << '\n';
                if (S < b) cout << "���������� = " << c << '\n' << "������� ����� = " << b << '\n' << "������� = " << S << '\n';
                if (S > b && S < c) cout << "���������� = " << c << '\n' << "������� = " << S << '\n' << "������� ����� = " << b << "\n";
            }
            else cout << "����������� �������������, �� �� ��������������\n";
        }
        else cout << "����������� �� �������������\n";
    }
    else cout << "�������� ����� ����������� �� ��������\n";

    cin.ignore(cin.rdbuf()->in_avail()).get();
    return 0;
}