#include <iostream>
#include <string>


using namespace std;


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
	int* array_a = from_string_to_array(a);
	int* array_b = from_string_to_array(b);
	int len = a.size();

	int* array_result = new int[2 * len]; // макс. длина произведения = сумме длинн чисел 
	for (int i = 0; i < 2 * len; i++)
		array_result[i] = 0;
	for (int i = 0; i < len; i++)
		for (int j = 0; j < len; j++)
		{
			array_result[i + j] += (array_a[i] * array_b[j]) % 10;
			if (array_result[i + j] > 9)
			{
				array_result[i + j + 1] += array_result[i + j] / 10;
				array_result[i + j] = array_result[i + j] % 10;
			}
			array_result[i + j + 1] += (array_a[i] * array_b[j]) / 10;
		}

	string result;
	for (int i = 2 * len - 1; i >= 0; i--)
		result += to_string(array_result[i]);

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
	int* array_a = from_string_to_array(a);
	int* array_b = from_string_to_array(b);
	int len = a.size();
	
	int* result = new int[len + 1]; // макс длина суммы = длина макс слагаемого + 1
	for (int i = 0; i < len + 1; i++)
		result[i] = 0;
	int ost = 0;
	for (int i = 0; i < len; i++)
	{
		result[i] = (array_a[i] + array_b[i] + ost) % 10;
		ost = (array_a[i] + array_b[i] + ost) / 10;
	}

	string res;

	for (int i = len; i >= 0; i--)
		res += to_string(result[i]);

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
	int* array_a = from_string_to_array(a);
	int* array_b = from_string_to_array(b);
	int len = a.size();

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

	int* result = new int[len];
	for (int i = 0; i < len; i++)
	{
		result[i] = 0;
	}

	if (is_a_eq_b) // если a = b возвращаем 0
	{
		delete[] array_a;
		delete[] array_b;
		return res = "0";
	}

	for (int i = 0; i < len; i++)
	{
		result[i] = array_a[i] - array_b[i];
		if (result[i] < 0)
		{
			result[i] += 10;
			array_a[i + 1]--;
		}
	}
	for (int i = len - 1; i >= 0; i--)
		res += to_string(result[i]);
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
	int* array_a = from_string_to_array(a);
	int* array_b = from_string_to_array(b);
	int len = a.size();

	for (int i = len - 1; i >= 0; i--)
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
	int* array_a = from_string_to_array(a);
	int* array_b = from_string_to_array(b);
	int len = a.size();

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


string divide_longNumbers(string a, string b)// 12345 / 123 => 123 / 123 = 1 
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
