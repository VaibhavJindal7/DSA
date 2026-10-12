#include<iostream>
#include<string>
#include<stack>
using namespace std;
int count=0;
int vp(string s) {
    stack<int> st;
    st.push(-1);
    int maxlength=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){
            count++;
            st.push(i);

        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                maxlength=max(maxlength,i-st.top());
                

            }
        }
    }
    return maxlength;
}
int main(){
    string s;
    cout<<"Enter a string: ";
    cin>>s;
    int result=vp(s);
    cout<<result<<endl;
    cout<<"max height: "<<count<<endl;  
    return 0;
}