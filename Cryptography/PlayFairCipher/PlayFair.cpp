#include <bits/stdc++.h>
using namespace std;

class PlayFair{
    private:
        char key[5][5];
        int countEncryption,countDecryption;
        string kText,plainText,cipherText,decryptedText;
        vector<string> mappingPlain,mappingCipher;

        void generateKey(){  //Generate key
            string temp="";
            unordered_map<char,int> k;
            for(auto i : kText) k.insert(pair<char,int>(i,0)); //get all the char of keyString only one time in map
            for(auto i : k) temp += i.first; //add that char into string
            reverse(temp.begin(),temp.end()); //reverse string because the unorder_map is storing in revese like stack 
            for(int i = 0; i < 26; i++) { 
                if(k.count('a'+i) || char('a'+i) == 'j') continue; //continue if char exist in string or char is 'j'
                temp+=char('a'+i);
            }
            for(int i = 0, count = 0; i < 5; i++){  //Create key matrix
                for(int j = 0; j < 5; j++,count++) key[j][i] = temp[count];
            }
            cout<<"Key Generate sucessfully!!"<<endl;
        }

        void showKey(){
            for(int i = 0, count = 0; i < 5; i++){  //Show key matrix
                for(int j = 0; j < 5; j++,count++) cout<<"["<<key[j][i]<<"]  ";
                cout<<endl;
            }
        }

        void padding(bool type){    //Padding fuction create the pair of two letter
            string temp="";
            if(type){ 
                if(plainText.size()/2 != 0) plainText += 'x';
                for(int i = 1; i < plainText.size(); i+=2,temp=""){
                    temp+=plainText[i-1];
                    if(plainText[i] == plainText[i-1])  {
                        temp+='x';  i--;
                    }else   temp+=plainText[i];
                    mappingPlain.push_back(temp);
                }
            }else{
                for(int i = 0; i < cipherText.size(); i+=2,temp=""){
                    temp+=cipherText[i];
                    temp+=cipherText[i+1];
                    mappingCipher.push_back(temp);
                }
            }
        }

        string encryption(){
            cipherText = ""; //string holds final data
            padding(1); //first do padding

            for(auto data: mappingPlain){ //take each padding pair and get eqvivelent alphabets
                //cout<<data<<"   ";
                pair<int,int> indexA,indexB; 
                indexA = find(data[0]); //cout<<data.first[0]<<" -> "<<indexA.first<<"  "<<indexA.second<<endl; 
                indexB = find(data[1]); //cout<<data.first[1]<<" -> "<<indexB.first<<"  "<<indexB.second<<endl;

                if(indexA.first == indexB.first){  //if row are same
                    cipherText += key[indexA.first][(indexA.second+1)%5];
                    cipherText += key[indexB.first][(indexB.second+1)%5];
                }else if(indexA.second == indexB.second){ //if colom are same
                    cipherText += key[(indexA.first+1)%5][indexA.second];
                    cipherText += key[(indexB.first+1)%5][indexB.second];
                }else{  //if both row and colom are different
                    cipherText += key[indexB.first][indexA.second];
                    cipherText += key[indexA.first][indexB.second];
                }
                //cout<<"-> "<<cipherText<<endl;
            }
            mappingPlain.erase(mappingPlain.begin(),mappingPlain.end()); //reset the vector for hold vallue for next data
            return cipherText;
        }

        string decryption(){
            decryptedText = "";
            padding(0);
            for(auto data: mappingCipher){
                //cout<<data<<"   ";
                pair<int,int> indexA,indexB; 
                indexA = find(data[0]); //cout<<data.first[0]<<" -> "<<indexA.first<<"  "<<indexA.second<<endl; 
                indexB = find(data[1]); //cout<<data.first[1]<<" -> "<<indexB.first<<"  "<<indexB.second<<endl;

                if(indexA.first == indexB.first){
                    decryptedText += key[indexA.first][(indexA.second-1+5)%5];
                    decryptedText += key[indexB.first][(indexB.second-1+5)%5];
                }else if(indexA.second == indexB.second){
                    decryptedText += key[(indexA.first-1+5)%5][indexA.second];
                    decryptedText += key[(indexB.first-1+5)%5][indexB.second];
                }else{
                    decryptedText += key[indexB.first][indexA.second];
                    decryptedText += key[indexA.first][indexB.second];
                }
                //cout<<"-> "<<decryptedText<<endl;
            }
            mappingCipher.erase(mappingCipher.begin(),mappingCipher.end());
            return decryptedText;
        }

        pair<int,int> find(char data){  //fnds the position of latter in metrix and return the indexes as the pair
            for(int i = 0; i < 5; i++){
                for(int j = 0; j < 5; j++) {
                    if(key[j][i] == data) return make_pair(j,i);
                }
            }
            return make_pair(0,0);
        }
        
    public:            
        PlayFair(string key){ //Constructor take key string as input
            kText = key;
            generateKey();
            countDecryption = countEncryption  = 0;
            showKey();  //remove comment to see key
        } 
        
        string encryption(string data){ //function take whole sting as input for encyption
            plainText = data; ++countEncryption;
            return encryption();
        }
    
        string decryption(string data){ //function take whole sting as input for decryption
            cipherText = data; ++countDecryption;
            return decryption();
        }

        void details(){
            cout<<"Total message Encytion: "<<countEncryption<<"\nTotal message Decryption: "<<countDecryption<<endl;
        }
};

int main(){
    string placeHolder,kText;
    cout<<"Enter The key: ";
    cin>>kText;
    PlayFair obj(kText); //create Playfair object by passing key string
    fstream output; //For writing output which is encrypted data and input for decrypt data
    ifstream input("testCases.txt"); //For getting input from the file
    ofstream decrypt("DecryptData.txt"); //For writing the decrypted data 

    output.open ("EncryptedData.txt",ios::out);
    while ( getline (input,placeHolder) ) output<<obj.encryption(placeHolder)<<endl;
    output.close();
    output.open ("EncryptedData.txt",ios::in);
    while ( getline (output,placeHolder) ) decrypt<<obj.decryption(placeHolder)<<endl;
    obj.details();
    return 0;
}
