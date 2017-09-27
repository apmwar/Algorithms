#include <iostream>
#include<algorithm>
#include<vector>
#include<utility>
#include<iomanip>
using namespace std;
bool compbyrat(const pair<long long int,long long int> &a, const pair<long long int,long long int> &b)
{
    return ((double)((double)a.first/(double)a.second)> (double)((double) b.first/(double) b.second)) ;
}
int main() {
    long long int n, weight;
    cin>>n>>weight;

    vector<pair<long long int,long long int> > v(n+2);
    for(long long int i = 0; i < n; i++){
        cin>>v[i].first>>v[i].second;
    }

    sort(v.begin(), v.end(), compbyrat);
    //cout<<v[0].first;
    long long int currentweight = 0;
    double ans = 0.0000;
    for(long long int i =0; i < n && currentweight < weight; i++){
        if(currentweight + v[i].second <= weight){
            ans = ans + v[i].first;
            currentweight = currentweight + v[i].second;
            //cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        else{
            ans = ans + ((double)((double)v[i].first/(double)v[i].second) * (weight -currentweight));
            currentweight = currentweight + v[i].second;
        }


    }
    cout<<fixed << setprecision(4)<<ans;
    return 0;
}
