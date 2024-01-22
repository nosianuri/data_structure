#include<bits/stdc++.h>
using namespace std;
class Student {
public:
    string name;
    int roll;
    int marks;
    Student(string n, int r, int m) {
        name = n;
        roll = r;
        marks = m;
    }
};

class Compare {
public:
    bool operator() (const Student& s1, const Student& s2) {
        if (s1.marks != s2.marks) {
            return s1.marks < s2.marks;
        } else {
            return s1.roll > s2.roll;
        }
    }
};

int main() {
    int n;
    cin >> n;
    priority_queue<Student, vector<Student>, Compare> pos;
    for (int i = 0; i < n; ++i) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        pos.push(Student(name, roll, marks));
    }
    int q;
    cin >> q;
    while (q--) {
        int cmnd;
        cin >> cmnd;
        if (cmnd == 0) {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            pos.push(Student(name, roll, marks));
            Student topStu = pos.top();
            cout << topStu.name << " " << topStu.roll << " " << topStu.marks << endl;
        } else if (cmnd == 1) {
            if (!pos.empty()) {
                Student topStu = pos.top();
                cout << topStu.name << " " << topStu.roll << " " << topStu.marks << endl;
            } else {
                cout << "Empty" << endl;
            }
        } else if (cmnd == 2) {
            if (!pos.empty()) {
                pos.pop();
                if (!pos.empty()) {
                    Student topStu = pos.top();
                    cout << topStu.name << " " << topStu.roll << " " << topStu.marks << endl;
                } else {
                    cout << "Empty" << endl;
                }
            } else {
                cout << "Empty" << endl;
            }
        }
    }
    return 0;
}