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
		cout << "Account()" << endl; // ������ ���� Ȯ��
		balance = _balance;
		accNum = new char[strlen(_accNum) + 1]; // �޸� ���� �Ҵ�
		strcpy(accNum, _accNum);
	}
	~Account()
	{
		delete[] accNum;
		cout << "~Account()" << endl; // �Ҹ��� ���� Ȯ��
	}
};

class KBAccount : public Account
{
	int transLimit;

public:
	KBAccount(const char* _accNum, int _balance, int _transLimit) : Account(_accNum, _balance)
	{
		cout << "KBAccount()" << endl; // ������ ���� Ȯ��
		transLimit = _transLimit;
	}
	~KBAccount()
	{
		cout << "~KBAccount()" << endl; // �Ҹ��� ���� Ȯ��
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
		cout << "SHAccount()" << endl; // ������ ���� Ȯ��
		name = new char[strlen(_name) + 1]; // �޸� ���� �Ҵ�
		strcpy(name, _name);
	}
	~SHAccount()
	{
		delete[] name;
		cout << "~SHAccount()" << endl; // �Ҹ��� ���� Ȯ��
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