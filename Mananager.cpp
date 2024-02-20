#include "Mananager.h"
Mananager::Mananager(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Mananager::showInfo()
{
	cout << "姓名：" << this->m_name
		<< "\t编号：" << this->m_Id
		<< "\t岗位：" << this->gerDeptName()
		<< "\t职责：完成老板交代的任务同时交代任务给职工" << endl;
}
string Mananager::gerDeptName()
{
	return "经理";
}