#include<vector>
#include<iostream>

using namespace std;



int main() {
	/*												
						_			   _				_
	2: |e͟|			3: |e|			4: e͟|			5: |e͟
									   _				_
	6: e͟|			7: |e͟			8:|e			9:  e|
		_
	10: e͟			11: |e|			12: |e			13:  e|
						_
	14: e͟			15: e			16: e
	*/
	int src = 0;
	int dest = 25;
	/*int B[5][10] = {
	{8,10,9,8,10,9,8,10,10,9},
	{11,5,6,7,9,7,13,3,8,6},
	{7,9,8,10,16,9,7,6,11,3},
	{8,14,6,8,13,7,4,8,14,6},
	{7,10,10,6,7,4,5,14,10,4}
	};*/
	int B[5][10] = {
	{8,10,10,10,10,10,10,10,10,9},
	{11,8,15,15,15,15,15,15,9,11},
	{11,12,16,16,16,16,16,16,13,11},
	{11,7,14,14,16,14,14,14,6,11},
	{7,10,10,10,14,10,10,10,10,6}
	};
	vector<vector<int>> A;
	vector<int> temp;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			switch (B[i][j]) {
			case 2: {temp.push_back((i - 1) * 10 + j); break; }
			case 3: {temp.push_back((i + 1) * 10 + j); break; }
			case 4: {temp.push_back(i * 10 + j-1); break; }
			case 5: {temp.push_back(i * 10 + j+1); break; }
			case 6: {temp.push_back(i * 10 + j - 1); temp.push_back((i - 1) * 10 + j); break; }
			case 7: { temp.push_back((i - 1) * 10 + j); temp.push_back(i * 10 + j + 1); break; }
			case 8: { temp.push_back((i + 1) * 10 + j); temp.push_back(i * 10 + j + 1); break; }
			case 9: { temp.push_back(i * 10 + j - 1); temp.push_back((i + 1) * 10 + j); break; }
			case 10: { temp.push_back(i * 10 + j - 1); temp.push_back(i * 10 + j + 1); break; }
			case 11: { temp.push_back((i - 1) * 10 + j); temp.push_back((i + 1) * 10 + j); break; }
			case 12: {  temp.push_back((i - 1) * 10 + j); temp.push_back((i + 1) * 10 + j); temp.push_back(i * 10 + j + 1); break; }
			case 13: { temp.push_back((i - 1) * 10 + j); temp.push_back((i + 1) * 10 + j); temp.push_back(i * 10 + j - 1); break; }
			case 14: { temp.push_back(i * 10 + j - 1); temp.push_back(i * 10 + j + 1); temp.push_back((i - 1) * 10 + j); break; }
			case 15: { temp.push_back(i * 10 + j - 1); temp.push_back(i * 10 + j + 1); temp.push_back((i + 1) * 10 + j); break; }
			case 16: {  temp.push_back(i * 10 + j - 1); temp.push_back(i * 10 + j + 1); temp.push_back((i - 1) * 10 + j); temp.push_back((i + 1) * 10 + j); break; }
			}
			A.push_back(temp);
			temp.clear();
		}
		
	}
	vector<int>  droga;
	for (int i = 0; i < 50; i++) {
		droga.push_back(0);
	}
	vector<int> kolejka; 
	bool cel = false;
	kolejka.push_back(src);
	int x;
	int dlugosc = 0;
	while (cel != true) {
		x = kolejka.front();
		if (x == dest) {
			cel = true;
			dlugosc = droga[x];
			break;
		}
		for (int i = 0; i < A[x].size();i++) {
			if (droga[A[x][i]] == 0 &&A[x][i]!=src) {
				kolejka.push_back(A[x][i]);
				droga[A[x][i]] = droga[x] + 1;
			}
		}
		kolejka.erase(kolejka.begin());
	}
	bool trasa = false;
	vector<int> pelna;
	x = dest;
	while (trasa != true) {
		for (int i = 0; i < A[x].size(); i++) {
			if (droga[A[x][i]] == dlugosc - 1) {
				pelna.push_back(A[x][i]);
				dlugosc--;
				break;
			}
		}
		x = pelna.back();
		if (pelna.back() == src) trasa = true;
	}
	for (int i = 0; i < pelna.size(); i++) {
		cout << pelna[i] << " ";
	}
	system("pause");
	return 0;
}