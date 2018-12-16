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
	cout << setw(5) << '*' << setw(15) << "[1]显示记录" << setw(15) << "[2]查找记录" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[3]添加记录" << setw(15) << "[4]删除记录" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[5]修改记录" << setw(15) << "[6]统计记录" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[7]排序记录" << setw(15) << "[8]保存记录" << setw(5) << '*' << endl;
	cout << setw(5) << '*' << setw(15) << "[0]退出系统" << endl;
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
	cout << "已保存" << endl;
	fclose(f);
	cout << "按任意键继续" << endl;
	_getch();
	_getch();
	return 1;
}

void display(student stu[], int n)
{
	cout << '\t' << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "语文" << '\t' << "英语" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << '\t' << stu[i].num << '\t' << stu[i].name;
		for (int j = 0; j < 3; j++)
		{
			cout << '\t' << stu[i].s[j];
		}
		cout << endl;
	}
	cout << "按任意键继续" << endl;
	_getch();
	_getch();
}

int search(student stu[],int n) 
{
	int o;
	student s;
	while (true)
	{
		cout << setw(15) << "按学号查找[1] 按姓名查找[2]" << endl;
		cin >> o;
		if (o == 1)
		{
			char a[8];
			cout << "请输入学号" << endl;
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
				cout << "该学生信息不存在，按任意键继续" << endl;
				_getch();
				_getch();
				return 0;
			}
			else
			{
				s = stu[i];
				cout << '\t' << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "语文" << '\t' << "英语" << endl;
				cout << '\t' << stu[i].num << '\t' << stu[i].name;
				for (int j = 0; j < 3; j++)
				{
					cout << '\t' << stu[i].s[j];
				}
			}
			cout << endl<< "查找结束，是否返回菜单？" << endl;
			cout << setw(15) << "是[1]  否[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else if (o == 2)
		{
			char a[20];
			cout << "请输入姓名" << endl;
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
				cout << "该学生信息不存在，按任意键继续" << endl;
				_getch();
				return 0;
			}
			else
			{
				s = stu[i];
				cout << '\t' << "学号" << '\t' << "姓名" << '\t' << "数学" << '\t' << "语文" << '\t' << "英语" << endl;
				cout << '\t' << stu[i].num << '\t' << stu[i].name;
				for (int j = 0; j < 3; j++)
				{
					cout << '\t' << stu[i].s[j];
				}
			}
			cout << endl<< "查找结束，是否返回菜单？" << endl;
			cout << setw(15) << "是[1]  否[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else
		{
			cout << "输入错误，请重新选择" << endl;
		}
	}
}

int add(student stu[], int &n)
{
	while (true)
	{
		if (n == N)
		{
			cout << "该记录表已满,按任意键返回" << endl;
			_getch();
			return 0;
		}
		cout << "请依次输入学生学号，姓名，数学，语文，英语成绩" << endl;
		student a;
		cin >> a.num >> a.name;
		for (int i = 0; i < 3; i++)
		{
			cin >> a.s[i];
		}
		stu[n] = a;
		n++;
		cout << "添加成功，是否返回菜单？" << endl;
		cout << setw(15) << "是[1]  否，继续添加[2] " << endl;
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
			cout << "该记录表为空,按任意键返回" << endl;
			_getch();
			_getch();
			return 0;
		}
		cout << setw(15) << "按学号删除[1] 按姓名删除[2]" << endl;
		int o;
		cin >> o;
		if (o == 1)
		{
			char a[8];
			cout << "请输入学号" << endl;
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
				cout << "该学生信息不存在，按任意键继续" << endl;
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
			cout << "删除成功，是否返回菜单？" << endl;
			cout << setw(15) << "是[1]  否，继续删除[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else if (o == 2)
		{
			char a[20];
			cout << "请输入姓名" << endl;
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
				cout << "该学生信息不存在，按任意键继续" << endl;
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
			cout << "删除成功，是否返回菜单？" << endl;
			cout << setw(15) << "是[1]  否，继续删除[2] " << endl;
			cin >> o;
			if (o == 1)
				return 1;
			else
				continue;
		}
		else
		{
			cout << "输入错误，请重新选择" << endl;
		}
	}
}

	int modify(student stu[], int n)
	{
		while (true)
		{
			if (n == 0)
			{
				cout << "该记录表为空,按任意键返回" << endl;
				_getch();
				_getch();
				return 0;
			}
			cout << setw(15) << "按学号修改[1] 按姓名修改[2]" << endl;
			int o;
			cin >> o;
			if (o == 1)
			{
				char a[8];
				cout << "请输入学号" << endl;
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
					cout << "该学生信息不存在，按任意键继续" << endl;
					_getch();
					_getch();
					return 0;
				}
				else
				{
					student a;
					cout << "请依次输入学生学号，姓名，数学，语文，英语成绩" << endl;
					cin >> a.num >> a.num;
					for (int j = 0; j < 3; j++)
					{
						cin >> a.s[j];
					}
					stu[i] = a;
				}
				cout << "修改成功，是否返回菜单？" << endl;
				cout << setw(15) << "是[1]  否，继续修改[2] " << endl;
				cin >> o;
				if (o == 1)
					return 1;
				else
					continue;
			}
			else if (o == 2)
			{
				char a[20];
				cout << "请输入姓名" << endl;
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
					cout << "该学生信息不存在，按任意键继续" << endl;
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
				cout << "删除成功，是否返回菜单？" << endl;
				cout << setw(15) << "是[1]  否[2] " << endl;
				cin >> o;
				if (o == 1)
					return 1;
				else
					continue;
			}
			else
			{
				cout << "输入错误，请重新选择" << endl;
			}
		}
	}

	/*void statis(student stu[], int n)
	{

}
void sort(student stu[], int n);*/