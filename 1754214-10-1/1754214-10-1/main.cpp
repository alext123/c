#include "stusystem.h"
#include "iostream"
#include "iomanip"
#include "string.h"
#include "stdio.h"
#include "conio.h"

#pragma warning(disable:4996)
using namespace std;

int main()
{
	student stu[N];
	int n=0;
	int o;
	cout << setw(10)<<'*';
	cout<< "*��ӭʹ��ѧ���ɼ�����ϵͳ**" << endl;
	n = readfile(stu);
	cout << "��ϵͳĿǰ�гɼ���¼" << n << "��" << endl;
	cout << "�����������" << endl;
	_getch();
	while (1)
	{
		system("cls");
		cout << setw(10) << '*';
		cout << "*��ӭʹ��ѧ���ɼ�����ϵͳ**" << endl;
		cout << "��ϵͳĿǰ�гɼ���¼" << n << "��" << endl;
		menu();
		cout << "��ѡ��Ҫ���еĲ���(0~8)" << endl;
		cin >> o;
		if (o == 0)
		{
			cout << "�ر�ϵͳ���Ƿ��޸ı������ļ��У�" << endl;
			cout << setw(15) << "��[1]  ��[2]  ����������ȡ���˳���" << endl;
			cin >> o;
			if (o == 1)
			{
				bool a;
				a=save(stu,n);
				if (a == 1)
				{
					cout << "��������˳�" << endl;
					_getch();
					break;
				}
				else
				{
					cout << "����ʧ�ܣ�����������ز˵�"<<endl;
					_getch();
					continue;
				}
			}
			else if (o==2)
			{
				break;
			}
			else
				continue;
		}
		switch (o)
		{
		case 1:display(stu,n); break;
		case 2:search(stu,n); break;
		case 3:add(stu, n); break;
		case 4:delet(stu, n); break;
		case 5:modify(stu, n); break;
		//case'6':statis(stu, n); break;
		//case'7':sort(stu, n); break;
		case 8 :save(stu, n); break;
		default:cout << "�������������ѡ��" << endl;
		}
	}
	cout << "��ӭ�ٴ�ʹ�ñ�ϵͳ" << endl;
	system("pause");
	return (0);
}