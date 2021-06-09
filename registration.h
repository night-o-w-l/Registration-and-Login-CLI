#include<iostream> 
#include<vector> 
#include<string> 
#include<fstream> 

using std::cout; 
using std::cin; 
using std::endl; 
using std::vector; 
using std::ofstream;
using std::string ; 
using std::ifstream;


bool checking_username(string username){
	ifstream file_0("username_data.txt");
	vector<string> username_list; 
	while(file_0){
		string name;
		getline(file_0,name);
		if (name == ""){
		}
		else {
			username_list.push_back(name);
		}
	}
	bool sit ;
	
	for(string namess:username_list){

		if(namess == username){
			sit = true;
			break; 
		}
		else {
			sit = false; 
			
		}
	}
	return sit ;
}

string verbose_user(){
	string username;
	while(true){
		cout<<"Username : "; 
		cin>>username; 
		if (checking_username(username)){
			system("clear");
			cout<<"\033[31mUsername already exist\n\033[0m";
		}
		else {
			break; 
		}
	}
	return username; 

}
string verbose_password(){
	string password; 
	while(true){
		cout<<"Password : "; 
		cin>>password;
		int length = password.size();
		if(length < 8){
			system("clear");
			cout<<"\033[31mPassword should be atleast 8 char\n\033[0m";
		}
		else if(length >= 8){
			string conf;
			cout<<"Confirm Pass : ";
			cin>>conf; 
			if (conf != password){
				system("clear");
			}
			else if (conf == password){
				break;
			}
		}
	}
	system("clear");
	return password;
}

void username_1(string name_1){
	ofstream file_1("username_data.txt",std::ios::app);
	string name_updt_2 = name_1 + "\n";
	file_1<<name_updt_2;
}
void password_1(string password_1){
	ofstream file_2("password_data.txt",std::ios::app);
	string password_updt_2 = password_1 + "\n";
	file_2<<password_updt_2;
}

void verbose_regestration(){
	string name = verbose_user(); 
	string pass = verbose_password(); 
	username_1(name); 
	password_1(pass);
}


