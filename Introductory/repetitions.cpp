#include <iostream>
#include <string>
using namespace std;

int main(){

    string s;
    cin >> s;
    int n = s.length();

    int max = 1;
    int count = 1;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            count++;
            if(count > max){
                max = count;
            }
        }else{
            count = 1;
        }
    }
    cout << max;
    return 0;
}