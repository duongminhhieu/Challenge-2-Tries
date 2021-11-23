
#include "Tries.h"


void main()
{
	string s;
	cout << "Nhap cac ki tu: ";
	getline(cin, s);

	trieNode* root = creatTrieFromFile("Dic.txt"); // Đọc file để tạo cây

	int* a = new int[soKiTu]; // Mảng chứa số lần xuất hiện của các ký tự
	for (int i = 0; i < soKiTu; i++) // Khởi tạo các phần tử của mảng là 0 
	{
		a[i] = 0;
	}

	for (int i = 0; i < s.length(); i = i + 2) // Đếm số lần xuất hiện của từ
	{
		a[s[i] - 'a'] += 1;
	}


	queue<string> dsTu; // Hàng đợi để lưu những từ tạo được
	string word = ""; // dùng để chứa các ký tự

	findWord(root, a, 0, dsTu, word); // Tìm từ

	// Xuất kết quả ra màn hình
	cout << dsTu.size()<<endl;
	while (!dsTu.empty())
	{
		cout << dsTu.front()<<endl;
		dsTu.pop();
	}

	cout << endl << endl;
	system("pause");
}