#include "Employee.h"
 Employee::Employee(int id, string name, int dId)
 {
	 this->m_Id = id;
	 this->m_name = name;
	 this->m_deptId = dId;
 }
 void Employee::showInfo()
 {
	 cout << "������" << this->m_name
		 << "\t��ţ�" << this->m_Id
		 << "\t��λ��" << this->gerDeptName()
		 << "\tְ����ɾ�����������" << endl;
 }
 string Employee::gerDeptName()
 {
	 return "Ա��";
 }