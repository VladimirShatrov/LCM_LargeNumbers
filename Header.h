#include <iostream>
#include <vector>

using namespace std;


void from_string_to_array(string a, long long int* array);

long long int* multiplay_longNumbers(long long int* a, long long int* b, int len);

long long int* divide_longNumbers(long long int* a, long long int* b, int len);

long long int* sum_longNumbers(long long int* a, long long int* b, int len);

long long int* subtraction_longNumbers(long long int* a, long long int* b, int len);

bool a_larger_b(long long int* a, long long int* b, int len);

bool a_larger_or_equal_b_oneElement_oneNumber(int* a, int* b);

long long int* mod(long long int* a, long long int* b, int len);

long long int* greatest_common_divisor(long long int* n, long long int* m);

string NOK(long long int* n, long long int* m, long long int* nod);