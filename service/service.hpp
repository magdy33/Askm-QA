#ifndef _SERVICE_H_
#define _SERVICE_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>


using namespace std;

vector<string> SplitString(string s, string delimiter = ",");
int Toint(string str);
vector<string> ReadFileLines(string path);
int ShowReadMenu();
void WriteFileLines(string path, vector<string> lines, bool append = true);

#endif // _SERVICE_H_
