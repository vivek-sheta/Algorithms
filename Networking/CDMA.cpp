#include <bits/stdc++.h>
#define DEVICE 4
using namespace std;

vector<int> calculateCommonChennelData(vector<vector<int>> Excode){
    vector<int>commonData(DEVICE,0);
    for(int i = 0, j = 0; i < DEVICE ; i++){
        for(int k = 0; k < DEVICE ; k++) j += Excode[k][i];
        commonData[i] = j;
        j = 0;
    }
    cout<<" Data On Common Channel is : ";
    for(int k = 0; k < DEVICE ; k++) cout<<commonData[k]<<" ";
    return commonData;
}

void sendDataOnChannel(vector<int> data, int totalTrasaction){
    int c1 = 0,c2 = 0;
    for(int i = 0; i < totalTrasaction; i++){
        cout<<"\n\nEnter Sending Station : ";
        cin>>c1;
        cout<<"Enter Receiving Station : ";
        cin>>c2;

        if(data[c1-1] == -1) printf("Station : %d  sending [%d] to Station %d \n",c1,0,c2);
        else if(data[c1-1] == 1) printf("Station : %d  sending [%d] to Station %d \n",c1,1,c2);
        else printf("\nStation : %d NOT SENDING ANY DATA!!!!\n",c1);
    }
}

int main(){
    vector< vector<int> > code(DEVICE,vector<int>(DEVICE,0)), Excode(DEVICE,vector<int>(DEVICE,0));
    vector<int>sendData(DEVICE,0);
    //Taking inputs from the user
    for(int i = 0; i < DEVICE ; i++){
        cout<<"Enter the code of station "<<i+1<<" : ";
        for(int k = 0, j = 0; k < DEVICE ; k++){
            cin>>j;
            code[i][k]=j;
        }
        cout<<"Entered code of station C"<<i+1<<" is : [ ";
        for(int j = 0; j < DEVICE; j++) cout<<code[i][j]<<" ";
        cout<<"]\n\n";
    }

    //Taking inputs which station want to send
    string j = "";
    bool data = 0;
    for(int i = 0; i < DEVICE ; i++,j=""){
        printf("Is Station [%d]wants to send data  : ",i+1);
        cin>>j;
        if(j == "Yes" || j == "yes" || j == "YES" || j == "Y" || j == "y"){
                cout<<"Enter the bit value : ";
                cin>>data;
                (data) ? sendData[i] = data : sendData[i] = -1;
        }
        //create the data according to sending data
        for(int k = 0; k < DEVICE ; k++) Excode[i][k] = code[i][k] * sendData[i];
    }
    sendDataOnChannel( calculateCommonChennelData(Excode),2 );
}
