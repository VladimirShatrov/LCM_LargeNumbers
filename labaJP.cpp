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


    long long int* array_a = new long long int[first_num.size() / 9 + 1];
    long long int* array_b = new long long int[second_num.size() / 9 + 1];
    for (int i = 0; i < first_num.size() / 9 + 1; i++)
    {
        array_a[i] = 0;
        array_b[i] = 0;
    }
    from_string_to_array(first_num, array_a); // запись строк в массивы по 9 цифр
    from_string_to_array(second_num, array_b);
    long long int* sun = divide_longNumbers(array_a, array_b, (first_num.size() / 9 + 1));
    cout << endl;
    bool is_neznach_zero = true;
    for (int i = (first_num.size() / 9 + 1) - 1; i >= 0; i--)
    {
        if ((sun[i] == 0) and (!is_neznach_zero))
            for (int j = 1; j <= 9; j++)
                cout << sun[i];
        else
        {
            cout << sun[i];
            if (sun[i] != 0)
                is_neznach_zero = false;
        }
    }

    delete[]sun;
    delete[]array_a;
    delete[]array_b;
    return 0;
}
