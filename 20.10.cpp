#include<iostream>
#include<fstream>
using namespace std;

class Info  //информация о абонентах
{
	string name;
	string num;
public:
	Info()
	{
		name = nullptr;
		num = nullptr;
	}
	Info(string n, string nu)
	{
		name = n;
		num = nu;
	}
	void SaveInfo()
	{
		fstream in;  //поток для чтения
		in.open("Directory.txt", ios::app);  //ios::app - файлы открываются для дозаписи  
		in << "Name People:" << name << endl;
		in << "Telephone People:" << num << endl;
		in.close();  //закрытие файла
	}
	void Print()
	{
		cout << "Name:";
		cin >> name;
		cout << "Number:";
		cin >> num;
	}


};

template<class T>
struct Elem 
{
	T value;
	Elem<T>* Next; 
};

template<typename T>
class Cond  
{
	Elem<T>* Head;
	Elem<T>* Tail;
public:
	Cond()
	{
		Head = nullptr;
		Tail = nullptr;
	}
	~Cond()
	{

	}
	void Add(T val)
	{
		Elem<T>* temp = new Elem<T>;
		temp->value = value;
		temp->Next = nullptr;
		if (Head != nullptr)
		{
			Tail->Next = temp;
			Tail = temp;
		}
	}
	void Dell(T v)
	{
		Elem<T>* temp = Head;
		Head = Head->Next;
		delete temp;
	}
	void Print()
	{
		for (T temp = Head; temp = temp->Next)
		{
			temp->value.Print();

		}
	}
	void Save()
	{
		for (T temp = Head; temp = temp->Next)
		{
			tempr->value.Save();
		}
	}

};


void NameSearch(const char* s)
{
	fstream in; //поток для чтения
	in.open("Directory.txt", ios::app); //ios::app - файлы открываются для дозаписи
	const int size = 100;
	char buff[size] = { };
	cout << "Search by name:";
	do
	{
		in.getline(buff, size);
		const char search[] = "Name:";
		if (strstr(buff, search))
		{
			cout << buff << endl;
		}
	} while (in);

	in.close();
}
void NumSearch(const char* v)
{
	fstream in;
	in.open("Directory.txt", ios::app);
	const int size = 100;
	char buff[size] = { };
	cout << "Search by number:";
	do
	{
		in.getline(buff, size);
		const char search[] = "Number:";
		if (strstr(buff, search))
		{
			cout << buff << endl;
		}
	} while (in);
	in.close();
}
void Save()
{
	fstream in;
	in.open("Directory.txt", ios::app);
	const int size = 500;
	char buff[size] = { };
	do
	{
		in.getline(buff, size);
		cout << buff << endl;
	} while (in);
	in.close();
}

int main()
{
	setlocale(0, "ru");
	Info obj("Naima", "0673329854");
    obj.Print();
	Info obj1("Katya", "0832753822");
    obj1.Print();

	Cond<Info> s;
    s.Add(obj);
    s.Add(obj1);
    s.Dell(obj1);

	NameSearch("Naima");
    s.Save();

	NumSearch("0832753822");
	s.Save();

}