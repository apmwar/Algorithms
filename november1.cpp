#include <iostream>
#include <vector>
using namespace std;

class Poly{
public:
    int a0, a1, a2, a3;
    long long int compute(int t){

    }
};

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n;
        vector<Poly> Y(n);
        for(int i = 0; i < n; i++)
            cin >> Y[i].a0 >> Y[i].a1 >> Y[i].a2 >> Y[i].a3;
        cin >> q;
        vector<int> t(q);
        for(int i = 0; i < q; i++)
            cin >> t[i];
        for(int i = 0; i < q; i++){
            //insert solution code here
        }
    }
    return 0;
}
