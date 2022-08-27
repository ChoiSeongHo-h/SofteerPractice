#include<iostream>
#include<vector>
#include<limits>

using namespace std;

int main(int argc, char** argv)
{
	int N;
	cin >> N;

	vector<int> timeAs;
	vector<int> timeBs;
	vector<int> timeA2Bs;
	vector<int> timeB2As;
	timeA2Bs.emplace_back(0);
	timeB2As.emplace_back(0);
	int timeA, timeB, timeA2B, timeB2A;
	for (int i = 0; i<N-1; i++)
	{
		cin >> timeA >> timeB >> timeA2B >> timeB2A;
		timeAs.emplace_back(timeA);
		timeBs.emplace_back(timeB);
		timeA2Bs.emplace_back(timeA2B);
		timeB2As.emplace_back(timeB2A);
	}
	cin >> timeA >> timeB;
	timeAs.emplace_back(timeA);
	timeBs.emplace_back(timeB);

	vector<vector<int>> table(N+1, vector<int>(N+1, 0));
	table[0][0] = 0;
	int minT = numeric_limits<int>::max();
	bool isA = true;
	for (int j = 1; j<N+1; j++)
	{
		table[0][j] = table[0][j-1] + timeAs[j-1];
	}
	minT = min(minT, table[0][N]);
	for (int i = 1; i<N+1; i++)
	{
		if(isA)
		{
			table[i][0] = table[i-1][0] + timeA2Bs[i-1] + timeBs[i-1];
			isA = !isA;
		}
		else
		{
			table[i][0] = table[i-1][0] + timeB2As[i-1] + timeAs[i-1];
			isA = !isA;
		}
	}
	minT = min(minT, table[N][0]);

	for (int i = 1; i<N+1; i++)
	{
		if(i%2 == 0)
			isA = true;
		else
			isA = false;

		for(int j = 1; i+j<N+1; j++)
		{
			int stay;
			if(isA)
				stay = table[i][j-1] + timeAs[i+j-1];
			else
				stay = table[i][j-1] + timeBs[i+j-1];

			int move;
			if(isA)
			{
				move = table[i-1][j] + timeB2As[i+j-1] + timeAs[i+j-1];

			}
			else
			{
				move = table[i-1][j] + timeA2Bs[i+j-1] + timeBs[i+j-1];
			}


			table[i][j] = (stay < move) ? stay : move;
		}
		minT = min(minT, table[i][N-i]);
	}

	cout<<minT;

	return 0;
}
