// Creator.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include<iostream>
#include<fstream>
#include"Header.h"
using namespace std;
int main() {
   
    const char* filename = "lab1.exe";
    int numRecords = 10;
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }
    employee emp;
    for (int i = 0; i < numRecords; i++) {
        cout << "Enter employee number: ";
        cin >> emp.num;
        cout << "Enter employee name: ";
        cin >> emp.name;
        cout << "Enter hours worked: ";
        cin >> emp.hours;

        file.write((char*)&emp, sizeof(employee));
    }

    file.close();

    cout << "File created successfully with " << numRecords << " records." << endl;

    return 0;
}

