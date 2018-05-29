#include "Student_info.h"
#include "grade.h"

using std::istream; using std::vector;

bool compare(const Student_info& x, const Student_info& y)
{
    return x.name < y.name;
}

bool compare2(const Student_info_mod& x, const Student_info_mod& y)
{
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s)
{
    //read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);
    return is;
}

istream& read(istream& is, Student_info_mod& s)
{
    double midterm;
    double final;
    is >> s.name >> midterm >> final;
    vector<double> homework;
    read_hw(is, homework);
    if(homework.size() != 0){
        s.final_grade = grade(midterm, final, homework);
    }
    return is;
}

//reads homework grades from input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw){
    
    if(in){
        //get rid of previous content
        hw.clear();

        //read homework grades
        double x;
        while(in >> x){
            hw.push_back(x);
        }
        //clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}


