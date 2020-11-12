#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(double* p, int size, const int Low, const int High, int i)
{
	p[i] = Low + rand() * (High - Low * 1.) / RAND_MAX;
	if (i < size - 1)
		Create(p, size, Low, High, i + 1);
}

void Print(double* p, int size, int i)
{
	cout << setw(10) << p[i];
	if (i < size - 1)
		Print(p, size, i + 1);
	else
		cout << endl;
}

int Count(double* p, int size, int C, int j, int i)
{
	if (p[i] < C)
		j++;
	if (i < size - 1)
		return Count(p, size, C, j, i + 1);
	else		
		return j;
}

int Minus(double* p, int size, int l, int i)
{
	if (p[i] < 0)
		l = i;
	if (i < size - 1)
		return Minus(p, size, l, i + 1);
	else
		return l;
}

int Sum(double* p, int size, int l, int S, int i)
{
	if (l >= 0)
	{
		if (i > l)
			S += p[i];
		if (i < size - 1)
			return Sum(p, size, l, S, i + 1);
		else
			return S;
	}
	else
		return 0;
}

double Max(double* p, int size, double max, int i)
{
	if (p[i] > max)
		max = p[i];
	if (i < size - 1)
		return Max(p, size, max, i + 1);
	else
		return max;
}

void Sort(double* p, double* f, int size, int max, int l, int i)
{
	if (p[i] >= max * 0.8)
	{
		f[l] = p[i];
		l++;
	}
	if (i < size - 1)
		Sort(p, f, size, max, l, i + 1);
	if (p[i] < max * 0.8)
	{
		f[l] = p[i];
		l++;
	}
	if (i < size - 1)
		Sort(p, f, size, max, l, i + 1);
}
int main()
{
	cout << fixed << setprecision(3) << endl;

	srand((unsigned)time(NULL));

	int k;
	cout << "k = "; cin >> k;
	double* p = new double[k];
	double* f = new double[k];

	double C;

	int Low;
	cout << "Low = "; cin >> Low;
	int High;
	cout << "High = "; cin >> High;

	Create(p, k, Low, High, 0);
	Print(p, k, 0);
	cout << endl;

	cout << "Calculating count" << endl;
	cout << endl;
	cout << "C = "; cin >> C;
	cout << "j = " << Count(p, k, C, 0, 0) << endl;
	cout << endl;

	cout << "Calculatin Sum" << endl;
	cout << endl;
	int q = Minus(p, k, -1, 0);
	if (q >= 0)
		cout << "Last minus " << q << endl;
	else
		cout << "No minus " << endl;
	cout << "S = " << Sum(p, k, 0, 0, 0) << endl;
	cout << endl;

	cout << "Relocated elements" << endl;
	cout << endl;
	cout << "Max =" << Max(p, k, p[0], 0) << endl;
	Sort(p, f, k, 0, 0, 0);
	Print(f, k, 0);

	delete[] p;
	delete[] f;

	system("pause");
	return 0;
}