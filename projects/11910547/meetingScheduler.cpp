/* 
Rules of the schedule -
If employee A has conflicting meetings with employee B and employee C then

A will attend the meeting with employee of higher designation. For example if B is CEO and C is Manager then A will attend meeting with B and cancel meeting with C.
A can attend either meeting if the designation for them is same.
Try to optimize for as many meetings as possible without any conflicts and remove other meetings from the list.
*/
#include<bits/stdc++.h>

using namespace std;

enum Designation { CEO, CTO, MANAGER, SR_EMPLOYEE, EMPLOYEE };

unordered_map<string, int> ranks = {{"CEO",0}, {"CTO", 1}, {"MANAGER", 2}, {"SR_EMPLOYEE", 3}, {"EMPLOYEE", 4}};

class Interval {
public:
    int start, end; // [start, end) start is inclusive and end is exclusive.
    int empId;
};

class Employees {
    public:
    int empId;
    string designation;
    vector<Interval> meetings; // daily meeting calander.

    int getDesignation() {
        return ranks[this->designation];
    }

};
vector<Employees> employees;

Employees findEmployee(int empId) {
    Employees searchedEmployee;
    for(int i=0; i<employees.size(); i++) {
        searchedEmployee = employees[i];
        if(searchedEmployee.empId == empId) return searchedEmployee;
    }
}

int main() {
    int n;
    cout<<"Enter the Total Number of Employees: ";
    cin>>n;
    // vector<Employees> employees(n);
    cout<<endl;
    for(int i=0; i<n; i++) {
        int meetN;
        Employees e;
        cout<<"Enter ID and Designation of Employee "<<i<<":\n";
        cin>>e.empId>>e.designation;
        cout<<"\nEnter the total number of meeting of Employeee "<<i<<":\n";
        cin>>meetN;
        vector<Interval> meets(meetN);
        cout<<"\nEnter the start,end and empID details of meeting:\n";
        for(int j=0; j<meetN; j++) {
            cin>>meets[j].start>>meets[j].end>>meets[j].empId;
        }
        e.meetings = meets;
        employees.push_back(e);
    }

    cout<<"\n\nBelow is the meeting scheduled for everyone: \n";
    for(int i=0; i<n; i++) {
        Employees currEmp = employees[i];
        sort(currEmp.meetings.begin(), currEmp.meetings.end(), [&](Interval a, Interval b) {
            if(a.end == b.end) {
                return findEmployee(a.empId).getDesignation() < findEmployee(b.empId).getDesignation();
            }
            else {
                return a.end < b.end;
            }
        });

        cout<<"For Employee - "<<currEmp.empId<<":";
        int meetSize = currEmp.meetings.size();
        int currEmpTotalMeets = 0, endMeetSize = -1;
        for(int i=0; i<meetSize; i++) {
            if(currEmp.meetings[i].start > endMeetSize) {
                // This meeting is attendable
                currEmpTotalMeets++;
                endMeetSize = currEmp.meetings[i].end;
            }
        }
        cout<<"Total attendable meetings - "<<currEmpTotalMeets<<endl<<endl;

    }


}