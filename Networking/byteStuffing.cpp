#include <bits/stdc++.h>
using namespace std;

vector<char> byteStuffing(vector<char> rawData,char flag,char esc){
    //add flag at first and last 
    rawData.insert(rawData.begin(),flag); 
    rawData.push_back(flag);
    //add esc char in data if data is flag or esc
    for(int i = 1; i < rawData.size() - 1; i++){
        if(rawData[i] == flag or rawData[i] == esc){
            rawData.insert(rawData.begin() + i,esc);
            i++;
        }//insert esc char befor flag or esc
    }
    return rawData;
}

int main()
{
    vector<char> data,stuffedData;
    string str;
    cout<<"Enter data : ";
    cin>>str;
    for(char i : str) data.push_back(i);
    
    char flag, esc;
    cout<<"Enter flag and esc key : ";
    cin>>flag>>esc;
    
    stuffedData = byteStuffing(data,flag,esc);
    for(int i = 0; i < stuffedData.size(); i++) cout<<stuffedData[i]<<"  ";
}
