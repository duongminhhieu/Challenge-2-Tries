#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include"tries.h"
using namespace std;


<<<<<<< HEAD
// Xây dựng cấu trúc Tries
=======

const int soKiTu = 26; //so luong ki tu trong bang chu cai
>>>>>>> 9ee0a3a58d4d2ee5361f4bd2ac9287a86c46716a
struct trieNode
{
	trieNode* next[soKiTu]; // tro den cac node tuong ung voi ki tu tu a den z
	bool isWord; // kiem tra xem phai la ket thuc cua 1 tu hay khong
};


trieNode* creatNode();
void insert(trieNode* root, string s);
trieNode* creatTrieFromFile(string filename);
void findWord(trieNode* root, int a[], int count, queue<string>& q, string s);
