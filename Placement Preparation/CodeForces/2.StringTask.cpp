#include <bits/stdc++.h>
using namespace std;

void takeInput(int *arr, int n) {
     for(int i = 0; i < n; i++) {
         cin >> arr[i];
    }
}
bool check_vovel(char c){
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y'){
        return true;
    }
    else if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y'){
        return true;
    }

    return false;
}
int main() {

    string str; cin >> str;
    string output;

    for(int i = 0; i < str.length(); i++){
         if(isupper(str[i])){
            str[i] = tolower(str[i]);
            
        }
        if(check_vovel(str[i])){
            continue;
        }
        else{
            output.append(1u,'.'); 

             output += str[i];
            // cout << output << endl;
        }
       
    }

    cout << output << endl;

    return 0;
}