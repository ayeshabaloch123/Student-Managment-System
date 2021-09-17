// student Managment system using file handling in c++
#include<iostream>
#include<fstream>
#include<conio.h>
using namespace std;
class student{
	private:
		string name,roll_no,course,address,email_id,contact_no;
	public:
	   void menu();
	   void insert();
	   void display();
	   void modify();
	   void search();
	   void deleted();
	    
	    
			
};
void student::menu()
{
    menustart:
   int choice;
   char x;
   system("cls");
   
 cout<<"\t\t  -----------------------------------"<<endl;
 cout<<"\t\t |   STUDENT  MANAGMENT  SYSTEM    |"<<endl;
 cout<<"\t\t  -----------------------------------"<<endl;
 cout<<endl<<endl;
   
   cout<<"\t\t\t 1.Enter student record  "<<endl;
   cout<<"\t\t\t 2.Display record  "<<endl;
   cout<<"\t\t\t 3.Modify record  "<<endl;
   cout<<"\t\t\t 4.search record  "<<endl;
   cout<<"\t\t\t 5.Delete record  "<<endl;
   cout<<"\t\t\t 6. Exit "<<endl;
   cout<<endl<<endl;
   
 cout<<"\t\t  -----------------------------------"<<endl;
 cout<<"\t\t    choose option: [ 1/2/3/4/5/6 ]   "<<endl;
 cout<<"\t\t  -----------------------------------"<<endl;
 
 cout<<"Enter your choice :";
 cin>>choice;
 
 switch(choice)
 {
    case 1:
    	do
    	{            insert();
    		cout<<"Enter another student record (Y,N) :";
    		cin>>x;
	    }while (x=='y'||x=='Y');
    	break;
    	case 2 :
    	display();
    	break;
    	case 3:
    		modify();
    		break;
    	case 4 :
    		search();
    		break;
    	case 5 :
    		deleted();
    		break;
    
    	case 6:
    		exit(0);
    	default:
    	    cout<<"\n\t\t\tInvalid choice.......Try again..";

    }
    getch();
    goto menustart;
    	    		 
 }
 void student::insert()     //add student details
 
 {
  system("cls");
  fstream file;
  
  cout<<"\n--------------------------------------------------------------------------"
    "--------------------------------------------------";
  cout<<"-----------------------------------------------------------Add student"
  "Details---------------------------------------------------------------------------"<<endl;
  cout<<"Enter student Name : ";
  cin>>name;
  cout<<"Enter Roll No : " ;
  cin>>roll_no;
  cout<<"Enter Course : ";
  cin>>course;
  cout<<"Enter Address : ";
  cin>>address;
  cout<<"Enter Email Id : ";
  cin>>email_id;
  cout<<"Enter Contect No : ";
  cin>>contact_no;
  file.open("studentRecord.txt",ios::app | ios::out);
  file<<"  "<<name<<"  "<<roll_no<<"  "<<course<<"  "<<address<<"  "<<email_id<<"  "<<contact_no<<" \n ";
  file.close();
  
  	
 }
 void student::display()
 {
 	system("cls");
 	fstream file;
 	
 	cout<<"\n----------------------------------------------------------------------------------------------"
 	"------------------------------------------"
 	"--------------------------------------------student Record Table ---------------------------------------"
 	<<endl;
 
 	
 	file.open("studentRecord.txt",ios::in);
 	if(!file)
 	{
 		cout<<"\n\t\t No Data Is Present..............";
 		file.close();
	 }
 	else
 	{
 		file>>name>>roll_no>>course>>address>>email_id>>contact_no;
 		while(!file.eof())
 		{
 			cout<<"\n\n\t\t Student Name : "<<name<<endl;
 			cout<<"\n\n\t\t Student Roll No : "<<roll_no<<endl;
 			cout<<"\n\n\t\t Student Course : "<<course<<endl;
 			cout<<"\n\n\t\t Student Address : "<<address<<endl;
 			cout<<"\n\n\t\t Student Email Id : "<<email_id<<endl;
 			cout<<"\n\n\t\t Student Contect No : "<<contact_no<<endl;
 			file>>name>>roll_no>>course>>address>>email_id>>contact_no;
 			
}
		 }
	  file.close();
 }
 
 void student::modify() // Modify details of student
{
    system("cls");
    fstream file, file1;
    string rollno;
    int found = 0;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Student Modify Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want to Modify: ";
        cin >> rollno;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno != roll_no)

                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            else
            {
                cout << "\n\t\t\tEnter Name: ";
                cin >> name;
                cout << "\t\t\tEnter Roll No.: ";
                cin >> roll_no;
                cout << "\t\t\tEnter Course: ";
                cin >> course;
                cout << "\t\t\tEnter Email Id(name@gmail.com): ";
                cin >> email_id;
                cout << "\t\t\tEnter Contact No(9639xxxxxx): ";
                cin >> contact_no;
                cout << "\t\t\tEnter Address: ";
                cin >> address;
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Student Roll No. Not Found....";
            }
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}

void student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Data --------------------------------------------" << endl;
        cout << "\n\t\t\tNo Data is Present... " << endl;
    }
    else
    {
        string rollno;
        cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
        cout << "------------------------------------- Student Search Table --------------------------------------------" << endl;
        cout << "\nEnter Roll No. of Student which you want to search: ";
        cin >> rollno;
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (rollno == roll_no)
            {
                cout << "\n\n\t\t\tName: " << name << "\n";
                cout << "\t\t\tRoll No.: " << roll_no << "\n";
                cout << "\t\t\tCourse: " << course << "\n";
                cout << "\t\t\tEmail Id: " << email_id << "\n";
                cout << "\t\t\tContact No.: " << contact_no << "\n";
                cout << "\t\t\tAddress: " << address << "\n";
                found++;
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
            if (found == 0)
            {
                cout << "\n\t\t\t Student Roll NO. Not Found....";
            }
        }
        file.close();
    }
}
void student::deleted() // ddeleted data of student
{
    system("cls");
    fstream file, file1;
    int found = 0;
    string roll;
    cout << "\n-------------------------------------------------------------------------------------------------------" << endl;
    cout << "------------------------------------- Delete Student Details ------------------------------------------" << endl;
    file.open("studentRecord.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tNo Data is Present..";
        file.close();
    }
    else
    {
        cout << "\nEnter Roll No. of Student which you want Delete Data: ";
        cin >> roll;
        file1.open("record.txt", ios::app | ios::out);
        file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        while (!file.eof())
        {
            if (roll != roll_no)
            {
                file1 << " " << name << " " << roll_no << " " << course << " " << email_id << " " << contact_no << " " << address << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Delete Data";
            }
            file >> name >> roll_no >> course >> email_id >> contact_no >> address;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Student Roll NO. Not Found....";
        }
        file1.close();
        file.close();
        remove("studentRecord.txt");
        rename("record.txt", "studentRecord.txt");
    }
}
main()
{
    student project; // object
    project.menu();
   
    
}
