// dijsktras.cpp
//Name: Kelsey Kelley
//Assignment: Project 4
//overview: Given a map of tiles with different costs
//implement dijkstras algorithm to find the shortest
//path from the runners starting position to a 
//specified goal tile. 

// Main Execution

#include <iostream>
#include <utility>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#include <limits>
#include "Node.h"
#include <deque>

using namespace std;

//Dijkstras algorithm function
void dijkstras(vector<vector<Node*> > &v, pair<int, int> source, pair<int, int> dest){

	//declaring variables
	int d;
	multimap<int, Node*> sptset;
	multimap<int, Node*>::iterator it;
	int r = v.size();
	int c = v[0].size();
	int startR = source.first;
	int startC = source.second;

	Node *n;
	Node *n2;

	//setting up the mutimap and temp variables before going through
	//all nodes
	n = v[startR][startC];
	n->distance = 0;
	sptset.insert(make_pair(n->distance, n));

	//continually run algorithm until multimap is empty
	while(!sptset.empty()){
	
		//iterator to point to beginning of multimap to find which node to
		//next be processed
		it = sptset.begin();

		//checking if the node has already been visited and if it has it is
		//erased from the multimap and it will then be reset
		if(it->second->visited == 1){
		
			sptset.erase(it);
			continue;

		}

		//setting up variables for processing
		n = it->second;
		startR = n->row;
		startC = n->col;

		//calculating distance and setting the nodes
		//visited field to 1
		d = n->distance + n->cost;
		n->visited = 1;

		//checking top neighbor if valid
		if(startR-1 > 0){
		
			n2 = v[startR-1][startC];
		
			//if neighbors distance has not been set or is larger than calculated distance
			//the neighbors distance field is updated, back edge is updated and neighbor is inserted 
			//into the multimap
			if((n2->distance == -1) || (d < n2->distance)){
				
				n2->distance = d;
				n2->backEdge = make_pair(startR, startC);
				sptset.insert(make_pair(d, n2));
		
			}
	
		}

		//checking right neigbor if valid
		if(startC+1 < c){
		
			n2 = v[startR][startC+1];

			//if neighbors distance has not been set or is larger than calculated distance
			//the neighbors distance field is updated, back edge is updated and neighbor is inserted 
			//into the multimap
			if((n2->distance == -1) || (d < n2->distance)){
				
				n2->distance = d;
				n2->backEdge = make_pair(startR, startC);
				sptset.insert(make_pair(d, n2));
		
			}
	
		}
	
		//checking bottom neighbor if valid
		if(startR+1 < r){
		
			n2 = v[startR+1][startC];
		
			//same steps as previous neighbor nodes are followed
			if((n2->distance == -1) || (d < n2->distance)){
				
				n2->distance = d;
				n2->backEdge = make_pair(startR, startC);
				sptset.insert(make_pair(d, n2));
		
			}
	
		}
	
		//checking left neighbor if valid
		if(startC-1 > 0){
		
			n2 = v[startR][startC-1];
		
			//same steps as previous neighbor nodes are followed
			if((n2->distance == -1) || (d < n2->distance)){
			
				n2->distance = d;
				n2->backEdge = make_pair(startR, startC);
				sptset.insert(make_pair(d, n2));
		
			}

		}
		
	}

}


//function to create the shortest path from source to destination
void createPath(vector<vector<Node*> > v, pair<int, int> start, pair<int, int> goal){

	deque<pair<int, int> > path;
	deque<pair<int, int> >::iterator pit;

	//putting goal into the path, back edges are inserted from the front, 
	//so path will be in the correct order
	path.push_front(goal);

	pair<int, int> b;
	b = v[goal.first][goal.second]->backEdge;

	//while the backEdge does not equal the starting position
	//the back edges are inserted into the path and followed to the start
	while(b != start){
	
		path.push_front(b);
		b = v[b.first][b.second]->backEdge;

	}

	//putting the starting location into the path
	path.push_front(start);

	//printing the distance in the goal node, as that will have the shortest distance from the starting node to goal
	//stored as per dijkstras algorithm
	cout << v[goal.first][goal.second]->distance << endl;

	//path is printed out appropriately
	for(pit = path.begin(); pit != path.end(); pit++){
	
		cout << pit->first << " " <<  pit->second << endl;

	}

}



int main(int argc, char *argv[]) {

	//setting up variables to be read in
	map<char, int> tileInfo;
	map<char, int>::iterator it;

	int numTiles;
	//storing the map as a vector of vector of Nodes, I defined in
	//Node.h, Nodes are structs
	vector<vector<Node*> > landscape;

	pair<int, int> runnerStart;
	pair<int, int> runnerGoal;
	int rows, cols;

	char c;
	int weight;
	istringstream buffer;
	string line;

	int count = 0;
	int a, b;

	//reading in the data for the tiles on map
	cin >> numTiles;
	for(int i = 0; i < numTiles; i++){

		cin >> c;
		cin >> weight;
		tileInfo.insert(make_pair(c, weight));

	}

	//reading in rows and cols of map
	cin >> rows >> cols;

	//resizing the 2d vector for reading in
	landscape.resize(rows);
	for(int i = 0;  i < rows; i++){

		landscape[i].resize(cols);

	}

	//reading in the map
	while(count != (rows)){
	
		buffer.clear();
		getline(cin, line);
		buffer.str(line);
	
		for(int i = 0; i < cols; i++){
		
			cin >> c;
			it = tileInfo.find(c);
			int w = it->second;
			Node *n;
			//creaing a new instance of a node and initializing appropriate variables
			//and inserting into the 2d vector
			n = new Node(w, c, count, i);
			landscape[count][i] = n;

		}

		count++;

	}
	

	//reading in the runners starting and desired
	//ending position
	cin >> a >> b;
	runnerStart = make_pair(a,b);

	cin >> a >> b;
	runnerGoal = make_pair(a, b);
	

	//calling dijkstras and then calling the create path function
	dijkstras(landscape, runnerStart, runnerGoal);
	createPath(landscape, runnerStart, runnerGoal);

	//deleting all the nodes created
	for(int i = 0; i < rows; i++){
	
		for(int j = 0; j < cols; j++){
		
			delete landscape[i][j];
	
		}

	}

	return 0;
}
