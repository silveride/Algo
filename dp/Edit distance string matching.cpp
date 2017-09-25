// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>


using namespace std;


class DP {
public:

	void BackTrace(vector< vector<int> >& table, string& p, string& t) {

		int i = table.size() - 1;
		int j = table[0].size() - 1;

		while (true) {

			if (i == 0 || j == 0) {
				break;
			}
			if (p[j - 1] == t[i - 1]) {
				i = i - 1;
				j = j - 1;
			}
			else if (table[i][j] == table[i - 1][j - 1] + 1) {
				cout << "Substitution " << p[j - 1] << " and " << t[i - 1] << endl;
				i = i - 1;
				j = j - 1;
			}
			else if (table[i][j] == table[i][j - 1] + 1) {
				cout << "Delete in " << p << "char " << p[j - 1] << endl;
				j = j - 1;
			}
			else if (table[i][j] == table[i - 1][j] + 1) {
				cout << "Delete in " << t << "char " << t[i - 1] << endl;
				i = i - 1;
			}
			else {

				cout << "false state entered" << endl;
				break;
			}

		}
	}


	int min(int x, int y, int z) {

		int min = x > y ? y : x;

		return min > z ? z : min;
	}

	int operations(string p, string t) {

		vector< vector<int> > table;

		// Init vectors


		for (int i = 0; i <= t.size(); ++i) {
			vector<int> row;
			for (int j = 0; j <= p.size(); ++j) {

				if (i == 0) {
					row.push_back(j);
				}
				else if (j == 0) {
					row.push_back(i);
				}
				else {
					row.push_back(0);
				}
			}
			table.push_back(row);
		}

		// construct the matrix
		for (int i = 1; i <= t.size(); ++i) {

			for (int j = 1; j <= p.size(); ++j) {

				if (p[j - 1] == t[i - 1]) {

					table[i][j] = table[i - 1][j - 1];
				}

				else {
					table[i][j] =1 + min(table[i - 1][j - 1], table[i][j - 1], table[i - 1][j]);
				}
			}

		}
	
		print_table(table, p.size(), t.size(),p,t);


		BackTrace(table, p, t);

		return table[p.size()][t.size()];
	}

	void print_table(vector< vector<int> >& table, int x, int y, string p, string t) {

		cout << 0 << " "<< 0<< " ";

		for (auto x : p) {
			cout << x << " ";
		}

		cout << endl;

		for (int i = 0; i <= y; ++i) {
			for (int j = -1; j <= x; ++j) {

				if (j == -1) {
					if (i == 0) cout << 0 << " ";
					else
						cout << t[i-1] << " ";
				}
				else
					cout << table[i][j] << " ";
			}
			cout << endl;

		}
	}

};
int main()
{
	DP dp;

	string str1 = "abcxfg";
	string str2 = "adc";

	dp.operations(str1, str2);

    return 0;
}

