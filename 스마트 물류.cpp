#include<iostream>
#include<string>


using namespace std;

int main(int argc, char** argv)
{
	int N, K;
	cin >> N >> K;
	if(N == 1)
	{
		cout<<0;
		return 0;
	}	
	string str;
	cin >> str;


	auto pH = str.end();
	for (pH = str.begin(); pH!=str.end(); pH++)
	{
		if(*pH == 'H')
		{
			break;
		}
	}
	if(pH == str.end())
	{
		cout<<0;
		return 0;
	}

	auto pP = str.end();
	for (pP = str.begin(); pP!=str.end(); pP++)
	{
		if(*pP == 'P')
		{
			break;
		}
	}
	if(pP == str.end())
	{
		cout<<0;
		return 0;
	}

	int cnt = 0;
	int idxH = distance(str.begin(), pH);
	int idxP = distance(str.begin(), pP);

	for(; idxP<N; idxP++)
	{
		if(str[idxP] == 'H')
			continue;

		int gap = idxH-idxP;
		if(abs(gap) > K)
		{
			if(idxH<idxP)
			{
				idxP--;
				while(1)
				{
					pH++;
					if(pH == str.end())
					{
						cout <<cnt;
						return 0;
					}
					if(*pH == 'H')
					{
						idxH = distance(str.begin(), pH);
						break;
					}
				}
			}
		}
		else if(abs(gap) <= K)
		{
			cnt++;
			while(1)
			{
				pH++;
				if(pH == str.end())
				{
					cout <<cnt;
					return 0;
				}
				if(*pH == 'H')
				{
					idxH = distance(str.begin(), pH);
					break;
				}
			}
		}
	}
	cout<<cnt;

	return 0;
}
