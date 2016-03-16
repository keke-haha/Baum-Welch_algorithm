#include "hmm.h"

HMM::HMM(int _K, int _N, double _thres = 0.5) :
	K(_K), N(_N), thres(_thres)
{
	A = new double[_N*_N];
	B = new double[_N*_K];
	Pi = new double[_N];
}

HMM::HMM(HMM &_hmm)
{
	*this = _hmm;
}

HMM::~HMM()
{
	if(A) delete[] A;
	if(B) delete[] B;
	if(Pi) delete[] Pi;
	samples.clear();
	C.clear();
}

bool HMM::setA(double *_A)
{
	if(!_A)
	{
		return false;
	}
	else
	{
		if(A) delete[] A;
		A = new double[N*N];
		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++)
			{
				A[i*N+j] = _A[i*N+j];
			}
		}
	}
	return true;
}

void operator=(HMM &_hmm)
{
	K = _hmm.K;
	N = _hmm.N;
	thres = _hmm.thres;
	if(A) delete[] A;
	if(B) delete[] B;
	if(Pi) delete[] Pi;
	A = new double[N*N];
	B = new double[N*K];
	Pi = new double[N];
	setA(_hmm.A);
	setB(_hmm.B);
	setPi(_hmm.Pi);
	samples.clear();
	for(vector<Sequence>::iterator i = _hmm.samples.begin();
		  i != _hmm.samples.end(); i++)
	{
		samples.push_back(*i);
	}
	C.clear();
	for(Sequence::iterator i = _hmm.C.begin();
		  i != _hmm.C.end(); i++)
	{
		C.push_back(*i);
	}
}