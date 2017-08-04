// SimpsonsIntegralEstimator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

static double f(double x)
{
	return 10 / ((3 * (x * x)) - (2 * x) + log(x));
	//return pow();
}

static double t(long n, double start, double end)
{
	double interval = (end - start) / n;
	double total = 0;
	double current = start;
	for (int i = 0; i < n - 1; i++) total += f((current += interval));
	return (interval * (f(start) + f(end) + (2 * total))) / 2;
}

static double m(long n, double start, double end)
{
	double interval = (end - start) / n;
	double total = 0;
	double current = start;
	for (int i = 0; i < n; i++) total += f((current + (current += interval)) / 2);
	return interval * total;
}

static double s(double tn, double mn)
{
	return (tn + (2 * mn)) / 3;
}

void printl(char* text)
{
	std::cout << text << std::endl;
}

void printl(double number)
{
	std::cout << number << std::endl;
}

void printl()
{
	std::cout << std::endl;
}

int main()
{
	long n = 1073741824;
	int start = 2;
	int end = 4;

	double tn = t(n, start, end);
	double mn = m(n, start, end);
	double sn = s(tn, mn);

	printl(tn);
	printl(mn);
	printl(sn);

	std::cin.get();

	return 0;
}
