#include "Header.h"

//Языки программирования ИКМ задача - 27 найти НОК двух чисел > 10^11
int main()
{
    string first_num, second_num;
    while (true) // проверка на корректность ввода
    {
        cout << "Enter first number: ";
        cin >> first_num;
        cout << endl;
        int c = 0;
        for (int i = 0; i < first_num.size(); i++)
        {
            switch (first_num[i])
            {
            case '0': c++; break;
            case '1': c++; break;
            case '2': c++; break;
            case '3': c++; break;
            case '4': c++; break;
            case '5': c++; break;
            case '6': c++; break;
            case '7': c++; break;
            case '8': c++; break;
            case '9': c++; break;
            default: break;
            }
        }
        if (c < first_num.size())
        {
            first_num = "";
            cout << "Incorrect enter, try again" << endl;
        }
        else
        {
            if (!a_larger_or_equal_b(first_num, "100000000000"))
            {
                first_num = "";
                cout << "Too small number, try again" << endl;
            }
            else
                break;// число введено корректно
        }
    }

    while (true)
    {
        cout << "Enter second number: ";
        cin >> second_num;
        cout << endl;
        int c = 0;
        for (int i = 0; i < second_num.size(); i++)
        {
            switch (second_num[i])
            {
            case '0': c++; break;
            case '1': c++; break;
            case '2': c++; break;
            case '3': c++; break;
            case '4': c++; break;
            case '5': c++; break;
            case '6': c++; break;
            case '7': c++; break;
            case '8': c++; break;
            case '9': c++; break;
            default: break;
            }
        }
        if (c < second_num.size())
        {
            second_num = "";
            cout << "Incorrect enter, try again" << endl;
        }
        else
        {
            if (!a_larger_or_equal_b(second_num, "100000000000"))
            {
                second_num = "";
                cout << "Too small number, try again" << endl;
            }
            else
                break;
        }
    }

    if (!a_larger_or_equal_b(first_num, second_num))
        swap(first_num, second_num);

    string res = remove_LeadingZeros(divide_longNumbers(multiply_longNumbers(first_num, second_num), greatest_common_divisor(first_num, second_num))); // nok = (a * b) / nod(a,b)
    cout << endl << "Least common multiple of those two numbers: ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    return 0;
}