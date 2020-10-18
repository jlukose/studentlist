#include<iostream>
#include<string>

using namespace std;

struct student{
  char firstname[10];
  char lastname[10];
  int id;
  float gpa;
};

std::string input;
string str;

void studentdelete(int a);

void studentadd();

void studentprint();

int main(){
  cout << "Welcome to student list, please type 'ADD' to add a student, 'PRINT' to print all students stored, 'DELETE' to delete a student, and 'QUIT' to quit." << endl;
  while(true){
    cin >> input;
    str = "QUIT";
    std::size_t found = input.find(str);
    if (found != std::string::npos){
      cout << "Quitting..." << endl;
      return 0;
    }
    str = "ADD";
    found = input.find(str);
    if (found != std::string::npos){
      studentadd();
    }
    str = "PRINT";
    found = input.find(str);
    if (found != std::string::npos){
      studentprint();
    }
    str = "DELETE";
    found = input.find(str);
    if (found != std::string::npos){
      cout << "Please enter the Student ID that you wish to delete" << endl;
      int deletenumber;
      cin >> deletenumber;
      studentdelete(deletenumber);
    }
  }
}

void studentadd(){

}

void studentprint(){

}

void studentdelete(int a){
  
}
