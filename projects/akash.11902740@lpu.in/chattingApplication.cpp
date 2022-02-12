#include <bits/stdc++.h>
using namespace std;

void initPage();
void bodyPage(string);
map<string, string> user;

class dosth
{
    vector<string> friend_list;
    struct basic
    {
        int id;
        string s, r;
        char message[55][105];
        int message_count = 0;
    };

public:
    map<string, basic> sms;
    void inbox(string);
    void display(string);
    void addfriend(string);
};

// DM functionality
void dosth::DM(string name)
{
    cout << "view your DM Messages:\n\n";
    for (int i = 0; i <= sms[name].message_count; i++)
    {
        puts(sms[name].message[i]);
        cout << endl;
    }
}

// display FriendList
void dosth::display()
{
    int c = 0;
    vector<string>::iterator i;
    i = friend_list.begin();
    cout << " Your Friends are:" << endl;
    for (; i != friend_list.end(); i++)
    {
        cout << "\n"
             << *i << endl;
        c++;
    }

    cout << "\nTotal friends: " << c;
}

// Add friend
void dosth::addfriend(string username)
{
    vector<string>::iterator it;
    map<string, string>::iterator myuser;
    int x = 0, flag = 0, y = 0;

    string addname;
    cout << "\nEnter the name friend name: " << endl;
    cin >> addname;

    for (myuser = user.begin(); myuser != user.end(); myuser++)
    {
        for (it = friend_list.begin(); it != friend_list.end(); it++)
        {
            if (*it == addname)
                y++;
        }
        if (addname == username)
        {

            x++;
            break;
        }

        else if (myuser->first == addname)
            flag++;
    }
    if (flag == 1 && x == 0 && y == 0)
    {
        friend_list.push_back(addname);
        cout << "\n"
             << addname << "added to your friend list\n"
             << endl;
    }
    else if (x == 0 && flag == 0)
    {
        cout << "\nSorry!!! not found!\n";
    }
    else if (y)
    {
        cout << "\n"
             << addname << " already your friend\n";
    }
}

void initPage()
{

    int flag = 0;
    int choice;

    cout << " Akash Chat-Console " << endl;

    while (true)
    {
        cout << "Please enter choice: " << endl;
        cout << "\n  1-Sign_up\n  2-Sign_in" endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string uname, upwd;
            cout << "Enter your fav username: ";
            cin >> uname;
            cout << "Enter your secret password: ";
            cin >> upwd;

            map<string, string>::iterator it;
            if (user.empty())
            {
                user[uname] = upwd;
            }
            else
            {
                // this is to check whether 2nd user dont have same username!!!
                for (it = user.begin(); it != user.end(); ++it)
                {
                    if (it->first == uname)
                    {
                        cout << "Username Undertaken ... Try another combination." << endl;
                        break;
                    }
                    else
                    {
                        user[uname] = upwd;
                        break;
                    }
                }
            }
            break;
        }

        case 2:
        {
            string loginname, loginpwd;
            cout << "Enter your username: " << endl;
            cin >> loginname;
            cout << "Enter your password: " << endl;
            cin >> loginpwd;

            map<string, string>::iterator it;
            for (it = user.begin(); it != user; it++)
            {
                if (it->first == loginname && it->second == loginpwd)
                {
                    cout << "Nice login Success!" << endl;
                    flag = 1;
                    bodyPage(loginname);
                    break;
                }
            }
            if (flag == 0)
            {
                cout << "Invalid username or password" << endl;
                break;
            }
            break;
        }
        }
    }
}

map<string, dosth> friend;
void bodyPage(string username)
{

    int choice3, choice2;
    cout << "chosse from following options: " << endl;
    cout << "\n1-Inbox\n2-Friend_list\n3-Add friend\n4-Unfriend\n5-Log out\n";
    cin >> choice2;

    switch (choice2)
    {
    case 1:
    {

        friend[username].inbox(username);
        break;
    }
    case 2:
    {
        friend[username].display();
        break;
    }
    case 3:
    {
        friend[username].addfriend(username);
        break;
    }
    case 4:
    {
        cout << "Log out Success!" << endl;
        initPage();
        break;
    }
    }
}

int main()
{
    initPage();
    return 0;
}