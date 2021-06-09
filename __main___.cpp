#include"login.h"
#include"registration.h"
#include<string> 
string reges_login(){
	string result ;
	cout<<"Regestration/Login : ";
	cin>>result;
	return result; 

}

bool in_list(string array[],string word,int length){
        bool result ;
	string alpha = word;
        for (int i=0 ; i <= length ; i++){
                if(array[i] == alpha){
                        result = true;
                        break;
                }
                else {
                        result = false;
                }

        }
        return result;
}

int main(){
	string logins1[]= {"login","Login","l","L","log"};
	string regestrations1[] = {"regestration","reges","r","Regestration","R","reg"}; 
	string word = reges_login(); 
	int length =( sizeof(logins1)/sizeof(logins1[0])-1);
	int length1 = (sizeof(regestrations1)/sizeof(regestrations1[0])-1);
	if(in_list(logins1,word,length)){
		if(verbose()){
			cout<<"Logged in\n";
		}
		else{
			cout<<"Sorry invalid password or username\n\n";
			main();
		}

	}
	else if(in_list(regestrations1,word,length1)){
		verbose_regestration();
	}



	
	
}
