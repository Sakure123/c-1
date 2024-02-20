#pragma once
#include<iostream>
using namespace std;
#include<string>
class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string gerDeptName() = 0;

	int m_Id;
	string m_name;
	int m_deptId;
};