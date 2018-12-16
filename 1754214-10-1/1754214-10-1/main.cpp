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
	cout<< "*欢迎使用学生成绩管理系统**" << endl;
	n = readfile(stu);
	cout << "本系统目前有成绩记录" << n << "条" << endl;
	cout << "按任意键继续" << endl;
	_getch();
	while (1)
	{
		system("cls");
		cout << setw(10) << '*';
		cout << "*欢迎使用学生成绩管理系统**" << endl;
		cout << "本系统目前有成绩记录" << n << "条" << endl;
		menu();
		cout << "请选择要进行的操作(0~8)" << endl;
		cin >> o;
		if (o == 0)
		{
			cout << "关闭系统，是否将修改保存至文件中？" << endl;
			cout << setw(15) << "是[1]  否[2]  （按其他键取消退出）" << endl;
			cin >> o;
			if (o == 1)
			{
				bool a;
				a=save(stu,n);
				if (a == 1)
				{
					cout << "按任意键退出" << endl;
					_getch();
					break;
				}
				else
				{
					cout << "保存失败，按任意键返回菜单"<<endl;
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
		default:cout << "输入错误，请重新选择" << endl;
		}
	}
	cout << "欢迎再次使用本系统" << endl;
	system("pause");
	return (0);
}