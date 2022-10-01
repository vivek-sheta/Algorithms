#include <bits/stdc++.h>
using namespace std;

//Create class for FCFS and give their functionality
class FCFS{
    private:
        vector< tuple<int,int,int,int,int> > P; //Process vector for store process info (Id , ArrivalTime , BurstTime , Waitingtime , TurnaroundTime)
        float averageWaitingTime; //Storing Average Waiting time
        float averageTurnAroundTime; //Storing Average TurnAround Time
    public:
        FCFS(int noProcess){
            int processArrivalTime,ProcessBurstTime,processId;
            cout<<"formate : |Process ID | Arrival-time | Process-Burst-time |: "<<endl;
                for(int i = 1; i <= noProcess; i++){
                    cout<<"Data : "<<i<<endl;
                    cin>>processId>>processArrivalTime>>ProcessBurstTime; //Get User input for process details
                    P.push_back(tuple<int,int,int,int,int>(processArrivalTime,processId,ProcessBurstTime,0,0)); //Add to Vector
            }
        }

        void showData(){
            cout<<"\n\nProcess ID\tArrivalTime\tBurstTime\tTurnAround Time\t\tWaiting Time\n";
            for(auto data: P){
                cout<<get<1>(data)<<"\t\t"<<get<0>(data)<<"\t\t"<<get<2>(data)<<"\t\t"<<get<3>(data)<<"\t\t\t"<<get<4>(data)<<endl;
            }
            cout<<"Average Waiting time : "<<averageWaitingTime<<"\nAverage Turn-Around time : "<<averageTurnAroundTime;
        }

        //Main FCFS Algorithm
        void callFCFS(){
            int sum = 0,tr = 0,wa = 0;      
            sort(P.begin(),P.end()); // Sort the vector by its arrival time
            for(int i = 0; i < P.size(); ++i){
                sum += get<2>(P[i]); //Add burst time
                get<3>(P[i]) = sum - get<0>(P[i]) ; //Find Turn Around time = CompletionTime - ArrivalTime
                get<4>(P[i]) = get<3>(P[i]) - get<2>(P[i]);//Assign to waiting time of process = TurnAroundtime - BurstTime
                wa += get<4>(P[i]); //Trace for find average of waiting time
                tr += get<3>(P[i]);
            }
            averageWaitingTime = (float)wa / P.size();
            averageTurnAroundTime = (float)tr / P.size();
        }
};

int main(){
    int pr;
    cout<<"Enter Number of Process : ";
    cin>>pr;
    FCFS obj(pr);
    obj.callFCFS();
    obj.showData();
}

/*
1 2	6
2 5 3
3 1	8
4 0	3
5 4	4
*/
