#include<iostream>
using namespace std;
#include"workerMananage.h"
#include"worker.h"
#include"Employee.h"
#include"Mananager.h"
#include"Boss.h"
int main()
{
	//Worker* worker=nullptr;
	//worker = new Employee(1, "张三", 1);
	//worker->showInfo();
	//delete worker;

	//worker = new Mananager(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new Boss(3, "王五", 3);
	//worker->showInfo();
	//delete worker;

	workerMananage wr;
	int choice = 0;
	while (true)
	{
		wr.showMemu();
		cout << "请输入您的选择" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0: wr.ExitSystem();
			break;
		case 1: wr.Add_Emp();
			break;
		case 2: wr.show_Emp();
			break;
		case 3: wr.del_Emp();
			break;
		case 4: wr.Mod_Emp();
			break;
		case 5: wr.find_Emp();
			break;
		case 6: wr.Sort_Emp();
			break;
		case 7: wr.clean_Emp();
			break;
		default:
			system("cls");
			break;
		}
	}
}