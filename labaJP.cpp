#include "Header.h"
//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
//Языки программирования ИКМ задача - 27 найти НОК двух чисел > 10^11
int main()
{
    string first_num, second_num;
    cout << "Enter first number: ";
    cin >> first_num;
    cout << endl << "Enter second number: ";
    cin >> second_num;
    //приводим числа к равной длине
    while (first_num.size() > second_num.size())
        second_num = "0" + second_num;
    while (first_num.size() < second_num.size())
        first_num = "0" + first_num;


    int* array_a = new int[first_num.size() / 9 + 1];
    from_string_to_array(first_num, array_a);
    int* array_b = new int[second_num.size() / 9 + 1];
    from_string_to_array(second_num, array_b);
    int* sun = sum_longNumbers(array_a, array_b, first_num.size() / 9 + 1, second_num.size() / 9 + 1);
    for (int i = first_num.size() / 9 + 1; i >= 0; i--)
        cout << sun[i];


    delete[]sun;
    delete[]array_a;
    delete[]array_b;
    return 0;
}
