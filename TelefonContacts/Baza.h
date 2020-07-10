#pragma once
#include "libs.h"

class Baza
{
	struct Node
	{
		int nummer;
		string surname;

		Node* left;
		Node* right;
	};
	char* key;
	Node* abonent;
	string error;
	int error_int;


	void AddAbonent(Node*& abonent, int nummer, string surname);

	void DelAbonent(Node*& abonent, int nummer);

	Node*& FindMin(Node*& abonent);

	int& RemoveAbonentNummer(Node*& abonent, int nummer);

	string& RemoveAbonentSurname(Node*& abonent, int nummer);

	void ReturnAbonentNummer(Node*& abonent, int nummer);

	void ReturnAbonentSurname(Node*& abonent, string surname);

	void Show(Node*& abonent);

	void ShowByNummers(Node*& abonent, int min, int max);

	void ShowBySurname(Node*& abonent, string& firstName, string& endName);

	int SuchNummer(Node* abonent, string& name);

public:
	Baza();

	char* GetKey();

	void AddAbonent(int nummer, string surname);

	void DelAbonent(int nummer);

	int& RemoveAbonentNummer(int nummer);

	string& RemoveAbonentSurname(int nummer);

	void ReturnAbonentSurname(string surname);

	void ReturnAbonentNummer(int nummer);

	void ShowByNummers(int min, int max);

	void ShowBySurname(string firstName, string  endName);

	void Show();

	void WriteToFile(Node* abonent);

	void ReadFromFile(Node* abonent);

	void RenameFile(const char* newName);

	void DeleteFiles(const char* newName);

	Node* GetNode();

	~Baza();
};
