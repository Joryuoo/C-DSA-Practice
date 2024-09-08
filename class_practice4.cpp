#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

/*
Student Grades System: Design a Student class that stores a student's name, 
roll number, and grades for different subjects. Implement methods to calculate 
the total and average grades and determine if the student has passed or failed.
*/
class Student{
    public: 

        void setName(string str){
            name = str;
        }

        void setRollNumber(int n){
            rollNumber = n;
        }

        void setGrades() {
            cout << "Enter 5 grades for " << name << ": " << endl;
            for (int i = 0; i < 5; i++) {
                cin >> grades[i];
            }
        }

        float getAve(){
            ave = 0.0;
            for(int i = 0; i < 5; i++){
                ave += grades[i];
            }
            ave /= 5.0;
            return ave;
        }

        void displayClassRecord(){
            cout << "\n-----------------------------" << endl;
            cout << "Student name: " << name << endl;
            cout << name << "'s grades: ";
            displayGrades();
            cout << name <<"'s average: " << fixed << setprecision(2) << ave << endl;
            cout << getPassFailStatus() << endl;
            cout << "-----------------------------" << endl;
        }

        
    private:
        string name;
        int rollNumber;
        float ave;
        float grades[5];

    string getPassFailStatus(){
        float average = getAve();
        return average >= 60 ? "Pass" : "Fail";
    }

    void displayGrades(){
        for (int i = 0; i < 5; i++) {
            cout << fixed << setprecision(2) << grades[i] << " ";
        } 
        cout << endl;
    }
};

int main(){
    int size;
    int rollnum;
    string name;
    cout << "Enter the number of students: ";
    cin >> size;

    Student student[size];
    for(int i = 0; i < size; i++){
        
        cin.ignore(); // to ignore newline / enter

        cout << "Enter the name of student " << i+1 << ": ";
        getline(cin, name);
        student[i].setName(name);
        
        cout << "Enter the roll number of student " << i+1 << ": ";
        cin >> rollnum;
        student[i].setRollNumber(rollnum);
        
        cin.ignore();
        student[i].setGrades();
        student[i].getAve();
    }

    for(int i = 0; i < size; i++){
        student[i].displayClassRecord();
    }

    
}