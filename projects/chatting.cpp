#include <bits/stdc++.h>
using namespace std;

vector<string> userList;
vector<string> feed;
vector<string> mymessages;


void newUser()
{
    cout<<" Enter Email: ";
    string email;
    cin>> email;
    userList.push_back(email);

    cout<<" Enter Name: ";
    string name;
    cin>> name;
    userList.push_back(name);

    cout<<" Enter UserName: ";
    string UserName;
    cin>> UserName;
    userList.push_back(UserName);
    
    cout<<" Enter Password: ";
    string Password;
    cin>> Password;
    userList.push_back(Password);
    cout<<endl<<"User created  "<<endl<<endl;
}

bool userFound(string UserName, string Password)
{
    for(int i=0;i<userList.size();i++)
    {
        if(userList[i] == UserName)
        {
            for(int i=0;i<userList.size();i++)
            {
                if(userList[i]==Password) return true;
            }
        }
    }
    return false;
}

void loginLogout()
{
    cout<<" Enter UserName: ";
    string UserName;
    cin>> UserName;
    //userList.push_back(UserName);
    
    cout<<" Enter Password: ";
    string Password;
    cin>> Password;
    //userList.push_back(Password);
    cout<<endl;
    if(userFound(UserName, Password))
    cout<<endl<<"User logged in"<<endl<<endl;
    else
    cout<<endl<<"User Not Found"<<endl<<endl;


}



void followUnfollow()
{
    
}

void addBroadCast()
{
    cout<<"Enter Your Message: ";
    string str;
    cin>>str;
    feed.push_back(str);
    cout<<"Send to Feed \n\n";

}

void addMyMessages()
{
    cout<<"Enter Your Message: ";
    string str;
    cin>>str;
    mymessages.push_back(str);
    cout<<"Saved to Personal \n\n";
}

void sendMessage()
{
    cout<<"1. BroadCast \n2. Presonal \n\n";
    int x;
    cin>>x;
    if(x==1) addBroadCast();
    else if(x==2) addMyMessages();
    else cout<<"Invalid Input\n\n";
}

void seeMyMsgs()
{
    if(mymessages.size()==0) 
    {
        cout<<"Nothing to show \n\n";
        return;
    }
    for(int i=0;i<mymessages.size();i++)
    {
        cout<<mymessages[i]<<endl;
    }
}

void seeMyFeed()
{
    if(feed.size()==0) 
    {
        cout<<"Nothing to show \n\n";
        return;
    }

    if(feed.size()==0) cout<<"Nothing to show \n\n";
    for(int i=0;i<feed.size();i++)
    {
        cout<<feed[i]<<endl;
    }
}



int main()
{

    cout<<"WELCOME TO CHATTING APPLICATION enter yout input\n\n\n";

    while(true)
    {
        cout<<" 1. Create new user \n 2. Login/Logout  \n 3. Send message (Personal, Broadcast) \n 4. See my messages \n 5. See my feed \n";

        int input;
        cin>>input;

        switch(input) {
      case 1 :
         newUser(); 
         break;
      case 2 :
        loginLogout(); 
         break;
      case 3 :
         sendMessage();
         break;
      case 4 :
         seeMyMsgs();
         break;
      case 5 :
         seeMyFeed();
         break;
      default :
         cout << "Invalid input" << endl;
   }
    }



    return 0;
}