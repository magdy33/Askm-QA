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



userManger::userManger(){
	last_id = 0;
}


void userManger::LoadDatabase(){
		last_id=0;
		username_userobject_map.clear(); //clearing the map each database loading
		
		vector<string>lines = ReadFileLines(user.txt); // call the database file to read each line sepratly
		for(auto &line:lines){ // loop on each line 
			user eachUser(line); // parse each element to its field
			username_userobject_map[eachUser.user_name]=eachUser; // put each user now in its place in the map
			last_id = max(last_id,eachUser.user_id);
		}
	}

void userManger::AccessSystem(){
	int choice  = ShowReadMenu();
	switch choice{
		case : 1
		{
			LogIn();
			break;
		}
		case : 2
		{
			SingUp();
			break;
		}
	}
}

void userManger::Login(){
	LoadDatabase();
	
	while(true){
		cout<<"Enter user name and Password:\n";
		cin >>current_user.user_name>>current_user.user_password; // current_user was created at the first of the class
		
		if(!username_userobject_map.count(current_user.user_name)){
			cout<<"invalid username or password\n";
			continue;
		}
		user user_exist = username_userobject_map[current_user.user_name];
		if(current_user.user_password!=user_exist.password){
			cout<<"invalid user name or password\n";
			continue;
		}
		current_user = user_exist ;
		break;
	}
}


void userManger::SignUp(){
	while(true){
		cout << "Enter user name, do not use spaces\n";
		cin  >> current_user.user_name;
		if(username_userobject_map.count(current_user.user_name)){
			cout << "user name is already exist\n";
		}
		else{
			break;
		}
	}
	cout << "Enter name: ";
	cin >> current_user.name;
	
	cout <<"enter a pasword\n";
	cin  >>current_user.user_password;
	
	cout << "Enter email: ";
	cin >> current_user.email;
	
	cout << "Allow anonymous questions? (0 or 1): ";
	cin >> current_user.Is_anonymmous;
	
	current_user.user_id = ++last_id;
	username_userobject_map[current_user.user_name]= current_user;
	
	UpdateDatabase(current_user);
}

void userManger::ListUsersNamesIds(){
	for(auto &pair : username_userobject_map){
		cout << "ID: "<<pair.second.user_id << "\t\tName: " << pair.second.name << "\n";
	}
}

pair<int, int> userManger::ReadUserId(){
	int user_id;
	cout << "Enter User id or -1 to cancel: ";
	cin >> user_id;
	if (user_id == -1){
		return make_pair(-1, -1);
	}

	for (auto &pair : userame_userobject_map) {
		if (pair.second.user_id == user_id){
			return make_pair(user_id, pair.second.Is_anonymmous);
		}
	}
	cout << "Invalid User ID. Try again\n";
	return ReadUserId();
}

void userManger::UpdateDatabase(User &eachUser){
	string line = eachUser.ToString();
	vector<string> lines(1, line);
	WriteFileLines("users.txt", lines);
}
