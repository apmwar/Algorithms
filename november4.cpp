//https://www.codechef.com/NOV17/problems/VILTRIBE

#include <iostream>
#include <string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int acount, bcount, dots;
        char left;
        left = '.';
        acount = bcount = 0;
        for(int i = 0; i < s.size(); i++){
            if(left == '.'){
                left = s[i];
                dots = 0;
            }
            if(s[i] == 'A'){
                    acount++;
                    if(left == s[i])
                        acount += dots;
                    else
                        left = s[i];
                    dots = 0;
            }
            else if(s[i] == 'B'){
                bcount++;
                if(left == s[i])
                    bcount += dots;
                else
                    left = s[i];
                dots = 0;
            }
            else{
                dots++;
            }
        }
        cout << acount << " " << bcount << endl;
    }
    return 0;
}
