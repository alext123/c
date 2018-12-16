#define N 100
struct student
{
	char num[8];
	char name[20];
	int s[3];
};
int readfile(student stu[]);
void menu();
int save(student stu[], int n);
void display(student stu[], int n);
int search(student stu[], int n);
int add(student stu[], int &n);
int delet(student stu[], int n);
int modify(student stu[], int n);
//void statis(student stu[], int n);
//void sort(student stu[], int n);



