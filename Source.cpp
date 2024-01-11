#include <iostream>
#include <string>


using namespace std;


void from_string_to_array(string a, int* array)
{
	for (int i = 0; i < a.size(); i++)
		array[a.size() - i - 1] = a[i] - '0';
}


int* multiplay_longNumbers(int* a, int* b, int len)
{
	int* result = new int[2 * len]; // макс. длина произведения = сумме длинн чисел 
	for (int i = 0; i < 2 * len; i++)
		result[i] = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			result[(i + j)] += a[i] * b[j];
		}
	return result;
}


int* sum_longNumbers(int* a, int* b, int len)
{
	
	int* result = new int[len + 1]; // макс длина суммы = длина макс слагаемого + 1
	for (int i = 0; i < len + 1; i++)
		result[i] = 0;
	int ost = 0;
	for (int i = 0; i < len; i++)
	{
		result[i] = (a[i] + b[i] + ost) % 10;
		ost = (a[i] + b[i] + ost) / 10;
	}
	return result;
}


int* subtraction_longNumbers(int* a, int* b, int len)
{
	int is_a_eq_b = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
		{
			is_a_eq_b = 0;
			break;
		}

	}

	int* result = new int[len];
	for (int i = 0; i < len; i++)
		result[i] = 0;

	if (is_a_eq_b) // если a = b возвращаем 0
		return result;

	for (int i = 0; i < len; i++)
	{
		result[i] = a[i] - b[i];
		if (result[i] < 0)
		{
			result[i] += 10;
			a[i + 1]--;
		}
	}
	return result;
}


bool a_larger_or_equal_b(int* a, int* b, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
			return true;
		if (a[i] < b[i])
			return false;
	}
	return true;// a == b
}


bool a_equal_b(int* a, int* b, int len)
{
	for (int i = len - 1; i >= 0; i--)
	{
		if (a[i] > b[i])
			return false;
		if (a[i] < b[i])
			return false;
	}
	return true;
}


int* divide_longNumbers(int* a, int* b, int len)
{
	int* result = new int[len];
	int* one_massive = new int[len];
	for (int i = 0; i < len; i++)
	{
		result[i] = 0;
		one_massive[i] = 0;
	}
	one_massive[0] = 1;

	while (a_larger_or_equal_b(a, b, len)) // пока a >= b; a = a - b; result += 1;
	{
		a = subtraction_longNumbers(a, b, len);
		result = sum_longNumbers(result, one_massive, len);
	}
	delete[] one_massive;
	return result;
}



int* greatest_common_divisor(int* a, int* b, int len)
{
	if (a_equal_b(a, b, len))
		return b;
	if (a_larger_or_equal_b(a, b, len)) // a не может равнятся b т.к. функция вернула бы b строкой выше
		return greatest_common_divisor(subtraction_longNumbers(a, b, len), b, len);
	return greatest_common_divisor(subtraction_longNumbers(b, a, len), a, len);
}
