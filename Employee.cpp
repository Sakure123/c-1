#include "Employee.h"
 Employee::Employee(int id, string name, int dId)
 {
	 this->m_Id = id;
	 this->m_name = name;
	 this->m_deptId = dId;
 }
 void Employee::showInfo()
 {
	 cout << "姓名：" << this->m_name
		 << "\t编号：" << this->m_Id
		 << "\t岗位：" << this->gerDeptName()
		 << "\t职责：完成经理交代的任务" << endl;
 }
 string Employee::gerDeptName()
 {
	 return "员工";
 }