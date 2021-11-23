#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include"tries.h"
using namespace std;

void main()
{
	string s;
	cout << "Nhap cac ki tu" << endl;
	getline(cin, s);
	trieNode* root = creatTrieFromFile("Dic.txt");
	int* a = new int[soKiTu]; // mang chua so lan xuat hien cua cac ki tu
	for (int i = 0; i < soKiTu; i++) // Khoi tao phan tu mang =0
	{
		a[i] = 0;
	}
	for (int i = 0; i < s.length(); i = i + 2)
	{
		a[s[i] - 'a'] += 1;
	}
	queue<string> dsTu; // Hang doi de luu nhung tu tao duoc
	string word = ""; // chua cac ki tu
	findWord(root, a, 0, dsTu, word);
	// xuat ket qua ra man hinh
	cout << dsTu.size()<<endl;
	while (!dsTu.empty())
	{
		cout << dsTu.front()<<endl;
		dsTu.pop();
	}
}