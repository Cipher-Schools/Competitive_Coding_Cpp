#include <iostream>
#include <string>
#include <vector>
using namespace std;

class user
{
    string username;
    char colorcode;

public:
    user(string name = "", char c = '')
    {
        this->username = name;
        this->colorcode = c;
    }
    string get_username()
    {
        return this->username;
    }
    char get_colorcode()
    {
        return this->colorcode;
    }
    void set_username(string username)
    {
        this->username = username;
    }
    void set_username()
    {
        string name;
        cout << "enter username: ";
        cin >> name;
        this->username = name;
    }
    void set_colorcode(char ch)
    {
        this->colorcode = ch;
    }
    void set_colorcode()
    {
        char ch;
        cout << "enter colorcode: ";
        cin >> ch;
        this->colorcode = ch;
    }
};

class position: public user
{
public:
    char ch;
    int y;
    position(char ch = 0, int y = 0)
    {
        this->ch = ch;
        this->y = y;
    }
};

class chessBoard
{
};

bool isPositionCorrect(string pos)
{

    if (pos.length() == 2 && pos[0] >= 'a' && pos[0] <= 'h' && pos[1] >= '1' && pos[1] <= '8')
    {
        return true;
    }
    return false;
}

int main()
{
    string tempname;
    char c;
    cout << "enter details of user1: ";
    user user1, user2;
    user1.set_username();
    user1.set_colorcode();
    cout << "enter details of user2: ";
    user2.set_username();
    user2.set_colorcode();
    // position user1pos, user2pos;
    cout << "enter the position of user1: ";
    // cin>>user1pos
    string pos1, pos2;
    cin >> pos1;
    
    while (!isPositionCorrect(pos1))
    {
        cout<<"position is not correct\n";
        cout << "enter the position of user1: ";
        cin>>pos1;
    }
    cout << "enter the position of user2: ";
    cin >> pos2;
    while (!isPositionCorrect(pos2))
    {
        cout<<"position is not correct\n";
        cout << "enter the position of user2: ";
        cin>>pos2;
    }
    vector<vector<bool> > board;
}