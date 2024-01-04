#include <iostream>


using namespace std;


void from_string_to_array(string a, int* array)
{
	string sub_string;
	int j ;
	int pos = 0;
	for (int i = a.size() - 10; i >= 0; i -= 9)
	{
		sub_string = "";
		j = 1;
		while ((j <= 9) and (i + j < a.size())) // формируем подстроку из 9 символов
		{
			sub_string += a[i + j];
			j++;
		}
		array[pos] = atoi(sub_string.c_str());
		pos++;
	}
	if (a.size() % 9 != 0) // если полседняя подстрока менье 9 символов дописывем нули
	{
		sub_string = "";
		for (int i = 0; i < a.size() % 9; i++)
			sub_string += a[i];
		array[pos] = atoi(sub_string.c_str());
	}
}


/*int* multiplay_longNumbers(int* a, int* b, int c, int d) // c - длинна а ,d - длинна b
{
	// a * b = a0 * b0 + ((a0 + a1) * (b0 + b1) - a0 * b0 - a1 * b1) * 10^m + a1 * b1 * 10^2m
	int m = max(c, d) / 2 + (max(c, d) % 2); // m - кол-во элементов в a0 a1 b0 b1, если max(sizeof(a), sizeof(b)) нечетное, то в a1 b1 будет хотябы один незначащий ноль
	
	int* a0 = new int[m];
	int* a1 = new int[m];
	int* b0 = new int[m];
	int* b1 = new int[m];

	for (int i = 0; i < m; i++)
		a0[i] = a[i + m - (max(c, d) % 2)];
	for (int i = max(c, d) - c + (max(c, d) % 2); i < m; i++) // если b > a в a1 будет sizeof(b) - sizeof(a) незнач. нолей и если a >= b, но sizeof(a) % 2 == 1 в a1 будет 1 незанч ноль
		a1[i] = a[i - (max(c, d) % 2) - (max(c, d) - c)];
	for (int i = 0; i < m; i++)
		b0[i] = b[i + m - (max(c, d) % 2)];
	for (int i = max(c, d) - c + (max(c, d) % 2); i < m; i++)
		b1[i] = b[i - (max(c, d) % 2) - (max(c, d) - d)];

	int* result = new int[c + d]; // макс. длина произведения = сумме длинн чисел 
	





	delete[]a0;
	delete[]a1;
	delete[]b0;
	delete[]b1;
}*/


int* sum_longNumbers(int* a, int* b, int len_a, int len_b)
{
	
	int* result = new int[max(len_a, len_b) + 1];
	int ost = 0;
	if (a[max(len_a, len_b)] < 0)
		a[max(len_a, len_b)] = 0;
	if (b[max(len_a, len_b)] < 0)
		b[max(len_a, len_b)] = 0;
	for (int i = 0; i < max(len_a, len_b) + 1; i++)
	{
		result[i] = (a[i] + b[i]) % 1000000000 + ost;
		ost = (a[i] + b[i]) / 1000000000;
	}
	return result;
}


/*int* subtraction_longNumbers(int* a, int* b)
{

}


int* NOD(int* n, int* m)
{

}


string NOK(int* n, int* m, int* nod)
{

}
*/