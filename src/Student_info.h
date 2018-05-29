#ifndef GUARD_Student_info
#define GUARD_Student_info

// Student_info.h header file
#include<iostream>
#include<string>
#include<vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

struct Student_info_mod {
    std::string name;
    double final_grade;
};


bool compare(const Student_info&, const Student_info&);
bool compare2(const Student_info_mod&, const Student_info_mod&);

std::istream& read(std::istream&, Student_info_mod&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);

#endif


