#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"worker.h"
#include"Employee.h"
#include"Mananager.h"
#include"Boss.h"
#include<fstream>
class workerMananage
{
public:
	workerMananage();

	int m_EmpNum;
	Worker** m_EmArray;
	bool is_EmptyFile;

	void Add_Emp();
	void Save();
	void show_Emp();

	int get_Number();
	void init_Emp();
	void del_Emp();
	int is_Exit(int id);

	void Mod_Emp();

	void showMemu();
	void ExitSystem();
	void find_Emp();
	void Sort_Emp();
	void clean_Emp();

	 ~workerMananage();
};

