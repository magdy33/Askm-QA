#include "../inc/Users.hpp"
#include "service.hpp"

user::user() {
    user_id = Is_anonymmous = -1;
}

user::user(string line) {
    vector<string> substr = SplitString(line);
    assert(substr.size() == 5);

    user_id = Toint(substr[0]);
    user_name = substr[1];
    password = substr[2];
    email = substr[3];
    Is_anonymmous = Toint(substr[4]);
}

string user::Tostring() {
    ostringstream oss;
    oss << user_id << "," << user_name << "," << password << "," << email << "," << Is_anonymmous;
    return oss.str();
}

void user::Print() {
    cout << "User " << user_id << ", " << user_name << ", " << password << ", " << email << "\n";
}
