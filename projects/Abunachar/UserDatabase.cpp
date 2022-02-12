#include<bits/stdc++.h>
#include "User.cpp"
using namespace std;


class UserDatabase{
    map<string,User> Users;
    int UserId = 101;
    

    public:
        bool validateLogin(string username, string password){
            User user = this->Users[username];
            return user.getPassword() == password;
        }

        bool checkUsernameAvailable(string username){
           return this->Users.find(username) == Users.end(); 
        }

        void addUser(User user){
            if(checkUsernameAvailable(user.getUsername())){
                user.setUserId(this->UserId++);
                Users[user.getUsername()] = user;
            }else{
                cout << "Username already taken" << endl;
            }
        }

        User getAccount(string username){
           return this->Users[username]; 
        }
    
};



