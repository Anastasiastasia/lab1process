// Reporter.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include<iostream>
#include<fstream>
#include "Header.h"
#include <string>
using namespace std;
int main() {
    const char* inputFile = "input.bin";
    const char* outputFile = "output.bin";
    double payRate = 10.0;

    ofstream output(outputFile);
    if (!output.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    output << "Отчет по файлу \"" << inputFile << "\"" << endl;

    ifstream input(inputFile, ios::binary);
    if (!input.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    employee emp;
    while (input.read((char*)&emp, sizeof(employee))) {
        double salary = emp.hours * payRate;
        output << "Employee number: " << emp.num << ", Name: " << emp.name << ", Hours worked: " << emp.hours << ", Salary: " << salary << endl;
    }

    input.close();
    output.close();

    return 0;
}