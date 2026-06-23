#include<iostream>
#include<iomanip>
using namespace std;
const int MAX_STUDENTS=100;
struct StStudentInfo{
	string StudentsName;
	float StudentsMarks;
};

int ReadPositiveNumber(string Message){
	int Number;
	do{
	cout<<Message;
	cin>>Number;
	}while(Number<0);
return Number;	
}


void PrintHeader(string Header){
	cout<<"\n========================================================================================================"<<endl;

       cout<<"                                             "<<Header<<"                                               \n";
	 cout<<"\n========================================================================================================"<<endl;
}

bool isArrayEmpty(int NumberOfStudent){
	
if(NumberOfStudent==0){
PrintHeader("No Students Found,Please add Students First");
	return true;
}
return false;

}

void AddStudents(StStudentInfo students[MAX_STUDENTS],int &NumberOfStudent){
	
	PrintHeader("ADDING STUDENTS");
	int NewStudentsToAdd=ReadPositiveNumber("How many students do you want to add?\n");
	int TargetLimit=NumberOfStudent+NewStudentsToAdd;
	
	if(TargetLimit>MAX_STUDENTS){
	cout<<"\n Sorry, Can Not Add Students! This Will Exceed the maximum limit .\n";
	return;
	}
	for(int counter=NumberOfStudent;counter<TargetLimit;counter++){
	cout<<"Enter Name of student number : "<<counter+1<<endl;
	cin.ignore();
	getline(cin,students[counter].StudentsName);
	
	do{
		cout<<"Enter  Mark of student number : "<<counter+1<<endl;
		cin>>students[counter].StudentsMarks;
	}while(students[counter].StudentsMarks<0 || students[counter].StudentsMarks>100);
	
	}
	NumberOfStudent=TargetLimit;
}

void PrintMarks(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("STUDENT MARKS");
	cout<<left<<setw(10)<<"ID"<<setw(20)<<"Student Name "<<setw(10)<<"Mark"<<endl;
	for(int counter=0;counter<NumberOfStudent;counter++){
cout<<left<<setw(10)<<counter+1<<setw(20)<<students[counter].StudentsName<<setw(10)<<students[counter].StudentsMarks<<"\n";  

}
}


int SearchStudent(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent,string NameToSearch){
	
   for(int i = 0; i <NumberOfStudent; i++) 
    { 
   if (students[i].StudentsName==NameToSearch) 
   return i; 
 } 
 return -1; 
 
}

void PrintFoundStudent(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("SEARCH STUDENT");
	string NameToSearch;
	cout<<"Enter The Name Of Student \n";
	cin.ignore();
	getline(cin,NameToSearch);
	int index=SearchStudent(students,NumberOfStudent,NameToSearch);
	
	if(index>=0){
	cout<<"----------------------------\n";
	cout<<"STUDENT FOUND SUCCESSFULLY !\n";
	cout<<"----------------------------\n";
	cout<<"Name: "<<students[index].StudentsName<<"\n";
	cout<<"Mark: "<<students[index].StudentsMarks<<"\n";
	cout<<"ID of Student: "<<index+1<<endl;
	}
	else
	cout<<"Student Not Found!\n";
	
}
void UpdateStudent(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("UPDATE STUDENT");
	string Name;
	int choice;
	cout<<"Enter student name to update: ";
	cin.ignore();
	getline(cin,Name);
	int index=SearchStudent(students, NumberOfStudent,Name);
	if(index==-1){
	cout<<"Student not found!\n";
	return;
	}
	
	else{
	cout<<"What do you want to update?\n";
	cout<<"[1]Update Name\n[2]Update Mark\n[3]Update Both\n";
	cin>>choice;
	
	if(choice==1||choice==3){
	cout<<"Enter New Name \n";
	cin>>students[index].StudentsName;
	cout<<"Student Name Updated Successfully!\n";
	}
	
	if(choice==2||choice==3){
	do{
	cout<<"Enter New Mark \n";
	cin>>students[index].StudentsMarks;	
	}while(students[index].StudentsMarks<0 || students[index].StudentsMarks>100);
	cout<<"Student Info Updated Successfully!\n";
}
}
}

void DeleteStudent(StStudentInfo students[MAX_STUDENTS],int &NumberOfStudent){
	
	PrintHeader("Delete Student");
	string Name;
	cout<<"Enter student name to Delete: ";
	cin.ignore();
	getline(cin,Name);
	int index=SearchStudent(students, NumberOfStudent,Name);
	
	if(index==-1){
	cout<<"Student not found!\n";
	return;
	}
	
	for(int counter=index;counter<NumberOfStudent-1;counter++){
		students[counter]=students[counter+1];
	}
	NumberOfStudent--;
	cout<<"Student Deleted Successfully!\n";
}

void CountTotalStudents(int TotalStudent){
	
	PrintHeader("COUNT TOTAL STUDENT");
	cout<<"Total student is: "<<TotalStudent<<endl;
	
}

void CountPassedStudents(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
PrintHeader("TOTAL PASSED STUDENTS");
	int counter=0;
	for(int i=0;i<NumberOfStudent;i++){
		if(students[i].StudentsMarks<=100 && students[i].StudentsMarks>=50)
        counter++;
	}
	 cout<<"The number Of Passed students is: "<<counter<<endl;
	 
}

void CountFailStudents(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("TOTAL FAILED STUDENT");
	int counter=0;
	for(int i=0;i<NumberOfStudent;i++){
	if(!(students[i].StudentsMarks<=100 && students[i].StudentsMarks>=50))
        counter++;
	}
	 cout<<"The number Of Faild students is: "<<counter<<endl;
}

void MaxMark(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent ){
	
	PrintHeader("MAX MARK");
	float Max=students[0].StudentsMarks;
	for(int counter=1;counter<NumberOfStudent;counter++){
		if(students[counter].StudentsMarks>Max)
		Max=students[counter].StudentsMarks;
	}
cout<<"The Max Mark is: "<<Max<<endl;
	
} 


void MinMark(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("MIN MARK");
	float Min=students[0].StudentsMarks;
	
	for(int counter=1;counter<NumberOfStudent;counter++){
		if(students[counter].StudentsMarks<Min)
		Min=students[counter].StudentsMarks;
	}
	
cout<<"The Min Mark is: "<<Min<<endl;	
} 

char CheckMark(float Mark){
	
	if( Mark>=90)
	return'A';
	else if(Mark>=80)
	return'B';
	else if(Mark>=70)
	return'C';
	else if(Mark>=60)
	return'D';
	else if(Mark>=50)
	return'E';
	else
	return'F';
}

void EstimationOfMark(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("ESTIMATION OF MarkS");
	for(int counter=0;counter<NumberOfStudent;counter++){
	cout<<"Mark "<<counter+1<<" Estimation Of Mark is : "<<CheckMark(students[counter].StudentsMarks)<<endl;
	}
}

void PrintPassedStudent(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("PASSED STUDENTS");
	cout<<left<<setw(10)<<"ID"<<setw(20)<<"Student Name "<<setw(10)<<"Mark"<<endl;
	for(int i=0;i<NumberOfStudent;i++){
		if(students[i].StudentsMarks<=100 && students[i].StudentsMarks>=50)
cout<<left<<setw(10)<<i+1<<setw(20)<<students[i].StudentsName<<setw(10)<<students[i].StudentsMarks<<"\n";
  
}	
}

void PrintFailedStudent(StStudentInfo students[MAX_STUDENTS],int NumberOfStudent){
	
	PrintHeader("FAILED STUDENTS");
	cout<<left<<setw(10)<<"ID"<<setw(20)<<"Student Name "<<setw(10)<<"Mark"<<endl;
	
	for(int i=0;i<NumberOfStudent;i++){
		if(!(students[i].StudentsMarks<=100 && students[i].StudentsMarks>=50))
cout<<left<<setw(10)<<i+1<<setw(20)<<students[i].StudentsName<<setw(10)<<students[i].StudentsMarks<<"\n";  
}	
}
	
int PrintMenu(){
	
PrintHeader("STUDENTS MARKS MANAGEMENT");
cout<<"(1)  Add student \n";
cout<<"(2)  Show Students Marks\n";
cout<<"(3)  Search Student\n";
cout<<"(4)  Count Students\n";
cout<<"(5)  Show & Count Passed Students\n";
cout<<"(6)  Show & Count failed Students\n";
cout<<"(7)  Find Maximum Mark\n";
cout<<"(8)  Find Minimum Mark\n";
cout<<"(9)  Estimation Of Mark\n";
cout<<"-------------------------------\n";
cout<<"(10)  Update Student \n";
cout<<"(11)  Delete Student\n";
cout<<"(12)  Show History\n";
cout<<"(13)  Exit\n";

int choice=ReadPositiveNumber("Choose : _\n");
return choice;
}

void ReturnToMenu(){
	
cout<<"\n\nPress enter to return to main menu ...\n";
system("pause>nul");

}

void LogOperation(string History[100][2], int &HistoryCount, string OpType, string TargetName){
	
    if (HistoryCount < 100) { 
        History[HistoryCount][0] = OpType;
        History[HistoryCount][1] = TargetName;
        HistoryCount++;
    }
}

void PrintHistory(string History[100][2], int HistoryCount) {
	
    PrintHeader("SYSTEM OPERATIONS HISTORY");

    if (HistoryCount == 0) {
        cout << "\n No operations recorded yet!\n";
        return;
    }

    cout << "===============================================================\n";
    cout << left << setw(7) << "Index" << setw(28) << "Operation Type" << setw(25) << "Detail";
    cout << "\n===============================================================\n";

    for (int i = 0; i < HistoryCount; i++) {
        cout << left << setw(7) << (i + 1)
             << setw(28) << History[i][0]   
             << setw(25) << History[i][1];  
        cout << "\n---------------------------------------------------------------\n";
    }
}

void Choose(int choice,StStudentInfo ClassOf2026[MAX_STUDENTS],int &TotalStudent,string History[100][2],int &HistoryCount){
	switch(choice){
	case 1:
	system("cls");
	system("color 0A");
	AddStudents(ClassOf2026,TotalStudent);
      LogOperation(History, HistoryCount, "Add Student", "-----");
	ReturnToMenu();
	break;
	
	case 2:
	system("cls");
	system("color 0B");
	PrintMarks(ClassOf2026,TotalStudent);
      LogOperation(History, HistoryCount, "Print Marks", "-----");
	ReturnToMenu();
	break;
	
	case 3:
	system("cls");
	system("color 0F");
	PrintFoundStudent(ClassOf2026,TotalStudent);
      LogOperation(History, HistoryCount, "Search Student", "----");
	ReturnToMenu();
	break;
	
	case 4:
	system("cls");
	system("color 0F");
	CountTotalStudents(TotalStudent);
      LogOperation(History, HistoryCount, "Count Total Students", "----");
	ReturnToMenu();
	break;
	
	case 5:
	system("cls");
	system("color 0A");
	PrintPassedStudent(ClassOf2026,TotalStudent);
	CountPassedStudents(ClassOf2026,TotalStudent);
      LogOperation(History, HistoryCount, "Show Passed Students", "----");
	ReturnToMenu();
	break;
	
	case 6:
	system("cls");
	system("color 0C");
	PrintFailedStudent(ClassOf2026,TotalStudent);
	CountFailStudents(ClassOf2026,TotalStudent);
	LogOperation(History, HistoryCount, "Show Failed Students", "----");
	ReturnToMenu();
	break;
	
	case 7:
	system("cls");
	system("color 0A");
	MaxMark(ClassOf2026,TotalStudent);
	LogOperation(History, HistoryCount, "Find Mix Mark", "----");
	ReturnToMenu();
	break;
	
	case 8:
	system("cls");
	system("color 0E");
	MinMark(ClassOf2026,TotalStudent);
	LogOperation(History, HistoryCount, "Show Min Mark", "----");
	ReturnToMenu();
	break;
	
	case 9:
	system("cls");
	system("color 0F");
	EstimationOfMark(ClassOf2026,TotalStudent);
	LogOperation(History, HistoryCount, "Estimation Of Mark", "----");
	ReturnToMenu();
	break;
	
	case 10:
	system("cls");
	system("color 0E");
	UpdateStudent(ClassOf2026,TotalStudent);
	LogOperation(History, HistoryCount, " Update Student", "-----");
	ReturnToMenu();
	break;
	
	case 11:
	system("cls");
	system("color 0C");
	DeleteStudent(ClassOf2026,TotalStudent);
	LogOperation(History, HistoryCount, "Delete Student","-----");
	ReturnToMenu();
	break;
	
	case 12:
	system("cls");
	system("color 0B");
	PrintHistory(History, HistoryCount); 
	ReturnToMenu();
      break;
      
	case 13:
	system("cls");
	system("color 0A");
	PrintHeader("THANK YOU FOR USING OUR SIMPLE SYSTEM .BYE!");
	break;
	
	default:
	cout<<"invalid choice\n";
	}
}
	
int main(){
int choice;
StStudentInfo ClassOf2026[MAX_STUDENTS];
int TotalStudent=0;
string NameToSearch;
string History[MAX_STUDENTS][2];
int HistoryCount=0;

do{
system("cls");
system("color 0F");
choice=PrintMenu();

if(choice!=1&&choice!=13)

if(isArrayEmpty(TotalStudent))
continue;
Choose(choice,ClassOf2026,TotalStudent,History,HistoryCount);
}while(choice!=13);

return 0;
}
