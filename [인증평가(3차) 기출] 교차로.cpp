#include<iostream>
#include<queue>
#include<map>

using namespace std;

void GetInput(int& N, queue<int>& tQ, queue<char>& wQ, queue<int>& idQ)
{
	int tInput;
	char wInput;
	
	cin >> N;
	for (int i = 0 ; i < N; i++)
	{
		cin >> tInput;
		cin >> wInput;
		tQ.emplace(tInput);
		wQ.emplace(wInput);
		idQ.emplace(i);
	}
}

void NewCars(const int tNow, queue<int>& idQA, queue<int>& idQD, queue<int>& idQC, queue<int>& idQB,
	queue<int>& tQ, queue<char>& wQ, queue<int>& idQ)
{
	while(1)
	{
		if (tQ.front() != tNow)
			break;
		
		auto choiceQ = &idQA;
		switch (wQ.front())
		{
			case 'A' :
				choiceQ = &idQA;
				break;

			case 'D' :
				choiceQ = &idQD;
				break;

			case 'C' :
				choiceQ = &idQC;
				break;

			case 'B' :
				choiceQ = &idQB;
				break;

			default :
				break;
		}
		choiceQ->emplace(idQ.front());
		idQ.pop();
		tQ.pop();
		wQ.pop();
	}
}

void PassCars(const int tNow, queue<int>& idQA, queue<int>& idQD, queue<int>& idQC, queue<int>& idQB,
 map<int, int>& idOutTimeMap, bool& isDeadlock)
{
	int tOut = tNow;
	if(isDeadlock)
		tOut = -1;

	if( idQA.size() > 0 && idQD.size() == 0 )
	{
		idOutTimeMap.emplace(idQA.front(), tOut);
	}
	if( idQD.size() > 0 && idQC.size() == 0 )
	{
		idOutTimeMap.emplace(idQD.front(), tOut);
	}
	if( idQC.size() > 0 && idQB.size() == 0 )
	{
		idOutTimeMap.emplace(idQC.front(), tOut);
	}
	if( idQB.size() > 0 && idQA.size() == 0 )
	{
		idOutTimeMap.emplace(idQB.front(), tOut);
	}

	if(idQA.size() > 0 && idQD.size() > 0 && idQC.size() > 0 && idQB.size() > 0)
	{
		isDeadlock = true;
		idOutTimeMap.emplace(idQA.front(), -1);
		idOutTimeMap.emplace(idQD.front(), -1);
		idOutTimeMap.emplace(idQC.front(), -1);
		idOutTimeMap.emplace(idQB.front(), -1);
	}

	if( idQA.size()>0 && idOutTimeMap.find(idQA.front()) != idOutTimeMap.end() )
	{
		idQA.pop();
	}
	if( idQD.size()>0 && idOutTimeMap.find(idQD.front()) != idOutTimeMap.end() )
	{
		idQD.pop();
	}
	if( idQC.size()>0 && idOutTimeMap.find(idQC.front()) != idOutTimeMap.end() )
	{
		idQC.pop();	
	}
	if( idQB.size()>0 && idOutTimeMap.find(idQB.front()) != idOutTimeMap.end() )
	{
		idQB.pop();
	}
}

int main(int argc, char** argv)
{
	int N = 0;
	queue<int> tQ;
	queue<char> wQ;
	queue<int> idQ;
	GetInput(N, tQ, wQ, idQ);

	map<int, int> idOutTimeMap;

	int tNow = tQ.front();
	queue<int> idQA, idQD, idQC, idQB;
	bool isDeadlock = false;
	while( idOutTimeMap.size() != N )
	{
		NewCars(tNow, idQA, idQD, idQC, idQB, tQ, wQ, idQ);
		PassCars(tNow, idQA, idQD, idQC, idQB, idOutTimeMap, isDeadlock);
		if(idQA.size()+idQD.size()+idQC.size()+idQB.size() > 0)
			tNow++;
		else
			tNow = tQ.front();
	}

	for (auto i:idOutTimeMap)
		cout<<i.second<<"\n";
		
	return 0;
}
