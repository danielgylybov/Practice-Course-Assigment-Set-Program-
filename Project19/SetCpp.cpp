#include "iostream"
#include "iomanip"
#include "string"
#include "math.h"

using namespace std;

template <class T>
class Set
{
private:
	T elementArr[100];
	int count;
public:

	Set()
	{
		count = 0;
	}

	Set(T element[], int count)
	{
		this->count = 0;
		for (int i = 0; i < count; i++)
		{
			if (!Belong(element[i]));
			{
				Add(element[i]);
			}
		}
	}

	Set(Set &set)
	{
		this->count = set.count;
		for (int i = 0; i < count; i++)
		{
			this->elementArr[i] = set.elementArr[i];
		}
	}

	Set& operator=(Set &set)
	{
		this->count = set.count;
		for (int i = 0; i < count; i++)
		{
			this->elementArr[i] = set.elementArr[i];
		}
		return *this;
	}

	// ������ ����� ����� ������, ������ ������� ���������� �� �����������
	bool Belong(T element)
	{
		for (int i = 0; i < count; i++)
		{
			if (this->elementArr[i] == element)
			{
				return true;
			}
		}
		return false;
	}

	int ElementCount()
	{
		return count;
	}

	// ������� �� �������� �� ������� � �����������
	void Add(T element)
	{
		if (!Belong(element))
		{
			this->elementArr[this->count] = element;
			this->count++;
		}
		else cout << "Equal elements exist! " << endl;
	}

	// ������ �� ��������� �� ��������� �� �����������
	void input()
	{
		int temp = 0;
		int n;
		cout << "Element Count to Add: ";
		cin >> n;
		temp = count;
		for (int i = count; i < count + n; i++)
		{
			cout << "Enter Element No( " << i << " ): "; cin >> elementArr[i];
			Add(elementArr[i]);
			if (temp + n == count)
			{
				break;
			}
		}
	}

	// ������ �� ����������� �� ��������� �� ������
	void output()
	{
		cout << "\nElement count of set: " << ElementCount() << endl;
		cout << "Elements: {";
		for (int i = 0; i < count; i++)
		{
			cout << "   " << elementArr[i];
		}
		cout << setw(4) << "}" << endl;
	}

	// ������� �� ���������� �� ��� ��������� (�������� '+')
	Set<T> operator+(Set set)
	{
		for (int i = 0; i < count; i++)
		{
			if (!set.Belong(elementArr[i]))
			{
				set.Add(elementArr[i]);
			}
		}
		return set;
	}

	// ������� �� ������� �� ��� ��������� (�������� '*')
	Set<T> operator*(Set set)
	{
		Set result;
		for (int i = 0; i < count; i++)
		{
			if (set.Belong(elementArr[i]))
			{
				result.Add(elementArr[i]);
			}
		}
		return result;
	}

	// ������� �� ������� ����� ��� ��������� (�������� '-')
	friend Set<T> operator-(Set set1, Set set2)
	{
		Set result;
		for (int i = 0; i < set1.count; i++)
		{
			if (!set1.Belong(set2.elementArr[i]))
			{
				result.Add(set2.elementArr[i]);
			}
		}
		return result;
	}
};





int main()
{
	// O������� � ��������� �� ��� 'int'
	// ���������: Set<���> ���_��_�����������;

	cout << " ||| Intiger Sets |||" << endl;
	// ��������� 'S3' � �������� { 18, 11, 41 }
	Set<int> S3;
	S3.Add(18);
	S3.Add(11);
	S3.Add(41);
	cout << "\t/ S3 \\";
	S3.output();

	// ��������� 'S4' � �������� { 11  21  12 }
	Set<int> S4;
	S4.Add(11);
	S4.Add(21);
	S4.Add(12);
	cout << "\t/ S4 \\";
	S4.output();

	// ��������� 'S5' ����� � ������������ �� 'S3' � 'S4' � ��������  {   18   11   41   21   12   }
	Set<int> S5;
	cout << "\nUnited S3 and S4: ";

	S5 = S4 + S3;
	S5.output();

	// ��������� 'S5' ����� � ��������� �� 'S3' � 'S4' � ��������  {   11   }
	cout << "\nIntersected S3 and S4: ";
	S5 = S4*S3;
	S5.output();

	// ��������� 'S5' ����� � ��������� �� 'S3' � 'S4' � ��������  {   18   41   }
	cout << "\nDiffernace between S3 and S4: ";
	S5 = S4 - S3;
	S5.output();
	cout << endl << endl;



	cout << " ||| Charecter Sets |||" << endl;

	// ��������� 'C3' � �������� { A  B  C }
	Set<char> C3;
	C3.Add('A');
	C3.Add('B');
	C3.Add('C');
	cout << "\t/ C3 \\";
	C3.output();

	// ��������� 'C4' � �������� { B  D  F }
	Set<char> C4;
	C4.Add('B');
	C4.Add('D');
	C4.Add('F');
	cout << "\t/ C4 \\";
	C4.output();

	// ��������� 'C5' ����� � ������������ �� 'C3' � 'C4' � ��������   {   A    B    C    D    F   }
	Set<char> C5;
	cout << "\nUnited C3 and C4: ";

	C5 = C4 + C3;
	C5.output();

	// ��������� 'C5' ����� � ��������� �� 'C3' � 'C4' � ��������  {   B   }
	cout << "\nIntersected C3 and C4: ";
	C5 = C4*C3;
	C5.output();

	// ��������� 'C5' ����� � ��������� �� 'C3' � 'C4' � ��������  {   A    C   }
	cout << "\nDiffernace between C3 and C4: ";
	C5 = C4 - C3;
	C5.output();
	cout << endl << endl;


	cout << " ||| Name(string) Sets |||" << endl;

	// ��������� 'N3' � �������� { Asen  Bojidar  Cvetmoir }
	Set<string> N3;
	N3.Add("Asen");
	N3.Add("Bojidar");
	N3.Add("Cvetomir");
	cout << "\t/ N3 \\";
	N3.output();

	// ��������� 'N4' � �������� { Bojidar  Daniel  Filip }
	Set<string> N4;
	N4.Add("Bojidar");
	N4.Add("Daniel");
	N4.Add("Filip");
	cout << "\t/ N4 \\";
	N4.output();

	// ��������� 'N5' ����� � ������������ �� 'N3' � 'N4' � ��������   {   Asen    Bojidar    Cvetomir    Daniel    Filip   }
	Set<string> N5;
	cout << "\nUnited N3 and N4: ";

	N5 = N4 + N3;
	N5.output();

	// ��������� 'N5' ����� � ��������� �� 'N3' � 'N4' � ��������  {   Bojidar   }
	cout << "\nIntersected N3 and N4: ";
	N5 = N4*N3;
	N5.output();

	// ��������� 'N5' ����� � ��������� �� 'N3' � 'N4' � ��������  {   Asen    Cvetomir   }
	cout << "\nDiffernace between N3 and N4: ";
	N5 = N4 - N3;
	N5.output();
	cout << endl << endl;

	cout << "\t\t\t\t\t\t\t\t\t\t\tDaniel Set Program v1.1 2017" << endl;

	system("pause");
	return 0;
}