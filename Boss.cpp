#include "Boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Boss::showInfo()
{
	cout << "������" << this->m_name
		<< "\t��ţ�" << this->m_Id
		<< "\t��λ��" << this->gerDeptName()
		<< "\tְ�𣺽������������" << endl;
}
string Boss::gerDeptName()
{
	return "�ϰ�";
}
