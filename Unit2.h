//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#endif
#include <vcl.h>
#include "math.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int fun (int,int,int,int);

class Projects{
	public :
	char Name[20];
	char Task[20];
	char NameExec[20];
	char NameLider[20];
	int year1;
	int month1;
	int day1;
	int year2;
	int month2;
	int day2;
	int Time;

	void GetInformation(FILE *fp, char *name, char *task, char *nameexec, char *namelider, int year1, int month1, int day1, int year2, int month2, int day2){

	strcpy(Name, name);
	strcpy(Task, task);
	strcpy(NameExec, nameexec);
	strcpy(NameLider, namelider);
	this->year1 = year1;
	this->month1 = month1;
	this->day1 = day1;
	this->year2 = year2;
	this->month2 = month2;
	this->day2 = day2;
	Timer(day1, month1, year1, day2, month2, year2);
	}

	void Print(char *temp, TMemo *Memo1){
		if(strcmp(temp, NameLider) == 0)
		{
			//Memo1->Lines->Add("Работает");
			Memo1->Lines->Add(AnsiString("Название: ") + Name);
			Memo1->Lines->Add(AnsiString("Задание: ") + Task);
			Memo1->Lines->Add(AnsiString("Сотрудник: ") + NameExec);
			Memo1->Lines->Add(AnsiString("Руководитель: ") + NameLider);
			Memo1->Lines->Add(AnsiString("Дата начала: ") + AnsiString(day1) + " "+AnsiString(month1) + " " + AnsiString(year1));
			Memo1->Lines->Add(AnsiString("Дата конца: ") + AnsiString(day2) + " "+AnsiString(month2) + " " + AnsiString(year2));
		}
	}
	void PrintLiderProjets (char *temp, TMemo *Memo1)
	{
		if(strcmp(temp, NameExec) == 0)
			Memo1->Lines->Add(AnsiString("Задание: ") + Task);

	}
	void PrintProjeсtExec (char *temp, TMemo *Memo1)
	{
		if(strcmp(temp, Name) == 0)
			Memo1->Lines->Add(AnsiString("Сотрудник: ") + NameExec);
	}
	void Read(FILE *fp,TMemo *Memo1){

		fscanf(fp,"%s",Name);
		fscanf(fp,"%s",Task);
		fscanf(fp,"%s",NameExec);
		fscanf(fp,"%s",NameLider);

		fscanf(fp,"%d",&day1);
		fscanf(fp,"%d",&month1);
		fscanf(fp,"%d",&year1);
		fscanf(fp,"%d",&day2);
		fscanf(fp,"%d",&month2);
		fscanf(fp,"%d",&year2);
		Time = Timer(day1, month1, year1, day2, month2, year2);

		Memo1->Lines->Add(AnsiString("Название:") + Name);
		Memo1->Lines->Add(AnsiString("Задание:") + Task);
		Memo1->Lines->Add(AnsiString("Сотрудник:") + NameExec);
		Memo1->Lines->Add(AnsiString("Руководитель:") + NameLider);
		Memo1->Lines->Add(AnsiString("Дата начала:") + AnsiString(day1) + " "+AnsiString(month1) + " " + AnsiString(year1));
		Memo1->Lines->Add(AnsiString("Дата конца:") + AnsiString(day2) + " "+AnsiString(month2) + " " + AnsiString(year2));
	}

	int Timer(int day1, int month1, int year1, int day2, int month2, int year2)
	{
		int i, day, day0, year, daymonth=0;
		year = year2 - year1;
		day0 = year / 4;
		day = year * 365;
		Time = year * 365;
		day += day0;
		Time += day0;
		daymonth = fun (month1, daymonth, day1, year1);
		day -= daymonth;
		Time -= daymonth;
		daymonth = 0;
		daymonth = fun (month2, daymonth, day2, year2);
		day += daymonth;
		Time += daymonth;
		return Time;
	}

	void Clock(TMemo *Memo1){
	if(Time > 31)
	{
		Memo1->Lines->Add("Работает 2");
		Memo1->Lines->Add(AnsiString("Название:") + Name);
		Memo1->Lines->Add(AnsiString("Задание:") + Task);
		Memo1->Lines->Add(AnsiString("Сотрудник:") + NameExec);
		Memo1->Lines->Add(AnsiString("Руководитель:") + NameLider);
		Memo1->Lines->Add(AnsiString("Дата начала:") + AnsiString(day1) + " " + AnsiString(month1) + " " + AnsiString(year1));
		Memo1->Lines->Add(AnsiString("Дата конца:") + AnsiString(day2) + " " + AnsiString(month2) + " " + AnsiString(year2));
		Memo1->Lines->Add(AnsiString("Время выполнения") + Time);
	}
}
	int fun (int month1, int daymonth, int day1, int year)
	{
	switch(month1)
	{
	case 1:
		daymonth = 0 + day1;
		break;
	case 2:
		daymonth = 31 + day1;
		break;
	case 3:
		if (year - (year / 4) * 4 == 0)daymonth = day1 + 60;
		else daymonth = 59 + day1;
		break;
	case 4:
		if (year - (year / 4) * 4 == 0)daymonth = 91 + day1;
		else daymonth = 90 + day1;
		break;
	case 5:
		if (year -(year / 4) * 4 == 0) daymonth = 121 + day1;
		else daymonth = 120 + day1;
		break;
	case 6:
		if (year - (year / 4) * 4 == 0) daymonth = 152 + day1;
		else daymonth = 151 + day1;
		break;
	case 7:
		if (year - (year / 4) * 4 == 0) daymonth = 182 + day1;
		else daymonth=181+day1;
		break;
	case 8:
		if (year - (year / 4) * 4 == 0) daymonth = 213 + day1;
		else daymonth = 212 + day1;
		break;
	case 9:
		if (year - (year / 4) * 4 == 0) daymonth = 244 + day1;
		else daymonth = 243 + day1;
		break;
	case 10:
		if (year - (year / 4) * 4 == 0) daymonth = 274 + day1;
		else daymonth = 273 + day1;
		break;
	case 11:
		if (year - (year / 4) * 4 == 0) daymonth = 305 + day1;
		else daymonth = 304 + day1;
		break;
	case 12:
		if (year - (year / 4) * 4 == 0) daymonth = 335 + day1;
		else daymonth = 334 + day1;
		break;
	}
	return daymonth;
	}
};
