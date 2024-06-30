#ifndef _USERS_H_
#define _USERS_H_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <cassert>
#include <sstream>

using namespace std;

struct user {
    int user_id;
    string user_name;
    string password;
    string email;
    int Is_anonymmous;

    vector<int> Q_ids_askedByUser; // This vector contains each question that is asked by a certain user
    map<int, vector<int>> Q_thread_askedByUser; // This map holds each thread "replies to certain question"

    // Constructors
    user();
    user(string line);

    // Methods
    string Tostring();
    void Print();
};

#endif // _USERS_H_
