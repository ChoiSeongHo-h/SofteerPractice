#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int N, M;
	cin >> N >> M;
	vector<int> weights;
	vector<int> bests;
	for (int i = 0; i<N; i++)
	{
		int Wi;
		cin >> Wi;
		weights.emplace_back(Wi);
		bests.emplace_back(0);
	}
	for (int i = 0; i<M; i++)
	{
		int Ai, Bi;
		cin >> Ai >> Bi;
		if(bests[Ai-1] < weights[Bi-1])
		{
			bests[Ai-1] = weights[Bi-1];
		}
		if(bests[Bi-1] < weights[Ai-1])
		{
			bests[Bi-1] = weights[Ai-1];
		}
	}

	int cnt = 0;
	for(int i = 0; i<N; i++)
	{
		if(weights[i] > bests[i])
			cnt++;
	}

	cout<<cnt;


	return 0;
}
