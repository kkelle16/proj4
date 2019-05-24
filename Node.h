#ifndef NODE_INCLUDE
#define NODE_INCLUDE

#include <utility>

using namespace std;

//creating a struct node that contains the back edge o the shortest path
//the total distance to the starting node, a visited field, the cost of
//going through that node, the char of which tile it is, and its row and column value
struct Node{
	public:
		pair<int, int>  backEdge = make_pair(-1, -1);
		int distance = -1;
		int visited = 0;
		int cost;
		char tile;
		int row;
		int col;
		Node(int c, char t, int i, int j){
			cost = c;
			tile = t;
			row = i;
			col = j;
		}
};

#endif
