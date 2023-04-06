#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;

class Account
{
protected:
	char* accNum;
	int balance;
public:
	Account(const char* _accNum, int _balance)
	{
		cout << "Account()" << endl; // 생성자 실행 확인
		balance = _balance;
		accNum = new char[strlen(_accNum) + 1]; // 메모리 동적 할당
		strcpy(accNum, _accNum);
	}
	~Account()
	{
		delete[] accNum;
		cout << "~Account()" << endl; // 소멸자 실행 확인
	}
};

class KBAccount : public Account
{
	int transLimit;

public:
	KBAccount(const char* _accNum, int _balance, int _transLimit) : Account(_accNum, _balance)
	{
		cout << "KBAccount()" << endl; // 생성자 실행 확인
		transLimit = _transLimit;
	}
	~KBAccount()
	{
		cout << "~KBAccount()" << endl; // 소멸자 실행 확인
	}
	void ShowData()
	{
		cout << "KBAccount()" << '(' << accNum << ", " << balance << ", " << transLimit << ')' << endl << endl;
	}
};

class SHAccount : public Account
{
	char* name;

public:
	SHAccount(const char* _accNum, int _balance, const char* _name) : Account(_accNum, _balance)
	{
		cout << "SHAccount()" << endl; // 생성자 실행 확인
		name = new char[strlen(_name) + 1]; // 메모리 동적 할당
		strcpy(name, _name);
	}
	~SHAccount()
	{
		delete[] name;
		cout << "~SHAccount()" << endl; // 소멸자 실행 확인
	}
	void ShowData()
	{
		cout << "SHAccount" << '(' << accNum << ", " << balance << ", " << name << ')' << endl << endl;
	}

};
int main()
{
	KBAccount KB = KBAccount("12345", 1000, 50000);
	KB.ShowData();

	SHAccount SH = SHAccount("3456-789", 100000, "TUKorea");
	SH.ShowData();
}