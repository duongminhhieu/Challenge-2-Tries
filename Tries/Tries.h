#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<queue>
#include"tries.h"
using namespace std;



// Xây dựng cấu trúc Tries

const int soKiTu = 26; //Số lượng các ký tự trong bảng chữ cái

struct trieNode
{
	trieNode* next[soKiTu]; // tro den cac node tuong ung voi ki tu tu a den z
	bool isWord; // kiem tra xem phai la ket thuc cua 1 tu hay khong
};


trieNode* creatNode(); // hàm tạo một Node trên cây
void insert(trieNode* root, string s); // hàm chèn 
trieNode* creatTrieFromFile(string filename); // Hàm đọc file vào cây
void findWord(trieNode* root, int a[], int count, queue<string>& q, string s); // Hàm tìm từ
