#include<iostream>
#include<vector>
#include <algorithm>


using namespace std;

int main(int argc, char** argv)
{
	int N, Ai;
	cin >> N;
	vector<int> heights;
	for (int i = 0; i<N; i++)
	{
		cin >> Ai;
		heights.emplace_back(Ai);
	}

	vector<int> cnts(heights.size());
	cnts[0] = 1;
	for(int i = 1; i<N; i++)
	{
		int maxCnt = 0;
		for(int j = 0; j<i; j++)
		{
			if(maxCnt<cnts[j] && heights[i] > heights[j])
			{
				maxCnt = cnts[j];
			}
		}
		maxCnt++;
		cnts[i] = maxCnt;
	}

	auto maxNum = max_element(cnts.begin(), cnts.end());
	cout<< *maxNum <<endl;


	return 0;
}
