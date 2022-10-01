#include<bits/stdc++.h>
using namespace std;


class LRC{
    private:
    string message;
    int datasize = 7;
    string padding = "",check = "";

    
    //Doing padding based on the 1's in the string
    bool checkEven(string data){
        bool flag = false;
        int track = 0;
        for(int i = 0; data[i] != '\0' ; i++)
            if(data[i] == 49) ++track; 

        if(track % 2) return false;
        else return true;
    }

    //For sender to add the padding
    void doPadding(string data){
        if(!checkEven(data)) padding += "1";
        else padding += "0";
    }

    //For reciver to check the padding
    void checkPadding(string data){
        if(!checkEven(data)) check += "1";
        else check += "0";
    }

    public:
    void reciver(string data[]){
        for(int i = 0; i < datasize; i++){
            string t = "";
            for(int j = 0; j < message.size() ; j++) t += data[j][i];
            checkPadding(t);
        }
        cout<<"\nRecevied Extra frame : "<<padding;
        if(padding == check)  cout<<"\nCheck at receiver side : "<<check<<"\nMessage Recived Sucessfully"<<endl;
        else  cout<<"Error occurred in message";
    }

    void sender(){    
        cout<<"Enter Message : ";
        cin>>message;
        char temp[7];
        string buffer[message.size()];
        for(int i = 0; i < message.size(); i++){
            itoa(message[i], temp , 2);
            buffer[i] = temp;
        }
        cout<<"Frame Before Padding : ";
        for(int i = 0; i < message.size(); i++){
            cout<<"\n"<<message[i]<<" -> ";
            for(int j = 0; j < datasize; j++){
                cout<<buffer[i][j]<<" ";
            }
        }
        for(int i = 0; i < datasize; i++){
            string t = "";
            for(int j = 0; j < message.size() ; j++) t += buffer[j][i];
            doPadding(t);
        }
        
        reciver(buffer);
    }
};

int main(){
    LRC *obj = new LRC();
    obj->sender();
    return 0;
}
