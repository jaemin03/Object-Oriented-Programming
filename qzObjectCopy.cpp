#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;

class Student
{
private:
	int id;
	char* name;
	char* major;
public:
	Student(int _id, const char* _name, const char* _major)
	{
		id = _id;
		name = new char[strlen(_name) + 1];
		major = new char[strlen(_major) + 1];
		strcpy(name, _name);
		strcpy(major, _major);
	}

	Student(const Student& s)
	{
		id = s.id;
		name = new char[strlen(s.name) + 1];
		major = new char[strlen(s.major) + 1];
		strcpy(name, s.name);
		strcpy(major, s.major);
	}

	~Student()
	{
		delete name;
		delete major;
		cout << "¼Ò¸êÀÚ ½ÇÇà" << endl;
	}
	
	void ShowData()
	{
		cout << '(' << id << ", " << name << ", " << major << ')' << endl;
	}
};

int main()
{
	//Student s(1234, "È«±æµ¿", "Computer Engineering");
	Student* ps1 = new Student(1234, "È«±æµ¿", "Computer Engineering");
	cout << "¿ø·¡ °´Ã¼ = ";
	//s.ShowData();
	ps1->ShowData();
	//Student s2 = s;
	//Student* ps2 = ps1;
	Student s2 = (*ps1);
	cout << "º¹»ç °´Ã¼ = ";

	s2.ShowData();
	//ps2->ShowData();

	delete ps1;
	return 0;
}