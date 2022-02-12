# Meeting Scheduler
Given the daily calander of every employee in a company, create a simple meeting scheduler.

### Input
Given an employee, try to optimize the daily calander.

```cpp
vector<Employees> employees;
enum Designation { CEO, CTO, MANAGER, SR_EMPLOYEE, EMPLOYEE };
class Employees {
    public:
    int empId;
    Designation designation;
    vector<Interval> meetings; // daily meeting calander.
}
class Interval {
public:
    int start, end; // [start, end) start is inclusive and end is exclusive.
}
```

### Rules of the schedule - 
If employee A has conflicting meetings with employee B and employee C then 
1. A will attend the meeting with employee of higher designation. For example if B is CEO and C is Manager then A will attend meeting with B and cancel meeting with C.
2.  A can attend either meeting if the designation for them is same.
3.  Try to optimize for as many meetings as possible without any conflicts and remove other meetings from the list.
