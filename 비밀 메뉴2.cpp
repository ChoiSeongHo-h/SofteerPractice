#include<iostream>
#include<vector>

using namespace std;

int main(int argc, char** argv)
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> nVec(N+1), mVec(M+1);
	for(int i = 1; i<=N; i++)
	{
		int Ni;
		cin >> Ni;
		nVec[i] = Ni;
	}
	for(int i = 1; i<=M; i++)
	{
		int Mi;
		cin >> Mi;
		mVec[i] = Mi;
	}

	if(N>M)
	{
		swap(N, M);
		swap(nVec, mVec);
	}

	int maxNum = 0;
	vector<vector<int>> table(N+1, vector<int>(M+1, 0));
	for(int i = 1; i<=N; i++)
	{
		for(int j =1; j<=M; j++)
		{
			if(nVec[i] == mVec[j])
			{
				table[i][j] = table[i-1][j-1]+1;
				maxNum = max(maxNum, table[i][j]);
			}
		}
	}

	cout<<maxNum;
	

	return 0;
}
