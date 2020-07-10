#include "libs.h"
#include "Baza.h"
#include "Modes.h"


void main() 
{
	setlocale(LC_CTYPE, "ukr");
	Baza* b = new Baza();
	
	int counter = 1;
	int ch = 1;
	while (true) 
	{
		do 
		{
		
		system("cls");
		if (counter == 1) SetCol(12);
		cout << "1. �������� ����� �������" << endl;
		SetCol(7);
		if (counter == 2) SetCol(12);
		cout << "2. �������� �������" << endl;
		SetCol(7);
		if (counter == 3) SetCol(12);
		cout << "3. ������ �������� �� ������ ��������" << endl;
		SetCol(7);
		if (counter == 4) SetCol(12);
		cout << "4. ������ �������� �� ���� i�e�i" << endl;
		SetCol(7);
		if (counter == 5) SetCol(12);
		cout << "5. �������� ��i�� � ����" << endl;
		SetCol(7);
		if (counter == 6) SetCol(12);
		cout << "6. ���������� ����� ��������" << endl;
		SetCol(7);
		if (counter == 7) SetCol(12);
		cout << "7. ���������� ��i����� ��������" << endl;
		SetCol(7);
		if (counter == 8) SetCol(12);
		cout << "8. ������������� ����" << endl;
		SetCol(7);
		if (counter == 9) SetCol(12);
		cout << "9. �������� ����" << endl;
		SetCol(7);
		ch = _getch();

		switch (ch) 
		{
		  case 224: 
		  {
			  switch (_getch()) 
			  {
			  case 80: counter < 9 ? counter++ : counter = 1; break;
			  case 72: counter > 1 ? counter-- : counter = 9; break;
			  }
		  }
		}

		} while (ch != 13);
		system("cls");
		switch (counter) 
		{
		  case (int)Modes::AddAbonent: 
		  {
			  int nummer;
			  string surname;
			  cout << "����i�� ����� - ";
			  cin >> nummer;
			  cout << "����i�� �����i�� - ";
			  cin >> surname;
			  b->AddAbonent(nummer, surname);
			 
			  break;
		  }
		  case (int)Modes::RemoveAbonent:
		  {
			  int key;
			  cout << "����i�� ����� - ";
			  cin >> key;
			  b->DelAbonent(key);
			  break;
		  }
		  case (int)Modes::FindByNummer:
		  {
			  int key = 0;
			  cout << "����i�� ����� - ";
			  cin >> key;
			  b->ReturnAbonentNummer(key);
			
			  break;
		  }
		  case (int)Modes::FindBySurname:
		  {
			  string key;
			  cout << "����i�� ��i����� - ";
			  cin >> key;
			  b->ReturnAbonentSurname(key);
			  break;
		  }
		  case (int)Modes::WriteFile: 
		  {
			  b->DeleteFiles(b->GetKey());
			  b->WriteToFile(b->GetNode());
			  cout << "��i�� ��������..." << endl;
			  break;
		  }
		  case (int)Modes::RemNum:
		  {
			  int key;
			  cout << "����i�� ����� - ";
			  cin >> key;
			  int& num = b->RemoveAbonentNummer(key);
			  if (num != -1) 
			  {
			  cout << "����i�� ����� ����� - ";
			  cin >> num;
			  }
			  break;
		  }
		  case (int)Modes::RemSur:
		  {
			  int key;
			  cout << "����i�� ����� �������� - ";
			  cin >> key;
			string & num = b->RemoveAbonentSurname(key);
			if (num != "Not Found!")
			{
			cout << "����i�� ���� ��i����� - ";
			cin >> num;
			}
			  break;
		  }
		  case (int)Modes::Rename:
		  {
			  char* newName = new char[255];

			  cout << "����i�� ���� ����� - ";
			  cin >> newName;
			  b->RenameFile(newName);
			  delete newName;
			  break;
		  }
		  case (int)Modes::Delete:
		  {
			  b->DeleteFiles(b->GetKey());
			  break;
		  }
		}
		_getch();
	}

	

	delete b;
}