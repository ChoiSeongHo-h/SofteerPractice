#include<iostream>
#include<vector>


using namespace std;

int main(int argc, char** argv)
{
	int N, K, Si, Ai, Bi;
	cin >> N >> K;
	
	vector<int> scores = {0};
	for (int i = 0; i<N; i++)
	{
		cin >> Si;
		scores.emplace_back(Si);
	}

	vector<int> As;
	vector<int> Bs;
	for (int i = 0; i<K; i++)
	{
		cin >> Ai >> Bi;
		As.emplace_back(Ai);
		Bs.emplace_back(Bi);
	}

	vector<int> accSum(N+1);
	accSum[0] = scores[0];
	for (int i = 1; i<N+1; i++)
	{
		accSum[i] = accSum[i-1] + scores[i];
	}

	for(int i = 0; i<K; i++)
	{
		printf("%.2f\n", double(accSum[Bs[i]]-accSum[As[i]-1])/double(Bs[i]-As[i]+1));
	}
	

	return 0;
}
