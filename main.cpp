#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
class student{
public: 
    int rollNo;
    string name;
    float marks;
    
    void input(){
        cout<<"Enter Roll No: ";
        cin>>rollNo;
        
        cout<<"Enter Name: ";
        cin.ignore();
        getline(cin,name);
        
        cout<<"Enter Marks: ";
        cin>>marks;
    }
    
    void display(){
        cout<<endl;
        cout<<"Roll No: "<<rollNo<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Marks: "<<marks<<endl;
        cout<<endl;
    }
};

void addStudent(){
    student s;
    ofstream file("students.txt", ios::app);
    
    if(!file){
        cout<<"Error opening file!\n";
        return;
    }
    
    s.input();
    file<<s.rollNo<<" | "<<s.name<<" | "<<s.marks<<endl;
    
    file.close();
    cout<<"Student Added Successfully\n";
}

void displayStudents(){
    ifstream file("students.txt");
    
    if(!file){
        cout<<"Error opening file!";
        return;
    }
    
    student s;
    cout<<"--All Students--";
    
    while(file>>s.rollNo>>s.name>>s.marks){
        cout<<"-----------------"<<endl;
        s.display();
        
    }
    file.close();
}

void searchStudent(){
    ifstream file("students.txt");
    int searchRollNo;
    bool found = false;
    
    cout<<"Enter Roll No to Search: ";
    cin>>searchRollNo;
    
    student s;
    while(file>>s.rollNo>>s.name>>s.marks){
        if(s.rollNo == searchRollNo){
            cout<<"Student Found!\n";
            s.display();
            found = true;
            break;
        }
    }
    
    if(!found){
        cout<<"Student not Found\n";
    }
    
    file.close();
}

void deleteStudent(){
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    
    int deleteRollNo;
    bool found = false;
    
    cout<<"Enter Roll No to delete: ";
    cin>>deleteRollNo;
    
    student s;
    while(file>>s.rollNo>>s.name>>s.marks){
        if(s.rollNo != deleteRollNo){
            temp<<s.rollNo<<"|"<<s.name<<"|"<<s.marks<<endl;
        }else{
            found = true;
        }
    }
    
    file.close();
    temp.close();
    
    
    
    if(found)
        cout<<"Student Deleted Successfully!\n";
    else
        cout<<"Student Not Found!\n";
}

void updateStudent(){
    ifstream file("students.txt");
    ofstream temp("temp.txt");
    
    int updateRollNo;
    bool found = false;
    
    cout<<"Enter Roll No to update: ";
    cin>>updateRollNo;
    
    student s;
    while(file>>s.rollNo>>s.name>>s.marks){
        if(s.rollNo == updateRollNo){
            cout<<"Enter New Details: ";
            s.input();
            found = true;
        }
        
        temp<<s.rollNo<<"|"<<s.name<<"|"<<s.marks<<endl;
    }
    
    file.close();
    temp.close();
    
    
    
    if(found)
        cout<<"Student Updated Successfully! \n";
    else
        cout<<"Student Not Found! \n";
}

int main(){
    int choice;
    do{
        cout<<"\n-----STUDENT MANAGEMENT SYSTEM-----\n";
        cout<<endl;
        cout<<"1. Add Student\n";
        cout<<"2. Display Students\n";
        cout<<"3. Search Student\n";
        cout<<"4. Delete Student\n";
        cout<<"5. Update Student\n";
        cout<<"6. Exit \n";
        cout<<endl;
        cout<<"Enter Your Choice: ";
        cin>>choice;
        cout<<endl;
        
        switch(choice){
            case 1: addStudent();
               break;
            case 2: displayStudents();
               break;
            case 3: searchStudent();
               break;
            case 4: deleteStudent();
               break;
            case 5: updateStudent();
               break;
            case 6: cout<<"Exiting...\n";
                break;
            default: cout<<"Invalid choice\n";
            
        }
        
    }while(choice != 6);
    
    return 0;
    

}




















