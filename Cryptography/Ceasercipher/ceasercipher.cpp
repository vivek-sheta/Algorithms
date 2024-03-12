#include<bits/stdc++.h>
using namespace std;
//FUNCTION: Encrypt the data
string encryptData(string plainText,int key){
    string eData=""; //Empty string to store the Encrypted data
    for(int i = 0; i < plainText.size(); i++){
        if(plainText[i] >= 'A' && plainText[i] <= 'Z') eData += char( int(plainText[i] + key - 65) %26 + 65);  
        if(plainText[i] >= 'a' && plainText[i] <= 'z') eData += char( int( plainText[i] + key - 97) %26 + 97);
    }
    return eData;
}

//FUNCTION: Decrypt the data 
string decryptData(string cText,int key){
    string eData=""; //Empty string for store decrypted data
    if(key > 26 ) key = key % 26;  //Set the key in the range 0-25 by calculating ( mod % 26 ) of original key
    for(int i = 0; i < cText.size(); i++){
        if(cText[i] >= 'A' && cText[i] <= 'Z') eData += char(int( (cText[i] - 'A' - key) + 26) % 26 + 65);  
        if(cText[i] >= 'a' && cText[i] <= 'z') eData += char(int( (cText[i] - 'a' - key) + 26) % 26 + 97);
    }
    return eData;
}

int main(){
    string plainText;
    int key;
    cout<<"Enter Key: ";
    cin>>key;

    fstream output; //For writing output which is encrypted data and input for decrypt data
    ifstream input("testCases.txt"); //For getting input from the file
    ofstream decrypt("DecryptData.txt"); //For writing the decrypted data 

    output.open ("EncryptedData.txt",ios::out);
    while ( getline (input,plainText) ) output<<encryptData(plainText,key)<<endl;
    output.close();
    output.open ("EncryptedData.txt",ios::in);
    while ( getline (output,plainText) ) decrypt<<decryptData(plainText,key)<<endl;
    
    return 0;
}
