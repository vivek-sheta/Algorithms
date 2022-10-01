#include <bits/stdc++.h>
using namespace std;

vector<bool> bitStuffing(vector<bool> rawData){
    for(int i = 0,count = 0; i < rawData.size(); i++){
        if(rawData[i] == 1) ++count;
        else count = 0;
        if(count == 5) rawData.insert(rawData.begin() + i + 1,false);
    }
    return rawData;
}
    
int main()
{
    vector<bool> data,stuffedData;
    bool bin;
    int size;
    cout<<"enter data size : ";
    cin>>size;
    
    cout<<"Enter data [binary]: ";
    for(int i = 0; i < size; i++){
        cin>>bin;
        data.push_back(bin);
    }
    cout<<"\nstuffed Data : ";
    stuffedData = bitStuffing(data);
    for(int i = 0; i < stuffedData.size(); i++) cout<<stuffedData[i]<<"  ";
}
