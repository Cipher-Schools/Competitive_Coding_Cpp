#include <bits/stdc++.h>
using namespace std;

vector<Employees> employees;
enum Designation
{
	CEO,
	CTO,
	MANAGER,
	SR_EMPLOYEE,
	EMPLOYEE
};
unordered_map<int, Designation> mp;
bool cmp(Interval a, Interval b)
{
	return mp[a.empId] > mp[b.empId];
}
class Employees
{
public:
	Employees(int id, Designation d)
	{
		this->empId = id;
		this->designation = d;
		mp[empId] = d;
	}
	int empId;
	Designation designation;
	vector<Interval> meetings; // daily meeting calander.
	void schedule()
	{
		int n = meeting.size();
		sort(meetings.begin(), meetings.end(), cmp);
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (meetings[i].end > meetings[i].start)
				{
					meetings.erase(meetings.begin() + j);
					n--;
					j--;
				}
			}
		}
	}
	void createmeeting(int start, int end, int id)
	{
		Interval obj = new Interval(start, end, id);
		meetings.push_back(obj);
		schedule();
	}
};
class Interval
{
public:
	int start, end; // [start, end) start is inclusive and end is exclusive.
	int empId;
	Interval(int start, int end, int id)
	{
		this->start=start;
		this->end=end;
		this->empId=id;
	}

};

int
main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	return 0;
}