#include <iostream>
#include <string>


using namespace std;

//в функциях int len = a.size() / 9 + 1 т.к. строки провдятся к равной длине (поэтому не важно b.size() или a.size()) и записываются в массивы по 9 цифр (поэтому делим на 9) если a.size() % 9 != 0 выделяем память на доп. цифры 
string remove_LeadingZeros(string a)
{
	string res;
	int index = 0;
	for (int i = 0; i < a.size(); i++)
		if (a[i] != '0')
		{
			index = i;
			break;
		}
	for (int i = index; i < a.size(); i++)
		res += a[i];
	return res;
}


long long int* from_string_to_array_9(string a)
{
	string sub_string;
	long long int* array = new long long int[a.size() / 9 + 1];
	for (int i = 0; i < a.size() / 9 + 1; i++)
		array[i] = 0;
	int j;
	int pos = 0;
	for (int i = a.size() - 10; i >= 0; i -= 9)
	{
		sub_string = "";
		j = 1;
		while ((j <= 9) and (i + j < a.size()))
		{
			sub_string += a[i + j];
			j++;
		}
		array[pos] = atoi(sub_string.c_str());
		pos++;
	}
	if (a.size() % 9 != 0) 
	{
		sub_string = "";
		for (int i = 0; i < a.size() % 9; i++)
			sub_string += a[i];
		array[pos] = atoi(sub_string.c_str());
	}
	return array;
}


int* from_string_to_array(string a)
{
	int* array = new int[a.size()];
	for (int i = 0; i < a.size(); i++)
		array[i] = 0;
	for (int i = 0; i < a.size(); i++)
		array[a.size() - i - 1] = a[i] - '0';
	return array;
}


string multiplay_longNumbers(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;
	long long int* array_a = from_string_to_array_9(a);
	long long int* array_b = from_string_to_array_9(b);
	int len = a.size() / 9 + 1;

	long long int* array_result = new long long int[2 * len]; // макс. длина произведения = сумме длинн чисел 
	for (int i = 0; i < 2 * len; i++)
		array_result[i] = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			array_result[i + j] += (array_a[i] * array_b[j]) % 1000000000;
			if (array_result[i + j] > 999999999)
			{
				array_result[i + j + 1] += array_result[i + j] / 1000000000;
				array_result[i + j] = array_result[i + j] % 1000000000;
			}
			array_result[i + j + 1] += (array_a[i] * array_b[j]) / 1000000000;
		}

	string result;
	for (int i = 2 * len - 1; i >= 0; i--)
		result += to_string(array_result[i]);

	delete[] array_result;
	delete[] array_a;
	delete[] array_b;
	return result;
}


string sum_longNumbers(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;
	long long int* array_a = from_string_to_array_9(a);
	long long int* array_b = from_string_to_array_9(b);
	int len = a.size() / 9 + 1;
	
	long long int* result = new long long int[len + 1]; // макс длина суммы = длина макс слагаемого + 1
	for (int i = 0; i < len + 1; i++)
		result[i] = 0;
	int ost = 0;
	for (int i = 0; i < len; i++)
	{
		result[i] = (array_a[i] + array_b[i] + ost) % 1000000000;
		ost = (array_a[i] + array_b[i] + ost) / 1000000000;
	}

	string res;

	for (int i = len; i >= 0; i--)
		res += to_string(result[i]);

	delete[] result;
	delete[] array_a;
	delete[] array_b;
	return res;
}


string subtraction_longNumbers(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;
	long long int* array_a = from_string_to_array_9(a);
	long long int* array_b = from_string_to_array_9(b);
	int len = a.size() / 9 + 1;

	int is_a_eq_b = 1;
	for (int i = len - 1; i >= 0; i--)
	{
		if (array_a[i] > array_b[i])
		{
			is_a_eq_b = 0;
			break;
		}

	}

	string res;

	long long int* result = new long long int[len];
	for (int i = 0; i < len; i++)
	{
		result[i] = 0;
	}

	if (is_a_eq_b) // если a = b возвращаем 0
	{
		delete[] result;
		delete[] array_a;
		delete[] array_b;
		return res = "0";
	}

	for (int i = 0; i < len; i++)
	{
		result[i] = array_a[i] - array_b[i];
		if (result[i] < 0)
		{
			result[i] += 1000000000;
			array_a[i + 1]--;
		}
	}
	for (int i = len - 1; i >= 0; i--)
		res += to_string(result[i]);

	delete[] result;
	delete[] array_a;
	delete[] array_b;
	return res;
}


bool a_larger_or_equal_b(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;
	long long int* array_a = from_string_to_array_9(a);
	long long int* array_b = from_string_to_array_9(b);
	int len = a.size() / 9 + 1;

	for (int i = len - 1; i >= 0; i--) // числа в массивах в обратном порядке => идем с конца и сравниваем элементы
	{
		if (array_a[i] > array_b[i])
		{
			delete[] array_a;
			delete[] array_b;
			return true;
		}
		if (array_a[i] < array_b[i])
		{
			delete[] array_a;
			delete[] array_b;
			return false;
		}
	}

	delete[] array_a;
	delete[] array_b;
	return true;// a == b
}


bool a_equal_b(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;
	long long int* array_a = from_string_to_array_9(a);
	long long int* array_b = from_string_to_array_9(b);
	int len = a.size() / 9 + 1;

	for (int i = len - 1; i >= 0; i--)
	{
		if (array_a[i] > array_b[i])
		{
			delete[] array_a;
			delete[] array_b;
			return false;
		}
		if (array_a[i] < array_b[i])
		{
			delete[] array_a;
			delete[] array_b;
			return false;
		}
	}
	delete[] array_a;
	delete[] array_b;
	return true;
}


string divide_longNumbers(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;
	int len = a.size();

	string res = "", substring = "";
	int i = 0;
	while (!a_larger_or_equal_b(substring, b))
	{
		if (i >= len)
			return res;
		substring += a[i];
		i++;
	}
	while (a_larger_or_equal_b(a, b)) // пока a >= b
	{
		for (int j = i - 1; j >= 0; j--)
			a[j] = '0';
		int count = 0;
		while (a_larger_or_equal_b(substring, b)) // while (substring >= b)
		{
			substring = subtraction_longNumbers(substring, b);
			count++;
		}
		res += to_string(count);
		while (!a_larger_or_equal_b(substring, b))
		{
			if (i >= len)
				return res;
			substring += a[i];
			if (!a_larger_or_equal_b(substring, b)) // if (substring < b)
				res += "0";
			i++;
		}
	}
	return res;
}


string mod(string a, string b)
{
	string res = subtraction_longNumbers(a, multiplay_longNumbers(divide_longNumbers(a, b), b)); // a % b = a - (a / b) * b
	return res;
}


string greatest_common_divisor(string a, string b)
{
	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;

	if (a_equal_b(b, "0"))
		return a;
	return greatest_common_divisor(b, mod(a, b));
}
