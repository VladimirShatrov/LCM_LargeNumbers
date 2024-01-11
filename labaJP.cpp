#include "Header.h"
//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
//Языки программирования ИКМ задача - 27 найти НОК двух чисел > 10^11
int main()
{
    string first_num, second_num;
    while (true) // проверка на корректность ввода
    {
        cout << "Enter first number: ";
        cin >> first_num;
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
        if (c != first_num.size())
            first_num = "";
        else
            break;
    }

    while (true)
    {
        cout << endl << "Enter second number: ";
        cin >> second_num;
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
        if (c != second_num.size())
            second_num = "";
        else
            break;
    }


    //приводим числа к равной длине
    while (first_num.size() > second_num.size())
        second_num = "0" + second_num;
    while (first_num.size() < second_num.size())
        first_num = "0" + first_num;

    string res = remove_LeadingZeros(divide_longNumbers(multiplay_longNumbers(first_num, second_num), greatest_common_divisor(first_num, second_num))); // nok = (a * b) / nod(a,b)

    cout << endl << "least common multiple of those two numbers: ";
    for (int i = 0; i < res.size(); i++)
        cout << res[i];
    return 0;
}
