#ifndef ass2_h
#define ass2_h
#include <iostream>
#include <vector>

using namespace std;
class Course
{
    string code;
    string Title;
    string instructor;
    int credits;
  

public:
    Course(string, string, string, int);
    virtual void displayDetails() ;
    virtual char calculateGrade(int);
    string get_title();
    string get_instructor();
    int get_credits();
    string get_code();
};
class LectureCourse : public Course
{
public:
    LectureCourse(string, string, string, int);
    void displayDetails() ;
      char calculateGrade(int);

};

class LabCourse : public Course
{
public:
    LabCourse(string, string, string, int);
    void displayDetails();
    char calculateGrade(int);
};
class SeminarCourse : public Course
{
public:
    SeminarCourse(string, string, string, int);
    void displayDetails() ;
     char calculateGrade(int);
};
class Student
{
private:
    int attendance;
    string name;
    int marks;
    char grade;


public:
    Student(int, string,int);
    int get_attendance();
    string get_name();
    int get_marks();
      void set_grade(char );
     char get_grade();
   
};
class CourseManager
{

private:
    vector<Course*> Courseslist;
    vector<Student*> Studentslist;

public:
    CourseManager();
    void add_course(Course);
    void remove_course(string);
    void display_courses();
    void add_student(Student);
    void display_students();
    void calculate_grade_for_all_students();
    void display_grade_of_all_students();

};
#endif
