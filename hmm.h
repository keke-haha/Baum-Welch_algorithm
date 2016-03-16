#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef vector<int> Sequence;

class HMM
{
	private:
		int K;					// number of possible emissions 
		int N;					// number of possible states
		double *A;			// transision matrix
		double *B;			// emission matrix
		double *Pi;			// initial distribution
		double thres;		// the threshold used to match
		vector<Sequence> samples;
										// initial sequences needed to generate the model
		Sequence C;			// count for each corresponding sequence

	public:
		// constructor & destructor
		HMM(int _K, int _N, double _thres = 0.5);
		HMM(HMM &_hmm);
		~HMM();

		// initialize the model
		bool setA(double *_A);
		bool setB(double *_B);
		bool setPi(double *_Pi);
		bool pushSample(Sequence sample, int _C = 1);
		Sequence getSample(int index);
		bool generateHMM();
		double getLikely();

		// match new samples
		int match(Sequence sample);

		// operators
		void operator=(HMM &_hmm);
}