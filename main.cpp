#define _HMM_DEBUG

#include <iostream>
#include "hmm.h"

int main()
{
	int n, k, t, m;
	cout << "Input n,k,t: ";
	cin >> n >> k >> t;
	HMM hmm(k, n, t);
	double *a, *b, *p;
	a = new double[n*n];
	b = new double[n*k];
	p = new double[n];
	ZeroMemory(a, sizeof(double)*n*n);
	ZeroMemory(b, sizeof(double)*n*k);
	ZeroMemory(p, sizeof(double)*n);
	cout << "Input A:";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i*n + j];
		}
	}
	cout << "Input B:";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < k; j++)
		{
			cin >> b[i*k + j];
		}
	}
	cout << "Input Pi:";
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	hmm.setA(a); hmm.setB(b); hmm.setPi(p);
	cout << "Input the number of samples: ";
	cin >> m;
	Sequence sample;
	for (int i = 0; i < m; i++)
	{
		cout << "Sample #" << i << ": ";
		sample.clear();
		int x;
		for (int j = 0; j < t; j++)
		{
			cin >> x;
			sample.push_back(x);
		}
		hmm.pushSample(sample);
	}
	hmm.generateHMM(1.0);
	system("pause");
}