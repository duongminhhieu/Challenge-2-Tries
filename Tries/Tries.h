#pragma once
#include<iostream>
using namespace std;

const int soKiTu = 26; //so luong ki tu trong bang chu cai
struct trieNode
{
	trieNode* next[soKiTu]; // tro den cac node tuong ung voi ki tu tu a den z
	bool isWord; // kiem tra xem phai la ket thuc cua 1 tu hay khong
};
trieNode* creatNode();
void insert(trieNode* root, string s);
trieNode* creatTrieFromFile(string filename);
void findWord(trieNode* root, int a[], int count, queue<string>& q, string s);
