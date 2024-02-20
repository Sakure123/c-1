#pragma once
#include<iostream>
using namespace std;
#include<string>
#include"worker.h"
class Mananager:public Worker
{
public:
	Mananager(int id, string name, int dId);
	virtual void showInfo();
	virtual string gerDeptName();
};

