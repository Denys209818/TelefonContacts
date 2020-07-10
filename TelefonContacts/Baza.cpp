#include "libs.h"
#include "Baza.h"

void Baza::AddAbonent(Node*& abonent, int nummer, string surname)
{
	if (abonent == nullptr)
	{

		Node* ANew = new Node();
		ANew->nummer = nummer;
		ANew->surname = surname;
		ANew->left = nullptr;
		ANew->right = nullptr;

		abonent = ANew;
		return;
	}
	else if (nummer > abonent->nummer)   AddAbonent(abonent->right, nummer, surname);
	else if (nummer < abonent->nummer)  AddAbonent(abonent->left, nummer, surname);
}

void Baza::DelAbonent(Node*& abonent, int nummer)
{
	if (abonent == nullptr) return;
	if (abonent->nummer == nummer)
	{
		if (abonent->left == nullptr && abonent->right == nullptr)
		{
			delete abonent;
			abonent = nullptr;
			return;
		}
		else if (abonent->left == nullptr && abonent->right != nullptr)
		{
			Node* del = abonent;
			abonent = abonent->right;
			delete del;
		}
		else if (abonent->right == nullptr && abonent->left != nullptr)
		{
			Node* del = abonent;
			abonent = abonent->left;
			delete del;
		}
		else if (abonent->right != nullptr && abonent->left != nullptr)
		{
			Node*& min = FindMin(this->abonent);
			abonent->nummer = min->nummer;
			abonent->surname = min->surname;
			delete min;
			min = nullptr;
		}
	}
	else if (nummer > abonent->nummer) 	DelAbonent(abonent->right, nummer);
	else if (nummer < abonent->nummer) DelAbonent(abonent->left, nummer);

}

Baza::Node*& Baza::FindMin(Node*& abonent)
{
	if (abonent->left == nullptr)
	{
		return abonent;
	}
	FindMin(abonent->left);
}

int& Baza::RemoveAbonentNummer(Node*& abonent, int nummer)
{
	if (abonent == nullptr) return this->error_int;
	if (abonent->nummer == nummer)
	{
		return abonent->nummer;
	}
	else if (nummer > abonent->nummer) RemoveAbonentNummer(this->abonent->right, nummer);
	else if (nummer < abonent->nummer) RemoveAbonentNummer(this->abonent->left, nummer);

}

string& Baza::RemoveAbonentSurname(Node*& abonent, int nummer)
{
	if (abonent == nullptr) return this->error;
	if (abonent->nummer == nummer)
	{
		return abonent->surname;
	}
	else if (nummer > abonent->nummer) this->RemoveAbonentSurname(abonent->right, nummer);
	else if (nummer < abonent->nummer) this->RemoveAbonentSurname(abonent->left, nummer);

}

void Baza::ReturnAbonentNummer(Node*& abonent, int nummer)
{
	if (abonent == nullptr) return;
	if (nummer == abonent->nummer)
	{

		string str;
		str += to_string(abonent->nummer);
		str += " ---- ";
		str += abonent->surname;
		str += "\0";
		cout << str << endl;

		return;
	}
	else if (nummer > abonent->nummer) { ReturnAbonentNummer(abonent->right, nummer); }
	else if (nummer < abonent->nummer) { ReturnAbonentNummer(abonent->left, nummer); }

}

void Baza::ReturnAbonentSurname(Node*& abonent, string surname)
{
	if (abonent == nullptr) return;
	if (abonent->surname == surname)
	{
		string str;
		str = to_string(abonent->nummer);
		str += " ---- ";
		str += abonent->surname;
		cout << str << endl;
		return;
	}
	ReturnAbonentSurname(abonent->left, surname);
	ReturnAbonentSurname(abonent->right, surname);
}

void Baza::Show(Node*& abonent)
{
	if (abonent == nullptr) return;
	Show(abonent->left);
	cout << "Nummer: " << abonent->nummer << " Surname: " << abonent->surname << endl;
	Show(abonent->right);
}

void Baza::ShowByNummers(Node*& abonent, int min, int max)
{
	if (abonent == nullptr) return;
	ShowByNummers(abonent->left, min, max);
	if (abonent->nummer >= min && abonent->nummer <= max)
		cout << "Nummer: " << abonent->nummer << " Surname: " << abonent->surname << endl;
	ShowByNummers(abonent->right, min, max);
}

void Baza::ShowBySurname(Node*& abonent, string& firstName, string& endName)
{
	int nummer_1 = this->SuchNummer(this->abonent, firstName);
	int nummer_2 = this->SuchNummer(this->abonent, endName);
	this->ShowByNummers(this->abonent, nummer_1, nummer_2);
}

int Baza::SuchNummer(Node* abonent, string& name)
{
	if (abonent == nullptr) return -1;
	if (abonent->surname == name)
	{
		cout << abonent->surname << endl;
		cout << abonent->nummer << endl;

		return (int)abonent->nummer;
	}
	SuchNummer(abonent->left, name);
	SuchNummer(abonent->right, name);
}


Baza::Baza()
{
	this->error = "Not Found!";
	this->error_int = -1;
	this->key = new char[255];
	this->abonent = nullptr;
	ifstream fs("key.txt");
	fs.getline(this->key, 255);
	fs.close();
	this->ReadFromFile(this->abonent);
}

char* Baza::GetKey()
{
	return this->key;
}

void Baza::AddAbonent(int nummer, string surname)
{
	this->AddAbonent(this->abonent, nummer, surname);
}

void Baza::DelAbonent(int nummer)
{
	this->DelAbonent(this->abonent, nummer);
}

int& Baza::RemoveAbonentNummer(int nummer)
{
	return this->RemoveAbonentNummer(this->abonent, nummer);
}

string& Baza::RemoveAbonentSurname(int nummer)
{
	return this->RemoveAbonentSurname(this->abonent, nummer);
}

void Baza::ReturnAbonentSurname(string surname)
{
	this->ReturnAbonentSurname(this->abonent, surname);
}

void Baza::ReturnAbonentNummer(int nummer)
{
	this->ReturnAbonentNummer(this->abonent, nummer);
}

void Baza::ShowByNummers(int min, int max)
{
	this->ShowByNummers(this->abonent, min, max);
}

void Baza::ShowBySurname(string firstName, string  endName)
{
	this->ShowBySurname(this->abonent, firstName, endName);
}

void Baza::Show()
{
	this->Show(this->abonent);
}

void Baza::WriteToFile(Node* abonent)
{
	if (abonent == nullptr) return;
	WriteToFile(abonent->left);
	string str = to_string(abonent->nummer);
	str += ".";
	str += abonent->surname;
	ofstream fs(this->key, ios_base::app);
	fs << str << "\n";
	fs.close();
	WriteToFile(abonent->right);
}

void Baza::ReadFromFile(Node* abonent)
{
	char* nummer = new char[255];
	char* buffer = new char[255];
	ifstream fs(this->key, ios_base::app);
	while (!fs.eof())
	{

		fs.getline(buffer, 255);
		if (strlen(buffer) > 0)
		{
			for (int i = 0; i < strlen(buffer) + 1; i++)
			{
				if (buffer[i] == '.')
				{
					buffer = buffer + (i + 1);
					break;
				}
				nummer[i] = buffer[i];
			}
			int k = atoi(nummer);
			this->AddAbonent(k, buffer);
		}
	}
	fs.close();
}

void Baza::RenameFile(const char* newName)
{
	ofstream fs("key.txt", ios_base::trunc);
	fs << newName;
	fs.close();
	rename(this->key, newName);
	strcpy_s(this->key, strlen(newName) + 1, newName);
}

void Baza::DeleteFiles(const char* newName)
{
	remove(newName);
}

Baza::Node* Baza::GetNode()
{
	return this->abonent;
}

Baza::~Baza()
{
	delete this->abonent;
}