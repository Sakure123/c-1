#include "Boss.h"
Boss::Boss(int id, string name, int dId)
{
	this->m_Id = id;
	this->m_name = name;
	this->m_deptId = dId;
}
void Boss::showInfo()
{
	cout << "姓名：" << this->m_name
		<< "\t编号：" << this->m_Id
		<< "\t岗位：" << this->gerDeptName()
		<< "\t职责：交代任务给经理" << endl;
}
string Boss::gerDeptName()
{
	return "老板";
}
