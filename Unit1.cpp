//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Projects A[20];
int i = 0;
int r = 0;
char Temp[20];
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
Memo1->Clear();
ifstream in("C:\\Users\\PC\\Desktop\\Laba2.txt");
string s;
while (in.peek() != EOF)
{
	getline(in, s);
	r ++;
}
in.close();

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
FILE *file;
file = fopen("C:\\Users\\PC\\Desktop\\Laba2.txt","a+");
AnsiString Name = Form1->Edit1->Text;

AnsiString Task = Form1->Edit2->Text;

AnsiString NameExec = Form1->Edit3->Text;

AnsiString NameLider = Form1->Edit4->Text;

int day1, month1, year1, day2, month2, year2;
int Day1, Month1, Year1, Day2, Month2, Year2;
strcpy(A[i].Name, Name.c_str());
strcpy(A[i].Task, Task.c_str());
strcpy(A[i].NameExec, NameExec.c_str());
strcpy(A[i].NameLider, NameLider.c_str());

fputs(A[i].Name,file);
fputs("\n",file);

fputs(A[i].Task,file);
fputs("\n",file);

fputs(A[i].NameExec,file);
fputs("\n",file);

fputs(A[i].NameLider,file);
fputs("\n",file);

day1 = StrToInt(Edit5->Text);
Day1 = 1;
fprintf(file,"%d", day1);
fputs("\n",file);

month1 = StrToInt(Edit6->Text);
Month1 = month1;
fprintf(file,"%d", month1);
fputs("\n",file);

year1 = StrToInt(Edit7->Text);
Year1 = year1;
fprintf(file,"%d", year1);
fputs("\n",file);

day2 = StrToInt(Edit8->Text);
Day2 = day2;
fprintf(file,"%d", day2);
fputs("\n",file);

month2 = StrToInt(Edit9->Text);
Month2 = month2;
fprintf(file,"%d", month2);
fputs("\n",file);

year2 = StrToInt(Edit10->Text);
Year2 = year2;
fprintf(file,"%d", year2);
fputs("\n",file);
Memo1->Lines->Add(A[i].Name);
Memo1->Lines->Add(A[i].Task);
Memo1->Lines->Add(A[i].NameExec);
Memo1->Lines->Add(A[i].NameLider);
Memo1->Lines->Add(day1);
Memo1->Lines->Add(month1);
Memo1->Lines->Add(year1);
Memo1->Lines->Add(day2);
Memo1->Lines->Add(month2);
Memo1->Lines->Add(year2);
A[i].GetInformation(file,A[i].Name, A[i].Task, A[i].NameExec, A[i].NameLider, year1, month1, day1, year2, month2, day2);
i ++;
fclose(file);
}
//---------------------------------------------------------------------------
void a(TMemo *Memo){

}
void __fastcall TForm1::Button3Click(TObject *Sender)
{
	Memo1->Clear();
	AnsiString temp = Form1->Edit11->Text;
	strcpy(Temp, temp.c_str());

	for(int j = 0; j < i; j++)
	{
		A[j].Print(Temp, Memo1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
	Memo1->Lines->Clear();
	for(int j = 0; j < i; j++)
	{
		A[j].Clock(Memo1);
	}
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button2Click(TObject *Sender)
{
	FILE *file2;
	Memo1->Clear();
	i += (r / 10);
	file2 = fopen("C:\\Users\\PC\\Desktop\\Laba2.txt","r+");
	for(int j = 0; j < i; j++)
		A[j].Read(file2, Memo1);
}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{
	Memo1->Clear();
	AnsiString temp = Form1->Edit12->Text;
	strcpy(Temp, temp.c_str());
	for(int j=0; j < i; j++)
	{
		A[j].PrintLiderProjets(Temp,Memo1);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
	Memo1->Clear();
	AnsiString temp = Form1->Edit13->Text;
	strcpy(Temp, temp.c_str());
	for(int j=0; j < i; j++)
	{
		A[j].PrintProjeсtExec(Temp, Memo1);
	}

}
//---------------------------------------------------------------------------

