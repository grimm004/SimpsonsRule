// SimpsonsIntegralEstimator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <math.h>

static double f(double x)
{
	return 10 / ((3 * (x * x)) - (2 * x) + log(x));
}

static double t(long n, double start, double end)
{
	double interval = (end - start) / n;
	double total = 0;
	double current = start;
	for (long i = 0; i < n - 1; i++) total += f((current += interval));
	return (interval * (f(start) + f(end) + (2 * total))) / 2;
}

static double m(long n, double start, double end)
{
	double interval = (end - start) / n;
	double total = 0;
	double current = start;
	for (long i = 0; i < n; i++) total += f((current + (current += interval)) / 2);
	return interval * total;
}

static double s(double tn, double mn)
{
	return (tn + (2 * mn)) / 3;
}

int main()
{
	for (short i = 30; i < 40; i++)
	{
		long n = (long)pow(2, i);
		int start = 2;
		int end = 4;

		double tn = t(n, start, end);
		double mn = m(n, start, end);
		double sn = s(tn, mn);

		printf("i: %u\tn: %u\tTn: %.20f\tMn: %.20f\tSn: %.20f\n", i, n, tn, mn, sn);
	}

	std::cin.get();

	return 0;
}
