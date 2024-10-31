#include "pch.h"
#include "gtest/gtest.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <memory>

bool fileExists(const std::string& filename) {
    std::ifstream file(filename.c_str());
    return file.good();
}

TEST(EmployeeManagement, TestFileCreation) {
    const char* filename = "lab1.exe";
    int numRecords = 10;

    std::string creatorCmd = "Creator.exe " + std::string(filename) + " " + std::to_string(numRecords);
    system(creatorCmd.c_str());

    ASSERT_TRUE(fileExists(filename));
}

TEST(EmployeeManagement, TestReportGeneration) {
    const char* filename = "lab1.exe";
    std::string reportFile = "report.txt";
    double payRate = 10.0;

    std::string reporterCmd = "Reporter.exe " + std::string(filename) + " " + reportFile + " " + std::to_string(payRate);
    system(reporterCmd.c_str());

    ASSERT_TRUE(fileExists(reportFile));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}