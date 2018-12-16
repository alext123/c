#include "stusystem.h"
#include "iostream"
#include "iomanip"
#include "string.h"
#include "stdio.h"
#include "conio.h"

#pragma warning(disable:4996)

using namespace std;

int readfile(student stu[])
{
	FILE *f;
	int n = 0;
	f = fopen("D:\\student", "ab+");
	if (f == NULL)
	{
		f = fopen("D:\\student", "wb+");
	}
	while (!feof(f))
	{
		if (fread(&stu[n], sizeof(student), 1, f) == 1)
			n++;
	}
	fclose(f);
	return n;
}

void menu()
{
	cout << "********************************************"<<endl;
	cout << setw(5) << '*' << setw(15) << "[1]��ʾ��¼" << setw(15) << "[2]���Ҽ�¼" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[3]��Ӽ�¼" << setw(15) << "[4]ɾ����¼" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[5]�޸ļ�¼" << setw(15) << "[6]ͳ�Ƽ�¼" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[7]�����¼" << setw(15) << "[8]�����¼" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[0]�˳�ϵͳ" << endl;
	cout << "********************************************" << endl;
}

int save(student stu[], int n)
{
	FILE *f;
	f = fopen("D:\\student", "ab+");
	if (f == NULL)
	{
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		fwrite(&stu[i], sizeof(student), 1, f);
	}
	cout << "�ѱ���" << endl;
	fclose(f);
	cout << "�����������" << endl;
	_getch();
	_getch();
	return 1;
}

void display(student stu[], int n)
{
	cout << '\t' << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "����" << '\t' << "Ӣ��" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << '\t' << stu[i].num << '\t' << stu[i].name;
		for (int j = 0; j < 3; j++)
		{
			cout << '\t' << stu[i].s[j];
		}
		cout << endl;
	}
	cout << "�����������" << endl;
	_getch();
	_getch();
}

int search(student stu[],int n) 
{
	int o;
	student s;
	while (true)
	{
		cout << setw(15) << "��ѧ�Ų���[1] ����������[2]" << endl;
		cin >> o;
		if (o == 1)
		{
			char a[8];
			cout << "������ѧ��" << endl;
			cin >> a;
			int i = 0;
			while (i < n)
			{
				if (strcmp(a, stu[i].num) == 0)
					break;
				i++;
			}
			if (i == n)
			{
				cout << "��ѧ����Ϣ�����ڣ������������" << endl;
				_getch();
				_getch();
				return 0;
			}
			else
			{
				s = stu[i];
				cout << '\t' << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "����" << '\t' << "Ӣ��" << endl;
				cout << '\t' << stu[i].num << '\t' << stu[i].name;
				for (int j = 0; j < 3; j++)
				{
					cout << '\t' << stu[i].s[j];
				}
			}
			cout << endl<< "���ҽ������Ƿ񷵻ز˵���" << endl;
			cout << setw(15) << "��[1]  ��[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else if (o == 2)
		{
			char a[20];
			cout << "����������" << endl;
			cin >> a;
			int i = 0;
			while (i < n)
			{
				if (strcmp(a, stu[i].name) == 0)
					break;
				i++;
			}
			if (i == n)
			{
				cout << "��ѧ����Ϣ�����ڣ������������" << endl;
				_getch();
				return 0;
			}
			else
			{
				s = stu[i];
				cout << '\t' << "ѧ��" << '\t' << "����" << '\t' << "��ѧ" << '\t' << "����" << '\t' << "Ӣ��" << endl;
				cout << '\t' << stu[i].num << '\t' << stu[i].name;
				for (int j = 0; j < 3; j++)
				{
					cout << '\t' << stu[i].s[j];
				}
			}
			cout << endl<< "���ҽ������Ƿ񷵻ز˵���" << endl;
			cout << setw(15) << "��[1]  ��[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else
		{
			cout << "�������������ѡ��" << endl;
		}
	}
}

int add(student stu[], int &n)
{
	while (true)
	{
		if (n == N)
		{
			cout << "�ü�¼������,�����������" << endl;
			_getch();
			return 0;
		}
		cout << "����������ѧ��ѧ�ţ���������ѧ�����ģ�Ӣ��ɼ�" << endl;
		student a;
		cin >> a.num >> a.name;
		for (int i = 0; i < 3; i++)
		{
			cin >> a.s[i];
		}
		stu[n] = a;
		n++;
		cout << "��ӳɹ����Ƿ񷵻ز˵���" << endl;
		cout << setw(15) << "��[1]  �񣬼������[2] " << endl;
		int o;
		cin >> o;
		if (o == 1)
			return 1;
		else 
			continue;
	}

}

int delet(student stu[], int n)
{
	while (true)
	{
		if (n == 0)
		{
			cout << "�ü�¼��Ϊ��,�����������" << endl;
			_getch();
			_getch();
			return 0;
		}
		cout << setw(15) << "��ѧ��ɾ��[1] ������ɾ��[2]" << endl;
		int o;
		cin >> o;
		if (o == 1)
		{
			char a[8];
			cout << "������ѧ��" << endl;
			cin >> a;
			int i = 0;
			while (i < n)
			{
				if (strcmp(a, stu[i].num) == 0)
					break;
				i++;
			}
			if (i == n)
			{
				cout << "��ѧ����Ϣ�����ڣ������������" << endl;
				_getch();
				_getch();
				return 0;
			}
			else
			{
				for (int j = i; j < n; j++)
				{
					stu[i] = stu[i + 1];
				}
				n--;
			}
			cout << "ɾ���ɹ����Ƿ񷵻ز˵���" << endl;
			cout << setw(15) << "��[1]  �񣬼���ɾ��[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else if (o == 2)
		{
			char a[20];
			cout << "����������" << endl;
			cin >> a;
			int i = 0;
			while (i < n)
			{
				if (strcmp(a, stu[i].name) == 0)
					break;
				i++;
			}
			if (i == n)
			{
				cout << "��ѧ����Ϣ�����ڣ������������" << endl;
				_getch();
				return 0;
			}
			else
			{
				for (int j = i; j < n; j++)
				{
					stu[i] = stu[i + 1];
				}
				n--;
			}
			cout << "ɾ���ɹ����Ƿ񷵻ز˵���" << endl;
			cout << setw(15) << "��[1]  �񣬼���ɾ��[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else
		{
			cout << "�������������ѡ��" << endl;
		}
	}
}

	int modify(student stu[], int n)
	{
		while (true)
		{
			if (n == 0)
			{
				cout << "�ü�¼��Ϊ��,�����������" << endl;
				_getch();
				_getch();
				return 0;
			}
			cout << setw(15) << "��ѧ���޸�[1] �������޸�[2]" << endl;
			int o;
			cin >> o;
			if (o == 1)
			{
				char a[8];
				cout << "������ѧ��" << endl;
				cin >> a;
				int i = 0;
				while (i < n)
				{
					if (strcmp(a, stu[i].num) == 0)
						break;
					i++;
				}
				if (i == n)
				{
					cout << "��ѧ����Ϣ�����ڣ������������" << endl;
					_getch();
					_getch();
					return 0;
				}
				else
				{
					student a;
					cout << "����������ѧ��ѧ�ţ���������ѧ�����ģ�Ӣ��ɼ�" << endl;
					cin >> a.num >> a.num;
					for (int j = 0; j < 3; j++)
					{
						cin >> a.s[j];
					}
					stu[i] = a;
				}
				cout << "�޸ĳɹ����Ƿ񷵻ز˵���" << endl;
				cout << setw(15) << "��[1]  �񣬼����޸�[2] " << endl;
				cin >> o;
				if (o == 1)
					return 1;
				else
					continue;
			}
			else if (o == 2)
			{
				char a[20];
				cout << "����������" << endl;
				cin >> a;
				int i = 0;
				while (i < n)
				{
					if (strcmp(a, stu[i].name) == 0)
						break;
					i++;
				}
				if (i == n)
				{
					cout << "��ѧ����Ϣ�����ڣ������������" << endl;
					_getch();
					return 0;
				}
				else
				{
					for (int j = i; j < n; j++)
					{
						stu[i] = stu[i + 1];
					}
					n--;
				}
				cout << "ɾ���ɹ����Ƿ񷵻ز˵���" << endl;
				cout << setw(15) << "��[1]  ��[2] " << endl;
				cin >> o;
				if (o == 1)
					return 1;
				else
					continue;
			}
			else
			{
				cout << "�������������ѡ��" << endl;
			}
		}
	}

	/*void statis(student stu[], int n)
	{

}
void sort(student stu[], int n);*/