#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<string>
using namespace std;
enum Color { Black = 0, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray, LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White };

enum Napravlenie { Up = 72, Left = 75, Right = 77, Down = 80, Enter = 13, escepushka = 27 };
HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);//получает дискриптор активного окна

void SetColor(Color text, Color background)
{
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
void SetCursor(int x, int y)
{
	COORD myCoords = { x,y };//инициализируем передаваемыми значениями объект координат
	SetConsoleCursorPosition(hStdOut, myCoords);
}

void menuPrint()
{
	SetColor(Red, Blue);
	cout << "\n 1 - GetMethod,    \n 2 - SetMethod,    \n 3 - PrintMethod,  \n 4 - PrintAllClass \n";
	SetColor(White, Black);
}
// функции для вывода
void GetMethod(string nameclass, string namePole)
{
	cout << nameclass << " Get" << namePole << "()" << "\n{\n" << "\treturn " << namePole << "\n" << "}";
}
void SetMethod(string nameclass, string namePole, string dataType)
{
	cout << nameclass << " Set" << nameclass << "("<<dataType<<" "<< namePole<<")" << "\n{\n" << "\tthis->" << namePole << " = " << namePole << "\n" << "}";
}
void PrintMetod(string nameclass, string namePole)
{
	cout << nameclass << " Print" << namePole << "()" << "\n{\n" << "\tcout<<" << namePole << ";\n}";
}
void FuncPrint(int point, string nameclass, string namePole, string dataType)
{
	switch (point)
	{
	case 1:
		GetMethod(nameclass, namePole);
		break;
	case 2:
		SetMethod(nameclass, namePole, dataType);
		break;
	case 3:
		PrintMetod(nameclass, namePole);
		break;
	case 4:
		GetMethod(nameclass, namePole);
		cout << "\n";
		SetMethod(nameclass, namePole, dataType);
		cout << "\n";
		PrintMetod(nameclass, namePole);
		break;
	default:
		break;
	}
}


void main()
{
	setlocale(LC_ALL, "ru");
	string nameclass, namePole, dataType;
	int point = 0;
	cout << "Введите название класса: \n";
	cin >> nameclass;
	menuPrint();
	cout << "Введите пункт(1-4):\n";
	cin >> point;
	cout << "Введите название поля:\n";
	cin >> namePole;
	if (point == 2 || point == 4)
	{
		cout << "Введите тип данных: ";
		cin >> dataType;
	}
	system("cls");
	FuncPrint(point, nameclass, namePole, dataType);
	cout << "\n";

	cout << "\n\nНажмите квавишу Enter для завершения программы: \n";
	int key = _getch();
	do
	{
	} while (key != Enter);
	SetColor(Black, Black);
}