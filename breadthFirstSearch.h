#define problemSize 3
using namespace std;

vector<int> goalState = {1,2,3,4,5,6,7,8,0};
set<vector<int> > visitedStates;
list<vector<int> > toVisitStates;
vector<int> currentState;

// qual linha está v[i]? é dada por (i/N)
// qual coluna está v[i]? é dado por i mod N

//quando é que posso mover para a direita?
// if ( i mod N < N-1)
//quando é que posso mover para a esquerda?
// if (i mod N > 0)
//quando é que posso mover para cima?
// if( i/N > 0)
//quando é que posso mover para baixo?
// if (i/N < N-1)

//class Node{
//private:
//Node * parent;
//public:
//	vector<int> 
//}

void showState(vector<int> state){
	cout << endl;
	for(int i = 0; i < state.size(); i++){		
		cout << state[i] << " ";				
	}
}

void initialize(vector<int> state){	
	visitedStates.insert(state);	
}

void moveFunction(vector<int> vectorPuzzle, int zeroPosition){  		
	// Esquerda	
	vector<int> vectorPuzzleTmp = vectorPuzzle;
	int zeroPositionTmp = zeroPosition;
    if ((zeroPositionTmp % problemSize > 0)){		
        swap(vectorPuzzleTmp[zeroPositionTmp], vectorPuzzleTmp[zeroPositionTmp-1]);
        zeroPositionTmp = zeroPositionTmp-1;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);			
    }
	// Cima	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize > 0)){			
        swap(vectorPuzzleTmp[zeroPositionTmp],vectorPuzzleTmp[zeroPositionTmp-problemSize]);
        zeroPositionTmp = zeroPositionTmp-problemSize;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }	
	// Direita 	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if (( zeroPositionTmp % problemSize < problemSize-1)){			
        swap(vectorPuzzleTmp[zeroPositionTmp],vectorPuzzleTmp[zeroPositionTmp+1]);
        zeroPositionTmp = zeroPositionTmp+1;			
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }
	// Baixo	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize < problemSize-1)){
        swap(vectorPuzzleTmp[zeroPositionTmp], vectorPuzzleTmp[zeroPositionTmp+problemSize]);
        zeroPositionTmp = zeroPositionTmp + problemSize; 
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);		
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);
    }  
}

bool isGoalState(vector<int> state){
	for(int i = 0; i < state.size(); i++){
		if (state[i] != goalState[i])
			return false;
	}
	return true;
}

int getZeroPosition(vector<int> state){
	for(int i = 0; i < state.size(); i++){
		if(state[i] == 0)
			return i;
	}
	return 1;
}

void breadthSearch(){
	int numberOfIterations = 0;
	toVisitStates.push_front(*visitedStates.begin());
// && currentDepth < maxDepth
	while(!toVisitStates.empty()){		
		currentState = *toVisitStates.begin();
		toVisitStates.erase(toVisitStates.begin());		
		if(isGoalState(currentState)){
			cout << endl;
			showState(currentState);
			printf("\nGoal State\n");			
			return;
		}else{					
			cout << endl;
			cout << numberOfIterations;			
			showState(currentState);			
			moveFunction(currentState, getZeroPosition(currentState));					
		}
		numberOfIterations++;
	}		
}