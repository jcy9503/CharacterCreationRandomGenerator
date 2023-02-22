/* Contributer: Lucas Jeong */
/* Clipboard Function Code from: Arian8j2 */

#include <iostream>
#include <random>
#include <string>
#include <cmath>
#include "Clipboard.h"

using namespace std;

void CutZero(string& param)
{
	if (param[0] == '-')
	{
		for (int i = 5; i < 9; ++i)
			param[i] = '\0';
	}
	else
	{
		for (int i = 4; i < 8; ++i)
			param[i] = '\0';
	}
}

int main(int argc, char* argv[])
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> two(0, 99);
	uniform_int_distribution<int> three(0, 999);
	uniform_int_distribution<int> color(0, 255);
	uniform_real_distribution<float> minus(-1.0f, 1.0f);
	uniform_real_distribution<float> plus(0.0f, 1.0f);

	bool flag = true;

	int copyNum;
	cin >> copyNum;

	while (flag)
	{
		clipboardxx::clipboard clipboard;
		string copyText;

		cout << "1: (00), 2: (000), 3: (0.00)~(1.00), 4: (-1.00)~(1.00)\n"
			"5: (0, 0, 0), 6: (0, 0, 0, 0)" << endl;

		int num;
		cin >> num;

		switch (num)
		{
		case 1:
			copyText = to_string(two(gen));
			for (int i = 0; i < copyNum - 1; ++i)
			{
				copyText += "\n" + to_string(two(gen));
			}
			break;
		case 2:
			copyText = to_string(three(gen));
			for (int i = 0; i < copyNum - 1; ++i)
			{
				copyText += "\n" + to_string(three(gen));
			}
			break;
		case 3:
			copyText = to_string(round(plus(gen) * 100) / 100);
			CutZero(copyText);
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = to_string(round(plus(gen) * 100) / 100);
				CutZero(tmp);
				copyText += "\n" + tmp;
			}
			break;
		case 4:
			copyText = to_string(round(minus(gen) * 100) / 100);
			CutZero(copyText);
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = to_string(round(minus(gen) * 100) / 100);
				CutZero(tmp);
				copyText += "\n" + tmp;
			}
			break;
		case 5:
			copyText = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
				"," + to_string(color(gen)) + ")";
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
					"," + to_string(color(gen)) + ")";
				copyText += "\n" + tmp;
			}
			break;
		case 6:
			copyText = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
				"," + to_string(color(gen)) + "," + to_string(color(gen)) + ")";
			for (int i = 0; i < copyNum - 1; ++i)
			{
				string tmp = "(" + to_string(color(gen)) + "," + to_string(color(gen)) +
					"," + to_string(color(gen)) + "," + to_string(color(gen)) + ")";
				copyText += "\n" + tmp;
			}
			break;
		default:
			flag = false;
			break;
		}

		cout << copyText << endl << endl;
		clipboard << copyText;
	}

	return 0;
}
