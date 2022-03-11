#include <iostream>
#include "queue.h"
#include <string>

using namespace std;

ostream& operator<<(ostream& out, const pair<int, Priority>& p) {
    if ((int)(p.second) == 0)
        return out << p.first << ", " << "high";
    if ((int)(p.second) == 1)
        return out << p.first << ", " << "medium";
    if ((int)(p.second) == 2)
        return out << p.first << ", " << "low";
}

int main()
{
    Priority h = High, m = Medium, l = Low;
    queue q;
    cout << q << endl;
    q.push(1, h);
    q.push(2, m);
    q.push(3, l);
    cout << q << endl;
    queue q1(q);
    cout << q1 << endl;
    cout << endl;

    queue q2;
    cout << q2 << endl;
    q2 = q;
    cout << q << endl;
    cout << q2 << endl;
    cout << endl;

    queue q3;
    cout << q3.isEmpty() << endl;
    q3.push(12, h);
    q3.push(0, m);
    cout << q3 << endl << q3.size() << endl;
    cout << q3.sizeHighPriority() << ' ' << q3.sizeMediumPriority() << ' ' << q3.sizeLowPriority() << endl;
    q3.push(43, h);
    q3.push(33, l);
    cout << q3 << endl << q3.size() << endl;
    cout << q3.sizeHighPriority() << ' ' << q3.sizeMediumPriority() << ' ' << q3.sizeLowPriority() << endl;
    cout << q3.isEmpty() << endl;
    cout << endl;

   
    cout << q << endl;
    q.push(6, m);
    q.push(8, h);
    q.push(9, l);
    q.push(-3, l);
    q.push(1, m);
    cout << q << endl;
    do
    {
        if (!q.isEmpty())
            cout << q.top() << endl;
    } while (q.pop());

    return 0;
}
