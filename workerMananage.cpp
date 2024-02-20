#include "workerMananage.h"
workerMananage::workerMananage()
{
	ifstream ifs;
	ifs.open("empFILE.txt", ios::in);
	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
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
		//cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		this->m_EmArray = NULL;
		this->is_EmptyFile = true;
		ifs.close();
		return;
	}
	int num = get_Number();
	//cout << "ְ��������" << endl;
	this->m_EmpNum = num;
	this->m_EmArray = new Worker * [this->m_EmpNum];
	this->init_Emp();
}
void workerMananage::showMemu()
{
	cout << "************************************" << endl;
	cout << "********��ӭʹ��ְ������ϵͳ********" << endl;
	cout << "***********0.�˳�����ϵͳ***********" << endl;
	cout << "***********1.����ְ����Ϣ***********" << endl;
	cout << "***********2.��ʾְ����Ϣ***********" << endl;
	cout << "***********3.ɾ����ְְ��***********" << endl;
	cout << "***********4.�޸�ְ����Ϣ***********" << endl;
	cout << "***********5.����ְ����Ϣ***********" << endl;
	cout << "***********6.���ձ������***********" << endl;
	cout << "***********7.��������ĵ�***********" << endl;
	cout << "************************************" << endl;
}
void workerMananage::ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workerMananage::Add_Emp()
{
	cout << "���������ְ����������" << endl;
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
			cout << "������" << i + 1 << "����ְ����ţ�" << endl;
			cin >> id;
			while ((this->is_Exit(id) != -1))
			{
				cout << "�������ظ�������������" << endl;
				cout << "������" << i + 1 << "����ְ����ţ�" << endl;
				cin >> id;
			}
			cout << "������" << i + 1 << "����ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1.��ְͨ��  2.����  3.�ϰ�" << endl;
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
		cout << "ְ����ӳɹ�" << endl;
		this->Save();
	}
	else
	{
		cout << "������������" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "������Ҫɾ����Ա�����" << endl;
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
			cout << "ɾ���ɹ�" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
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
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�Ա�����" << endl;
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
			cout << "�������µ�ְ����ţ�" << endl;
			cin >> newid;
			cout << "�������µ�ְ��������" << endl;
			cin >> name;
			cout << "�������µ�ְ����λ��" << endl;
			cout << "1.��ְͨ��  2.����  3.�ϰ�" << endl;
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
			cout << "�޸ĳɹ�" << endl;
		}
		else
		{
			cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerMananage::find_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��������ҷ�ʽ��" << endl;
		cout << "1.���ձ�Ų���" << endl;
		cout << "2.������������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			int id;
			cout << "����������˵ı�ţ�" << endl;
			cin >> id;
			int res = this->is_Exit(id);
			if (res != -1)
			{
				cout << "�����˵���Ϣ���£�" << endl;
				this->m_EmArray[res]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			string name;
			cout << "����������˵�����" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmArray[i]->m_name == name)
				{
					cout << "�����˵���Ϣ���£�" << endl;
					this->m_EmArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "�������" << endl;
		}
	}
	system("pause");
	system("cls");
}
void workerMananage::Sort_Emp()
{
	if (this->is_EmptyFile)
	{
		cout << "�ļ�Ϊ�ջ򲻴���" << endl;
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1.ְ���ı�Ű�������" << endl;
		cout << "2.ְ���ı�Ű�������" << endl;
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
			cout << "������ɣ�������£�" << endl;
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
	cout << "ȷ��Ҫ����ļ���" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
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
		cout << "�ļ�������" << endl;
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