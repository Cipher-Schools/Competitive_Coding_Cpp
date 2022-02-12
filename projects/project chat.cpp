#include<iostream>
#include<vector>
#include<map>
#include<string>

using namespace std;

class User{
	string  Email,Name,UserName,Password;
	map<string,string> map_username;
		void login(){
			string username,password;
			cin>>username;
			cout<<endl<<"Password ->";
			cin>>password;
			if(map_username.find(username)==map_username.end()){
				system("clear");
				cout<<"Wrong User Name"<<endl;
				login();
			}
			else{
				if(map_username[username]==password){
					cout<<"Login successful";
					//chat();
				}
				else{
						system("clear");
				cout<<"Wrong password"<<endl;
				login();
				
				}
			}
			return ;
			
		}
		void checkUserName(string username,string password){
			if(map_username.find(username)==map_username.end()){
				this->UserName=username;
				map_username[username]=password;
				cout<<"account Created/n Now Login";
				system("clear");
				login();
			}
			else{
				cout<<"Re-enter User Name duplicate"<<endl;
				cin>>username;
				checkUserName(username,password);
			}
			return;
		}
		void setDetails(string email,string name,string username,string password){
			this->Name=name;
			this->Email=email;
			this->Password=password;
			checkUserName(username,password);
			return;
		}
		void register(){
			string email,name,username,password;
			cout<<"Email-> ";
			cin>>email;
			cout<<endl<<"Name-> ";
			cin>>name;
			cout<<endl<<"User Name-> ";
			cin>>username;
			cout<<endl<<"Password ->";
			cin>>password;
			cout<<"Enter 1 to submit"<<endl;
			cout<<"Enter 2 to Re-enter Details/nEnter * for exit";
			char ch;
			cin>>ch;
			switch(ch){
				case '1':
					setDetails(email,name,username,password);
					break;
				case '2':
					system("clear");
					register();
					break;
				case '*':
					return;
					break;
				default:
					system("clear");
					cout<<"You didnt enter anything";
					register();
			}
			return;
		}
		public:
		void main_fun(){
			cout<<"Enter 1 to register"<<endl;
			cout<<"Enter 2 to login"<<endl;
			cout<<"Enter * to exit"<<endl;
			char ch;
			cout<<"Enter your choise :";
			cin>>ch;
			switch(ch){
				case '1':
					register();
					break;
				case '2':
					login();
					break;
				case '*':
					return;
				default:
					system("clear");
					cout<<"You didnt choose anything"<<endl;
					main_fun();
					
			}
			return;
		}
};
void main(){
	User u1;
	u1.main_fun();
	return ;}

