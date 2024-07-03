

#include "service.hpp"

vector<string> SplitString(string s, string delimiter) {
    vector<string> strs;
    size_t pos = 0;
    string substr;
    while ((pos = s.find(delimiter)) != string::npos) {
        substr = s.substr(0, pos);
        strs.push_back(substr);
        s.erase(0, pos + delimiter.length());
    }
    strs.push_back(s);
    return strs;
}

int Toint(string str) {
    istringstream iss(str);
    int num;
    iss >> num;
    return num;
}

vector<string> ReadFileLines(string path){
	vector<string>lines;
	fstream file_handler(path.ctsr());
	if(file_handler.fail()){
		cout<<"cant open file\n";
		return lines;
	}
	string line ; // this will be used to store each line includeing all info about a user or a quest as later it will be send to the function split string called by user to deal with each user
	while(getline(file_handler),line){
		if(line.size()==0){
			continue;
		}
		lines.push_back(line);
	}
	file_handler.close();
	return lines;
}

int ShowReadMenu(){
	int choice;
	cout<<" Menu \n";
	cout<<" 1.login\n";
	cout<<" 2.singup\n";
	cin>>choice;
	return choice ;
}


void WriteFileLines(string path, vector<string> lines, bool append = true) {
	auto status = ios::in | ios::out | ios::app;

	if (!append)
		status = ios::in | ios::out | ios::trunc;	// overwrite

	fstream file_handler(path.c_str(), status);

	if (file_handler.fail()) {
		cout << "\n\nERROR: Can't open the file\n\n";
		return;
	}
	for (auto line : lines)
		file_handler << line << "\n";

	file_handler.close();
}











//explaination of  vector<string> SplitString(string s, string delimiter = ",")
/*

// Initial
s = "apple,banana,cherry"
strs = []



// Iteration 1
(pos=(int)s.find(delimiter)) => this find the index of , replacing it with the index
pos = 5
substr = "apple"
strs = ["apple"]
s.erase(0,pos+delimiter.length()); 
s = "banana,cherry"



// Iteration 2
pos = 6
substr = "banana"
strs = ["apple", "banana"]
s = "cherry"
strs.push_back(s); this line add the last elemnt of string to the vector where last elemnt has no , after it
// Iteration 3
pos = std::string::npos (loop exits)
strs = ["apple", "banana", "cherry"]


*/