

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