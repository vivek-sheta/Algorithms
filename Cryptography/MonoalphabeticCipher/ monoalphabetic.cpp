#include <bits/stdc++.h>
#include <math.h>
#define RANDOM 3
using namespace std;

string encryptData(string data,map<char,char> key){
    string eData="";
    for(char ch : data){
        auto it = key.find(ch);
        eData += char(it->second);
    }
    return eData;
}   

string decryptData(string data,map<char,char> key){
    string eData="";
    for(char ch : data){
        for(auto it: key){
            if( (it.second) == ch){
                eData += char(it.first);
                break;
            }
        }
    }
    return eData;
}

int main(){
    //For random alphabets gonerate
    array<char,26> alpha{'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string placeHolder;
    map<char,char> key;
    cout<<"Monoalphabatic cipher encryption";
    
    for(int i = 0; i < RANDOM; i++) random_shuffle(alpha.begin(),alpha.end());
    for(int i = 0; i < 26; i++) key.insert(pair<char,char>(char(97+i),alpha[i]));

    fstream output; //For writing output which is encrypted data and input for decrypt data
    ifstream input("testCases.txt"); //For getting input from the file
    ofstream decrypt("DecryptData.txt"); //For writing the decrypted data 

    output.open ("EncryptedData.txt",ios::out);
    while ( getline (input,placeHolder) ) output<<encryptData(placeHolder,key)<<endl;
    output.close();
    output.open ("EncryptedData.txt",ios::in);
    while ( getline (output,placeHolder) ) decrypt<<decryptData(placeHolder,key)<<endl;

    return 0;
}
