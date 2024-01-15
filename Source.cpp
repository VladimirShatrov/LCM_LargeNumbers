#include <iostream>
#include <string>


using namespace std;


void swap_xdd(string &a, string &b)
{
	string t = a;
	a = b;
	b = t;
}

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
	for (int i = a.size() - 10; i >= -1; i -= 9)
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
	if (a.size() % 9 != 0) // если кол-во цифр числа нечетное первые a.size() % 9 цифр не будут записаны в массив в пред. цикле
	{
		sub_string = "";
		for (int i = 0; i < a.size() % 9; i++)
			sub_string += a[i];
		array[pos] = atoi(sub_string.c_str());
	}
	return array;
}


int* from_string_to_array(string a) // не используется
{
	int* array = new int[a.size()];
	for (int i = 0; i < a.size(); i++)
		array[i] = 0;
	for (int i = 0; i < a.size(); i++)
		array[a.size() - i - 1] = a[i] - '0';
	return array;
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
		if (array_a[i] != array_b[i])
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


string multiply_longNumbers(string a, string b)
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
			if (array_result[i + j] >= 1000000000)
			{
				array_result[i + j + 1] += array_result[i + j] / 1000000000;
				array_result[i + j] = array_result[i + j] % 1000000000;
			}
			array_result[i + j + 1] += (array_a[i] * array_b[j]) / 1000000000;
		}

	string result;
	bool is_it_leading_zero = true;
	for (int i = 2 * len - 1; i >= 0; i--)
	{
		if (is_it_leading_zero and array_result[i] != 0)
		{
			is_it_leading_zero = false;
			result += to_string(array_result[i]);
		}
		else
		{
			if (!is_it_leading_zero)
			{
				if (array_result[i] == 0)
					result += "000000000";
				else
				{
					if (array_result[i] < 100000000) //если в не первом не нулевом элементе < 9 цифр дописываем нули
					{
						string sub_string = to_string(array_result[i]);
						while (sub_string.size() < 9)
							sub_string = "0" + sub_string;
						result += sub_string;
					}
					else
						result += to_string(array_result[i]);
				}
			}
		}
	}

	delete[] array_result;
	delete[] array_a;
	delete[] array_b;
	return result;
}


string sum_longNumbers(string a, string b)// не используется
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
	bool is_it_leading_zero = true;
	for (int i = len; i >= 0; i--)
	{
		if (is_it_leading_zero and result[i] != 0)
		{
			is_it_leading_zero = false;
			res += to_string(result[i]);
		}
		else
		{
			if (!is_it_leading_zero)
			{
				if (result[i] == 0)
					res += "000000000";
				else
				{
					if (result[i] < 100000000)
					{
						string sub_string = to_string(result[i]);
						while (sub_string.size() < 9)
							sub_string = "0" + sub_string;
						res += sub_string;
					}
					else
						res += to_string(result[i]);
				}
			}
		}
	}

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

	long long int* result = new long long int[len];
	for (int i = 0; i < len; i++)
	{
		result[i] = 0;
	}

	if (a_equal_b(a, b)) // если a = b  a - b = 0 
	{
		delete[] result;
		delete[] array_a;
		delete[] array_b;
		return "0";
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

	string res;
	bool is_it_leading_zero = true;
	for (int i = len - 1; i >= 0; i--)
	{
		if (is_it_leading_zero and result[i] != 0)
		{
			is_it_leading_zero = false;
			res += to_string(result[i]);
		}
		else
		{
			if (!is_it_leading_zero)
			{
				if (result[i] == 0)
					res += "000000000";
				else
				{
					if (result[i] < 100000000)
					{
						string sub_string = to_string(result[i]);
						while (sub_string.size() < 9)
							sub_string = "0" + sub_string;
						res += sub_string;
					}
					else
						res += to_string(result[i]);
				}
			}
		}
	}

	delete[] result;
	delete[] array_a;
	delete[] array_b;
	return res;
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
	while (!a_larger_or_equal_b(substring, b)) // while (substring < b)
	{
		if (i >= len)
			return res;
		substring += a[i];
		i++;
	}
	while ((a_larger_or_equal_b(a, b)) or (a_larger_or_equal_b(substring, b)))// while (a >= b) or (sub_string >= b)
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
	string res = subtraction_longNumbers(a, multiply_longNumbers(divide_longNumbers(a, b), b)); // a % b = a - (a / b) * b
	return res;
}


string greatest_common_divisor(string a, string b)
{
	if (!a_larger_or_equal_b(a, b))
		swap(a, b);

	while (a.size() > b.size())
		b = "0" + b;
	while (a.size() < b.size())
		a = "0" + a;

	if (a_equal_b(b, "0"))
		return a;
	return greatest_common_divisor(b, mod(a, b));
}
