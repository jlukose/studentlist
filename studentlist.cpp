//StudentList by Joshua Lukose October 2020 - User enters student name, id, and gpa into a list that can be printed and specific ids can be removed. 
#include<iostream>
#include<cstring>
#include<vector>
#include<iterator>
#include<iomanip>

using namespace std;

struct S{
  char firstname[10];
  char lastname[10];
  int id;
  float gpa;
};

//initialization of variables and methods
char input[6];
void studentdelete(vector<S*>* StudentList, int deleteid);
S* studentadd();
void studentprint(vector<S*> StudentList);

int main(){//main
  cout << "Welcome to student list, please type 'ADD' to add a student, 'PRINT' to print all students stored, 'DELETE' to delete a student, and 'QUIT' to quit." << endl;
  S List;
  vector<S*> StudentList;
  while(true){//main loop, detects commands
    cout << "Command list: ADD  PRINT  DELETE  QUIT" << endl;
    for (int i = 0; i < 7; i++){
      input[i] = '\0';
    }
    cin >> input;
    if (strcmp(input, "QUIT") == 0){//Quit and exit the code
      return 0;
    }
    if (strcmp(input, "ADD") == 0){//Add new student to list
      StudentList.push_back(studentadd());
    }
    if (strcmp(input, "PRINT") == 0){//Print current students
      studentprint(StudentList);
    }
    if (strcmp(input, "DELETE") == 0){//Delete by id
      cout << "Please enter the Student ID that you wish to delete" << endl;
      int deleteid;
      cin >> deleteid;
      studentdelete(&StudentList, deleteid);
    }
    cin.clear();
    cin.ignore(10000000, '\n');
  }
}

S* studentadd(){//Adds a student and asks first and last name, id, gpa
  S* newstudent = new S();
  cout << "Enter first name" << endl;
  cin >> newstudent->firstname;
  cin.clear();
  cin.ignore(10000000, '\n');
  cout << "Enter last name" << endl;
  cin >> newstudent->lastname;
  cin.clear();
  cin.ignore(10000000, '\n');
  cout << "Enter ID" << endl;
  cin >> newstudent->id;
  cin.clear();
  cin.ignore(10000000, '\n');
  cout << "Enter GPA" << endl;
  cin >> newstudent->gpa;
  return newstudent;
}

void studentprint(vector<S*> StudentList){//Prints students with iterator
  vector<S*>::iterator ptr;
  for (ptr = StudentList.begin(); ptr < StudentList.end(); ptr++){
    cout << (*ptr)->firstname << " " << (*ptr)->lastname << ", " << (*ptr)->id << setprecision(3) << ", " << (*ptr)->gpa << endl;
  }
}

void studentdelete(vector<S*>* StudentList, int deleteid){//Checks all students with iterator and deletes relevent id
  vector<S*>::iterator ptr;
  for (ptr = StudentList->begin(); ptr < StudentList->end(); ptr++){
    if ((*ptr)->id == deleteid){
      delete *ptr;
      StudentList->erase(ptr);
    }
  }
  return;
}
