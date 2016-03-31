#define _HMM_DEBUG

#include <iostream>
#include <fstream>
#include "hmm.h"

int main(int argc, char **argv)
{
	ifstream input;
	int n, k, t, m;
	bool file = false;
	double *a, *b, *p;
	a = new double[n*n];
	b = new double[n*k];
	p = new double[n];
	ZeroMemory(a, sizeof(double)*n*n);
	ZeroMemory(b, sizeof(double)*n*k);
	ZeroMemory(p, sizeof(double)*n);
	Sequence sample;

	if (argc > 1)
	{
		input.open(argv[1], ios::in);
		if (input.fail())
		{
			cout << "File " << argv[1] << " doesn't exist!" << endl;
			return -1;
		}
		file = true;
	}

	if (file)
	{
		cout << "Input n,k,t: ";
		input >> n >> k >> t;
		cout << "Input A:";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				input >> a[i*n + j];
			}
		}
		cout << "Input B:";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < k; j++)
			{
				input >> b[i*k + j];
			}
		}
		cout << "Input Pi:";
		for (int i = 0; i < n; i++)
		{
			input >> p[i];
		}
	}
	else
	{
		cout << "Input n,k,t: ";
		cin >> n >> k >> t;
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
	}

	HMM hmm(k, n, t);
	hmm.setA(a); hmm.setB(b); hmm.setPi(p);
	cout << "Input the number of samples: ";
	if (file)
	{
		input >> m;
		for (int i = 0; i < m; i++)
		{
			cout << "Sample #" << i << ": ";
			sample.clear();
			int x;
			for (int j = 0; j < t; j++)
			{
				input >> x;
				sample.push_back(x);
			}
			hmm.pushSample(sample);
		}
	}
	else
	{
		cin >> m;
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
	}
	hmm.generateHMM(1.0);
	system("pause");
	input.close();
}