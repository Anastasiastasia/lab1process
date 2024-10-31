#include <iostream>
#include<fstream>
#include <windows.h>
#include<string>

//#include"Header.h"
using namespace std;
struct employee {
    int num;
    char  name;
    double hours;
};
int main() {
   
    const char* filename = "lab1.exe";
    int numRecords = 10;
    //double r = 5.0;
    STARTUPINFO siCreator;
    PROCESS_INFORMATION piCreator;
    ZeroMemory(&siCreator, sizeof(siCreator));
    ZeroMemory(&piCreator, sizeof(piCreator));
    string creatorCmd = "Creator.exe " + string(filename) + " " + to_string(numRecords);
    LPWSTR cmdLine = LPWSTR(creatorCmd.data());
    CreateProcess(NULL, cmdLine, NULL, NULL, FALSE, 0, NULL, NULL, &siCreator, &piCreator);
    WaitForSingleObject(piCreator.hProcess, INFINITE);

    ifstream input(filename, ios::binary);
    if (!input.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }
    employee emp;
    while (input.read((char*)&emp, sizeof(employee))) {
        cout << "Employee number: " << emp.num << endl;
        cout << "Employee name: " << emp.name << endl;
        cout << "Hours worked: " << emp.hours << endl;
    }

    input.close();

    string reportFile;
    double payRate;
    cout << "Enter report file name: ";
    cin >> reportFile;
    cout << "Enter pay rate per hour: ";
    cin >> payRate;

    STARTUPINFO siReporter;
    PROCESS_INFORMATION piReporter;
    ZeroMemory(&siReporter, sizeof(siReporter));
    ZeroMemory(&piReporter, sizeof(piReporter));

    string reporterCmd = "Reporter.exe " + string(filename) + " " + reportFile + " " + to_string(payRate);
    CreateProcess(NULL, (LPWSTR)reporterCmd.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &siReporter, &piReporter);
    WaitForSingleObject(piReporter.hProcess, INFINITE);

    cout << "Report generated successfully." << endl;

    return 0;
}
