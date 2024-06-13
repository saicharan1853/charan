#include "ass2.h"
#include <iostream>
Course::Course(string code, string Title, string instructor, int credits)
{
     this->code = code;
     this->credits = credits;
     this->Title = Title;
     this->instructor = instructor;
     cout << "Inside base class Course() constructor " << endl;
}
string Course::get_code()
{
     return code;
}
void Course::displayDetails(){}
char Course::calculateGrade(int ){}
int Course::get_credits()
{
     return credits;
}
string Course::get_title()
{
     return Title;
}
string Course::get_instructor()
{
     return instructor;
}



LectureCourse::LectureCourse(string code = "", string Title = "", string instructor = "", int credits = 0) : Course(code, Title, instructor, credits)
{
     cout << "Inside derived  class LectureCourse() constructor " << endl;
}
void LectureCourse ::displayDetails()
{
     cout << "Display details of Leture Coure" << endl;
     cout << "Course Code : " << get_code() << endl;
     cout << "Course title : " << get_title() << endl;
     cout << "Course Instructor : " << get_instructor() << endl;
     cout << "Course Credits : " << get_credits() << endl;
     cout << " It is Lecture course " << endl;
     return;
}
char LectureCourse::calculateGrade(int marks)
{
     // some calculation for logic of grade

     if (marks > 80)
          return 'A';
     else if (marks > 70 && marks < 80)
          return 'B';
     else if (marks > 60 && marks < 70)
          return 'C';
     else if (marks > 50 && marks < 60)
          return 'D';
     else
          return 'F';
}


LabCourse::LabCourse(string code, string Title, string instructor, int credits) : Course(code, Title, instructor, credits)
{
     cout << "Inside derived  class LabCourse() constructor " << endl;
}
void LabCourse::displayDetails()
{

     cout << "Display details of Lab Coure" << endl;
     cout << "Course Code : " << get_code() << endl;
     cout << "Course title : " << get_title() << endl;
     cout << "Course Instructor : " << get_instructor() << endl;
     cout << "Course Credits : " << get_credits() << endl;
}
char LabCourse::calculateGrade(int marks)
{
     // some calculation for logic of grade
     if (marks > 90)
          return 'A';
     else if (marks > 75 && marks < 90)
          return 'B';
     else if (marks > 60 && marks < 75)
          return 'C';
     else if (marks > 40 && marks < 60)
          return 'D';
     else
          return 'F';
}


SeminarCourse::SeminarCourse(string code, string Title, string instructor, int credits) : Course(code, Title, instructor, credits)
{
     cout << "Inside derived  class SeminarCourse() constructor " << endl;
}
void SeminarCourse::displayDetails()
{
     cout << "Display details of seminar Coure" << endl;
     cout << "Course Code : " << get_code() << endl;
     cout << "Course title : " << get_title() << endl;
     cout << "Course Instructor : " << get_instructor() << endl;
     cout << "Course Credits : " << get_credits() << endl;
}
char SeminarCourse::calculateGrade(int marks)
{
     // some calculation for logic of grade
     if (marks > 70)
          return 'A';
     else if (marks > 60 && marks < 70)
          return 'B';
     else if (marks > 50 && marks < 60)
          return 'C';
     else if (marks > 40 && marks < 50)
          return 'D';
     else
          return 'F';
}


Student::Student(int attendance, string name, int marks)
{

     this->attendance = attendance;
     this->name = name;
     this->marks = marks;
}

int Student::get_attendance()
{
     return attendance;
}
string Student::get_name()
{
     return name;
}
int Student::get_marks()
{
     return marks;
}
void Student::set_grade(char grade)
{
     this->grade = grade;
}
char Student::get_grade()
{
     return grade;
}



CourseManager::CourseManager()
{
     cout << "\nInside Course Mnager class ()" << endl;
}
void CourseManager::add_course(Course obj)
{
     Courseslist.push_back(&obj);
}
void CourseManager::add_student(Student obj)
{
     Studentslist.push_back(&obj);
}
void CourseManager::display_courses()
{
      cout<<"The Courses present in the Course Manager  : "<<endl;
     int size = Courseslist.size();
     for (int i = 0; i < size; i++)
     {
          cout << "course code: "<< (*Courseslist[i]).get_code() << "  course name : " << (*Courseslist[i]).get_title() << "  course credits : " << (*Courseslist[i]).get_credits() << endl;
     }
}
void CourseManager::remove_course(string code)
{
     int index = 0;
     int size = Courseslist.size();
     int find = 0;
     while (!find && index < size)
     {
          if ((*Courseslist[index]).get_code() == code)
          {
               find = 1;
          }
          else
          {
               index++;
          }
     }
     if (find == 0)
     {
          cout << "The course is not available in this course manager " << endl;
     }
     else
     {
          Courseslist.erase(Courseslist.begin() + index, Courseslist.begin() + index + 1);
          cout << "course deleted successfully\n" << endl;
     }
     return;
}
void CourseManager::display_students()
{
    cout<<"The student present in the Course Manager  : "<<endl;
     int size = Studentslist.size();
     for (int i = 0; i < size; i++)
     {
          cout << "Name : " << (*Studentslist[i]).get_name() << "  attendance : " << (*Studentslist[i]).get_attendance() <<"days"<< endl;
     }
     return;
}
void CourseManager::calculate_grade_for_all_students()
{
     int students_size=Studentslist.size();
     int courses=Courseslist.size();
     for(int i=0;i<students_size;i++)
     {
         int marks=(*Studentslist[i]).get_marks() ;
        char ch;
         if (marks > 80)
          ch='A';
        else if (marks > 70 && marks < 80)
          ch='B';
        else if (marks > 60 && marks < 70)
           ch='C';
         else if (marks > 50 && marks < 60)
           ch='D';
         else
            ch= 'F';

        
        (*Studentslist[i]).set_grade(ch);

     }
     return;
}
void CourseManager::display_grade_of_all_students()
{

     int size = Studentslist.size();
     for (int i = 0; i < size; i++)
     {
          cout << "Name: " << (*Studentslist[i]).get_name() << "  grade : " << (*Studentslist[i]).get_grade() << endl;
     }
}