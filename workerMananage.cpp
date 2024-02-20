#include "workerMananage.h"
workerMananage::workerMananage()
{
	ifstream ifs;
	ifs.open("empFILE.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this-> m_EmpNum = 0;
		this-> m_EmArray = NULL;
		this->is_EmptyFile = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmArray = NULL;
		this->is_EmptyFile = true;
		ifs.close();
		return;
	}
	int num = get_Number();
	//cout << "职工数量：" << endl;
	this->m_EmpNum = num;
	this->m_EmArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}
void workerMananage::showMemu()
{
	cout << "************************************" << endl;
	cout << "********欢迎使用职工管理系统********" << endl;
	cout << "***********0.退出管理系统***********" << endl;
	cout << "***********1.增加职工信息***********" << endl;
	cout << "***********2.显示职工信息***********" << endl;
	cout << "***********3.删除离职职工***********" << endl;
	cout << "***********4.修改职工信息***********" << endl;
	cout << "***********5.查找职工信息***********" << endl;
	cout << "***********6.按照编号排序***********" << endl;
	cout << "***********7.清空所有文档***********" << endl;
	cout << "************************************" << endl;
}
void workerMananage::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workerMananage::Add_Emp()
{
	cout << "请输入添加职工的数量：" << endl;
	int Emy_Num = 0;
	cin >> Emy_Num;
	if (Emy_Num > 0)
	{
		int newSize = this->m_EmpNum + Emy_Num;
		Worker** newSpace = new Worker * [newSize];
		int i = 0;
		if (this->m_EmArray != NULL)
		{

			for (i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = m_EmArray[i];
			}
		}
		for (i = 0; i < Emy_Num; i++)
		{
			int id;
			string name;
			int dIdSelet;
			cout << "请输入" << i + 1 << "名新职工编号：" << endl;
			cin >> id;
			while ((this->is_Exit(id) != -1))
			{
				cout << "输入编号重复，请重新输入" << endl;
				cout << "请输入" << i + 1 << "名新职工编号：" << endl;
				cin >> id;
			}
			cout << "请输入" << i + 1 << "名新职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工的岗位：" << endl;
			cout << "1.普通职工  2.经理  3.老板" << endl;
			cin >> dIdSelet;
			Worker* worker = NULL;
			switch (dIdSelet)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Mananager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmArray;
		this->m_EmArray = newSpace;
		this->m_EmpNum = newSize;
		this->is_EmptyFile = false;
		cout << "职工添加成功" << endl;
		this->Save();
	}
	else
	{
		cout << "输入数量有误" << endl;
	}
	system("pause");
	system("cls");
}
void workerMananage::Save()
{
	ofstream ofs;
	ofs.open("empFILE.txt", ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmArray[i]->m_Id << " "
			<< this->m_EmArray[i]->m_name << " "
			<< this->m_EmArray[i]->m_deptId << endl;
	}
	ofs.close();
}
int workerMananage::get_Number()
{
	ifstream ifs;
	ifs.open("empFILE.txt", ios::in);
	int num = 0;
	int id;
	string name;
	int dId;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}
void workerMananage::init_Emp()
{
	ifstream ifs;
	ifs.open("empFILE.txt", ios::in);
	int id;
	string name;
	int dId;
	int idex = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			worker = new Mananager(id, name, dId);
		}
		else
		{
			worker = new Boss(id, name, dId);
		}
		this->m_EmArray[idex] = worker;
		idex++;
	}
	ifs.close();
}
void workerMananage::show_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void workerMananage::del_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入要删除的员工编号" << endl;
		int id;
		cin >> id;
		int idex = this->is_Exit(id);
		if (idex != -1)
		{
			if (idex == this->m_EmpNum - 1)
			{
				this->m_EmpNum--;
			}
			else
			{
				for (int i = idex; i < this->m_EmpNum - 1; i++)
				{
					this->m_EmArray[i] = this->m_EmArray[i + 1];
				}
				this->m_EmpNum--;
			}
			this->Save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
int workerMananage::is_Exit(int id)
{
	int idex = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmArray[i]->m_Id == id)
		{
			idex = i;
			break;
		}
	}
	return idex;
}
void workerMananage::Mod_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入要修改的员工编号" << endl;
		int id;
		cin >> id;
		int idex = 0;
		idex = this->is_Exit(id);
		if (idex != -1)
		{
			delete this->m_EmArray[idex];
			int newid=0;
			string name="";
			int dId=0;
			cout << "请输入新的职工编号：" << endl;
			cin >> newid;
			cout << "请输入新的职工姓名：" << endl;
			cin >> name;
			cout << "请输入新的职工岗位：" << endl;
			cout << "1.普通职工  2.经理  3.老板" << endl;
			cin >> dId;
			Worker* worker = NULL;
			switch (dId)
			{
			case 1:
				worker = new Employee(newid, name, dId);
				break;
			case 2:
				worker = new Mananager(newid, name, dId);
				break;
			case 3:
				worker = new Boss(newid, name, dId);
				break;
			default:
				break;
			}
			this->m_EmArray[idex] = worker;
			this->Save();
			cout << "修改成功" << endl;
		}
		else
		{
			cout << "修改失败，未找到该职工" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerMananage::find_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请输入查找方式：" << endl;
		cout << "1.按照编号查找" << endl;
		cout << "2.按照姓名查找" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "请输入查找人的编号：" << endl;
			cin >> id;
			int res = this->is_Exit(id);
			if (res != -1)
			{
				cout << "查找人的信息如下：" << endl;
				this->m_EmArray[res]->showInfo();
			}
			else
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "请输入查找人的姓名" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmArray[i]->m_name == name)
				{
					cout << "查找人的信息如下：" << endl;
					this->m_EmArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else
		{
			cout << "输入错误" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerMananage::Sort_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "文件为空或不存在" << endl;
	}
	else
	{
		cout << "请选择排序方式：" << endl;
		cout << "1.职工的编号按升序排" << endl;
		cout << "2.职工的编号按降序排" << endl;
		int select = 0;
		cin >> select;
			int k = 0;
			int maxszie=0;
			for (int i = 1; i <= this->m_EmpNum; i++)
			{
				maxszie = this->m_EmArray[this->m_EmpNum-i]->m_Id;
				k = this->m_EmpNum - i;
				for (int j = this->m_EmpNum - i - 1; j >= 0; j--)
				{
					if (select == 1)
					{
						if (this->m_EmArray[j]->m_Id > maxszie)
						{
							maxszie = this->m_EmArray[j]->m_Id;
							k = j;
						}
					}
					else
					{
						if (this->m_EmArray[j]->m_Id < maxszie)
						{
							maxszie = this->m_EmArray[j]->m_Id;
							k = j;
						}
					}
				}
				Worker* temp = this->m_EmArray[this->m_EmpNum - i];
				this->m_EmArray[this->m_EmpNum - i]= this->m_EmArray[k];
				this->m_EmArray[k] = temp;
			}
			cout << "排序完成，结果如下：" << endl;
			this->Save();
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				this->m_EmArray[i]->showInfo();
			}
	}
	system("pause");
	system("cls");
}
void workerMananage::clean_Emp()
{
	cout << "确定要清空文件吗" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		ofstream ofs;
		ofs.open("empFILE.txt", ios::trunc);
		ofs.close();
		if (this->m_EmArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmArray[i];
				this->m_EmArray[i] = NULL;
			}
			delete[] this->m_EmArray;
			this->m_EmArray = NULL;
		}
		this->m_EmpNum = 0;
		this->is_EmptyFile = true;
		cout << "文件清空完成" << endl;
	}
	system("pause");
	system("cls");
}
workerMananage::~workerMananage()
{
	if (this->m_EmArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmArray[i];
			this->m_EmArray[i] = NULL;
		}
		delete[] this->m_EmArray;
		this->m_EmArray = NULL;
	}
}