#include <bits/stdc++.h>
using namespace std;

const int N = 13; //Number of nodes
vector<pair<char, int>> graph_vector[N]; //store graph with it's child and their cost
vector<char> nodes = {'S','A','B','C','D','H','L','F','G','I','J','K','E'}; // Nodes identifiers

//Graph
unordered_map<char,vector<pair<char,int>>> graph = { //pattern {node, {{child, weight}}, {node, {{child, weight}}, ...}
   {'S', { {'A',7}, {'B',2}, {'C',3} } },
   {'A', { {'B',3}, {'D',4} } },
   {'B', { {'D',4}, {'H',1} } },
   {'C', { {'L',2} } },
   {'D', { {'F',5}} },
   {'H', { {'F',3}, {'G',2}} },
   {'L', { {'I',4}, {'J',4}} },
   {'G', { {'E',2} } },
   {'I', { {'K',4}} },
   {'J', { {'K',4}} },
   {'K', { {'E',5} } },
};
 
//Heuristic value of the each node
unordered_map<char,int> heuristic = {
   {'S',10},
   {'A',9},
   {'B',7},
   {'C',8},
   {'D',8},
   {'H',6},
   {'L',6},
   {'F',6},
   {'G',3},
   {'I',4},
   {'J',4},
   {'K',3},
   {'E',0},
};

//Global method to Print graph
void print_graph(){
   for (int u=0; u<N; u++) {
      cout << "Node = " << nodes[u]<<"\tHeuristic value: " <<heuristic[nodes[u]] <<"\nNeighbors:\n";
      for (auto it=graph_vector[u].begin(); it!=graph_vector[u].end(); it++) 
         cout << "\tNode = " << it->first << "  Weight = " << it->second << "\n";
      cout << "\n\n";
   }
}

//Best First Search
class BestFirstSearch{
   private:
      char goalNode;  //Goal Node 
      map<int,char>open; //Open priority Queue
      vector<char> close; //Close priority Queue
      int cost; // Calculate cost

      //Private method of calss which prints the final path with the cost
      void printPath(){
         cout<<"\n\nOptimal Path :"<<endl;
         for(auto i : close){
            cout<<"  "<<i<<"  ";
         }
         cout<<"\nTotal Cost: "<<cost;
      }
   public:
      //Pass the goal node in constructor
      BestFirstSearch(char gn){
         goalNode = gn;
      }

      //Finding the path
      void findSolution(){
         auto n = graph.find(nodes[0]);  //getting the start or initial node
         open.insert(make_pair(heuristic.find(n->first)->second, n->first) );  // add root node in open Queue
         bool goal = false; //set the goal boolean as the false for the condition

         while(goal != true){       //Loop untill goal not found     
            auto f = open.begin()->second;  //get node char name 
            open.erase(open.begin()->first); //remove current node from the open queue
            close.push_back(f); // Remove current node insert to the close queue
            cost += heuristic.find(f)->second; // get the huristic of the remove node 
            for(auto j : graph.find(f)->second)  open.insert(make_pair(heuristic.find(j.first)->second,j.first));// Insert all sucessor of current node
            
            //uncomment this for print for Tracing 
            // cout<<"\n\nOpen  :: \n";
            // for(auto i : open) cout<<i.first<<" "<<i.second<<"\t";
            // cout<<"\n\nClose  :: ";
            // for(auto i :close) cout<<i<<" ";


            //if theb goal state found the path from initial node to goal node is going to be print
            if(open.begin()->first == goal){
               printPath();
               goal = true;
            } 
         }
      }
};

//Driver 
int main(){
   for(int i = 0 ; i < nodes.size(); i++){
      if(graph.count(nodes[i]) == 0) continue;
      auto a = graph.find(nodes[i]);
      for(auto j : a->second) graph_vector[i].push_back(make_pair(j.first,j.second));   
   }
   print_graph();

   BestFirstSearch bfs('D');
   bfs.findSolution();
   return 0;
}
