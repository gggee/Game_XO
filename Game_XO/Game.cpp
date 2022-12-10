#include <iostream>
#include <Windows.h> 
#include <time.h>    
#include <conio.h>   
#include "Win10.h"
using namespace std;

int MenuRow = 4, MenuCol = 6;

int Select = 0;

// ���������
int colSelFon = _COLOR::blue; // ���� ����
int colSelSym = _COLOR::light_yellow; // ���� �������
// �����������
int colUnSelFon = _COLOR::bright_white; // ���� ����
int colUnSelSym = _COLOR::light_red; // ���� �������

int colDefFon = _COLOR::black;
int colDefSym = _COLOR::white;

clock_t startTime = clock();
int WinX = 0, WinO = 0, Windraw = 0;
bool isStepX = true;

int Row = 3, Col = 6;

void StartGameXO() {
	system("cls");

	SetPos(Row + 0, Col); cout << "+---+---+---+";
	SetPos(Row + 1, Col); cout << "|   |   |   |";
	SetPos(Row + 2, Col); cout << "+---+---+---+";
	SetPos(Row + 3, Col); cout << "|   |   |   |";
	SetPos(Row + 4, Col); cout << "+---+---+---+";
	SetPos(Row + 5, Col); cout << "|   |   |   |";
	SetPos(Row + 6, Col); cout << "+---+---+---+";
	// ���������� ��� �����. ������� � �����
	int curRow = Row + 1;
	int curCol = Col + 2;
	int _row = 0, _col = 0;


	int cell[3][3] = { 0 };
	int step = 0;
	int Win = 0;

	CursorHide(TRUE, 100);
	bool isGameOver = false;
	while (!isGameOver)
	{
		SetPos(curRow, curCol);
		//
		int key = _getch();
		switch (key) {
		case _KEY::UP: // �����
		case 'w': case 'W':
			if (_row > 0) { curRow -= 2; _row--; }
			break;
		case _KEY::DOWN: case 's': case 'S': // ����
			if (_row < 2) { curRow += 2; _row++; }
			break;
		case _KEY::LEFT: case 'a': case 'A': // �����
			if (_col > 0) { curCol -= 4; _col--; }
			break;
		case _KEY::RIGHT: case 'd': case 'D': // ������
			if (_col < 2) { curCol += 4; _col++; }
			break;
		case _KEY::ENTER: case _KEY::SPACE:
			if (cell[_row][_col] == 0)
			{
				step++; // ������� ���-�� �����
				if (isStepX == true) {
					cout << "X";
					cell[_row][_col] = 1;
					isStepX = false;
				}
				else {
					cout << "O";
					cell[_row][_col] = 2;
					isStepX = true;
				}
				// �� �����������
				if (cell[0][0] != 0 &&
					cell[0][0] == cell[0][1] && cell[0][0] == cell[0][2]) {
					Win = cell[0][0];
				}
				if (cell[1][0] != 0 &&
					cell[1][0] == cell[1][1] && cell[1][0] == cell[1][2]) {
					Win = cell[1][0];
				}
				if (cell[2][0] != 0 &&
					cell[2][0] == cell[2][1] && cell[2][0] == cell[2][2]) {
					Win = cell[2][0];
				}
				// �� ���������
				if (cell[0][0] != 0 &&
					cell[0][0] == cell[1][0] && cell[0][0] == cell[2][0]) {
					Win = cell[0][0];
				}
				if (cell[0][1] != 0 &&
					cell[0][1] == cell[1][1] && cell[0][1] == cell[2][1]) {
					Win = cell[0][1];
				}
				if (cell[0][2] != 0 &&
					cell[0][2] == cell[1][2] && cell[0][2] == cell[2][2]) {
					Win = cell[0][2];
				}
				// �� ���������
				if (cell[0][0] != 0 &&
					cell[0][0] == cell[1][1] && cell[0][0] == cell[2][2]) {
					Win = cell[0][0];
				}
				if (cell[0][2] != 0 &&
					cell[0][2] == cell[1][1] && cell[0][2] == cell[2][0]) {
					Win = cell[0][2];
				}
				// ������ ���������� ������ - Win
				if (Win == 1)
				{
					clock_t gameTime = clock() - startTime;
					SetPos(Row + (2 * 3 + 1) + 2, Col);
					cout << "�������� X!";
					WinX++;
					system("pause > nul");
					isGameOver = true;
				}
				else if (Win == 2) {
					SetPos(Row + (2 * 3 + 1) + 2, Col);
					cout << "�������� O!";
					WinO++;
					system("pause > nul");
					isGameOver = true;
				}
				else if (step == 9) {
					SetPos(Row + (2 * 3 + 1) + 2, Col);
					cout << "�����!";
					Windraw++;
					system("pause > nul");
					isGameOver = true;
				}
			}
			break;
		case _KEY::ESC:
			isGameOver = true;
			break;
		} // switch(key)
	} // while( !isGameOver )
	system("pause > nul");
	system("cls");
} // StartGameXO()

// ������� ������ ���������� �� �����
void ShowStat()
{
	system("cls");
	SetPos(1, 2); cout << "����� ������� ���: " << WinX + WinO + Windraw;
	SetPos(2, 2); cout << "�������� X: " << WinX << " ���";
	SetPos(3, 2); cout << "�������� O: " << WinO << " ���";
	SetPos(4, 2); cout << "�������� ������: " << Windraw << " ���";
	SetPos(6, 2); system("pause>nul");
	system("cls");
}
// ������� ��� ��������� ����
void Settings()
{
	system("cls");
	SetPos(1, 2);
	cout << "�������� ��� ������ ����� ������ (X ��� O): ";
	int key;
	do
	{
		key = _getch();
	} while (key != 'o' && key != 'O' && key != 'x' && key != 'X');
	while (_kbhit())
	{
		_getch();
	}
	cout << (char)key;
	isStepX = (key == 'x' || key == 'X') ? true : false;
	SetPos(2, 2);
	system("pause>nul");
	system("cls");
}

void About()
{
	system("cls");
	SetPos(5, 8); cout << "���� \"��������-������\"";
	SetPos(7, 7); cout << " ��������� �����������";
	SetPos(8, 7); cout << "  GGG/gss.  ";

	SetPos(10, 7);

	system("pause > nul");
	system("cls");
}

//
int main() {
	setlocale(LC_ALL, "Rus");
	system("color 07");

	CursorHide(FALSE, 20);

	bool isExit = false;
	while (!isExit)
	{
		CursorHide();//������ ������

		SetPos(MenuRow + 0, MenuCol);
		if (Select == 0) { SetColor(colSelFon, colSelSym); }
		else { SetColor(colUnSelFon, colUnSelSym); }
		cout << "    ������ ����    ";

		SetPos(MenuRow + 1, MenuCol);
		if (Select == 1) { SetColor(colSelFon, colSelSym); }
		else { SetColor(colUnSelFon, colUnSelSym); }
		cout << "  ���������� ����  ";

		SetPos(MenuRow + 2, MenuCol);
		if (Select == 2) { SetColor(colSelFon, colSelSym); }
		else { SetColor(colUnSelFon, colUnSelSym); }
		cout << "   ��������� ����  ";

		SetPos(MenuRow + 3, MenuCol);
		if (Select == 3) { SetColor(colSelFon, colSelSym); }
		else { SetColor(colUnSelFon, colUnSelSym); }
		cout << "    �� �������     ";

		SetPos(MenuRow + 4, MenuCol);
		if (Select == 4) { SetColor(colSelFon, colSelSym); }
		else { SetColor(colUnSelFon, colUnSelSym); }
		cout << "      �����        ";


		SetColor(colDefFon, colDefSym);
		{
			int key = _getch();
			switch (key)
			{
			case _KEY::UP: // �����
				if (Select > 0) { Select--; }
				break;
			case _KEY::DOWN: // ����
				if (Select < 4) { Select++; }
				break;
			case _KEY::ENTER:
				SetPos(MenuRow + 6, MenuCol - 2);
				cout << "������ " << Select << " ����� ����";

				switch (Select)
				{
				case 0:
					StartGameXO();
					break;
				case 1:
					ShowStat();
					break;
				case 2:
					Settings();
					break;
				case 3:
					About();
					break;
				case 4:
					isExit = true;
					break;
				}
				break;
			case _KEY::ESC:
				isExit = true;
				break;
			}
		} // if(_kbhit())
	} // while(true)

	SetPos(MenuRow + 6, MenuCol - 2);
	cout << "                                ";

	SetPos(MenuRow + 6, MenuCol - 2);
	cout << "Goob bye :c ...";

	cin.get(); cin.get();
} // main()
