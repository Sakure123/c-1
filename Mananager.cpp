#include "Mananager.h"
Mananager::Mananager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Mananager::showInfo()
{
	cout << "������" << this->m_name
		<< "\t��ţ�" << this->m_Id
		<< "\t��λ��" << this->gerDeptName()
		<< "\tְ������ϰ彻��������ͬʱ���������ְ��" << endl;
}
string Mananager::gerDeptName()
{
	return "����";
}