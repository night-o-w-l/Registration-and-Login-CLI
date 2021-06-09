#include<iostream> 
#include<string> 
#include<vector> 
#include<fstream> 


using std::cout; 
using std::cin ; 
using std::endl; 
using std::string;
using std::vector;
using std::ifstream;
using std::find;
int getindex(vector<string> a , string b){
	int ind ;
	auto it = find(a.begin(), a.end(),b);
	if (it != a.end() ){
        int index = it - a.begin();

        ind = index;}
	else {

	    ind = -1;
	}
	return ind ; 
}

bool user_pass_equal(string username , string password){
	ifstream file("username_data.txt");
	ifstream file1("password_data.txt");
	vector<string> usernames; 
	vector<string> passwords; 
	while(file){
		string user ; 
		getline(file,user); 
		if (user==""){}
		else{
			usernames.push_back(user);
		}
	}
	while(file1){
		string passs;
		getline(file1,passs);
		if (passs==""){

		}
		else {
			passwords.push_back(passs);
		}
	}
	bool trueorfalse;
	int indexofpass = getindex(usernames,username);
	if (indexofpass == -1){
		trueorfalse = false;
	}
	string passwordoftxt;
	passwordoftxt = passwords[indexofpass];
	if (passwordoftxt == password){
		trueorfalse = true;
	}
	else {
		trueorfalse = false; 
	}


	return trueorfalse;
}
bool verbose(){
	string use,pas ;
	cout<<"Username : "; 
	cin>>use; 
	cout<<"Password : ";
	cin>>pas;
	bool b;
	if (use == "" && pas == ""){
		b = false; 
	}
	else {
		b = user_pass_equal(use,pas);
	}

	return b; 
}

