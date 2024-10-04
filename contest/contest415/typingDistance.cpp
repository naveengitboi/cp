#include <bits/stdc++.h>
#include <utility>
using namespace std;



pair<int, int> getLocation(vector<string>& vect, char ele){
    pair<int, int> location;
    for(int i = 0; i< vect.size(); i++){
        for(int j = 0; j< vect[0].length(); j++){
            char c = vect[i][j];
            if(c == ele){
                location = make_pair(i, j);
                return location;
            }
        }
    }
    return location;
}
int typingDistance(string& s){
    vector<string> vect{
        "QWERTYUIOP",
        "ASDFGHJKL ",
        " ZXCVBNM  "
    };
    int distance = 0;
    int len = s.length();
    int x1, y1;
    auto p = getLocation(vect, s[0]);
    x1 = p.first;
    y1 = p.second;
    for(int i = 1; i< len; i++){
        pair<int,int> currentLocation = getLocation(vect,s[i]);
        int x2 = currentLocation.first;
        int y2 = currentLocation.second;
        distance += (abs(x2-x1) + abs(y1-y2));
        x1 = x2;
        y1 = y2;
    }
    return distance;
}

int main(){
    string s;
    cin >> s; 
    int ans = typingDistance(s);
    cout<<ans<<endl;
    return 0;
}
