#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char *argv[]){

	if(argc != 2){
		cerr << "Need to specify N value" << endl;
	}

	int N = atoi(argv[1]);

	int numTiles = 6;

	char tiles[] = {'f', 'g', 'G', 'h', 'm', 'r'};
	int costs[] = {3, 1, 2, 4, 7, 5};

	vector<vector<char> > map;
	map.resize(N);
	for(int i = 0; i < N; i++){
		map[i].resize(N);
	}

	srand(time(NULL));
	int random;

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			random = rand() % 6;
			map[i][j] = tiles[random];
		}
	}

	cout << numTiles << endl;
	for(int i = 0; i < numTiles; i++){
		cout << tiles[i] << " " << costs[i] << endl;
	}
	cout << N << " " << N << endl;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << map[i][j];
			if(j != N-1){
				cout << " ";
			}
		}
		cout << endl;
	}
	cout << 0 << " " << 0 << endl;
	cout << N-1 << " " << N-1 << endl;

	return 0;
}
