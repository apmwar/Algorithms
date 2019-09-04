#include <string>
#include <iostream>

using namespace std;

int main()
{
    string s, subs;
		cin >> subs >> s;
    int count = 0;
    size_t nPos = s.find(subs);
    while(nPos != string::npos)
    {
        count++;
        nPos = s.find("subs", nPos+1);
    }
    cout << count + 1;
		return 0;
}
