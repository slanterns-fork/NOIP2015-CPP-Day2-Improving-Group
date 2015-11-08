#include <fstream>

using namespace std;

int length, stonenum, removenum;
int stonelength[50010], forelen[50010];
bool chosed[50010];
int maxminlen = -1;

void remove(int cnt)
{
	if (cnt == removenum)
	{
		int last = 1, minA = 1000000000;
		for (int i = 1; i <= stonenum; ++i)
		{
			if (chosed[i]) { continue; }
			int temp = 0;
			for (int j = last; j <= i; ++j)
			{
				temp += forelen[j];
			}
			minA = min(temp, minA);
			last = i + 1;
		}
		maxminlen = max(maxminlen, minA);
		return;
	}

	for (int i = 1; i <= stonenum; ++i)
	{
		if (chosed[i]) { continue; }
		
		chosed[i] = true;
		remove(cnt + 1);
		chosed[i] = false;
	}

	return;
}		

int main()
{
	ifstream fin("stone.in");
	ofstream fout("stone.out");
	fin >> length >> stonenum >> removenum;

	for (int i = 1; i <= stonenum; ++i)
	{
		fin >> stonelength[i];
		forelen[i + 1] = stonelength[i];
	}
	stonelength[stonenum + 1] = length;
	for (int i = 1; i <= stonenum + 1; ++i)
	{
		forelen[i] = stonelength[i] - stonelength[i - 1];
	}

	remove(0);

	fout << maxminlen << endl;

	return 0;
}
