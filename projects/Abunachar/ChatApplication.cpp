#include<bits/stdc++.h>
#include "UserDatabase.cpp"

using namespace std;



class ChatApplication{
    UserDatabase userDatabase;
    User activeUser;
 
    void login(){
        cout << "\n\n--- LOGIN ---" <<endl;

        string username,password;
        cout << "Username > ";
        cin >> username;
        if(userDatabase.checkUsernameAvailable(username)){
           cout << "Username not found" << endl;
           login();
           return;
        }
        
        int chance = 3;
        while(chance--){
            cout << "Password > ";
            cin >> password;
            
            if(userDatabase.validateLogin(username,password)){
                cout << "Successfully Logged In" << endl;
                this->activeUser = userDatabase.getAccount(username);
                return;
                
            } else {
                cout << "!Invalid password" << endl;
            }
        }
        cout << "3 Wrong Attempt" << endl;
    }

    void signUp(){
        cout << "\n\n--- SIGNUP ---" <<endl;
        string username, name, email, password;
        cout << "Username > ";
        cin >> username;
        if(userDatabase.checkUsernameAvailable(username)){
            cout << "Name > ";
            cin >> name ;
            cout << "Email > ";
            cin >> email;
            cout << "Password > ";
            cin >> password;

            User user = User(name,email,username,password);
            userDatabase.addUser(user);
            cout << "Successfully Accout created, Redirecting to Login";
            this->login();
        } else {
            signUp();
            return;
        }
    }
    

    public:
    void loginSignup(){
        char userInput;
        cout << "[ L ]ogin   [ S ]ignUp" << endl;
        cout << ">> ";
        cin >> userInput;
        if(userInput == 'l' || userInput == 'L'){
            this->login();
        } else if (userInput == 's' || userInput == 'S'){
            this->signUp();
        } else {
            cout << "Invalid Input" << endl;
        }
    }

};

int main(){
    
    ChatApplication chatApp;
    string userInput;
    cout << "---- WELCOME ----" <<endl;
    chatApp.loginSignup();

    return 0;
}




