#include<bits/stdc++.h>
using namespace std;
class User
{
    string username, name, email, password;
    int userId;

    public:
        User(){
        }

        User(
                string name,
                string email,
                string username,
                string password
            ){
            this->name = name;
            this->username = username;
            this->email = email;
            this-> password = password;
        }
        
        string getName(){
            return this->name;
        }

        string getEmail(){
            return this->email;
        }

        string getUsername(){
            return this->username;
        }

        string getPassword(){
            return this->password;
        }
        
        int getUserId(){
            return this->userId;
        }
        void setUserId(int userId){
            this->userId = userId;
        }

};
