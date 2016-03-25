#define problemSize 3
using namespace std;

vector<int> goalState = {1,2,3,4,5,6,7,8,0};
set<vector<int> > visitedStates;
list<vector<int> > toVisitStates;
vector<int> currentState;

// which row is v[i]? it's given by (i/N)
// which column is v[i]? it's given by (i mod N)

//when can I move right?
// if ( i mod N < N-1)
//when can I move left?
// if (i mod N > 0)
//when can I move up?
// if( i/N > 0)
//when can I move down?
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
	// Left	
	vector<int> vectorPuzzleTmp = vectorPuzzle;
	int zeroPositionTmp = zeroPosition;
    if ((zeroPositionTmp % problemSize > 0)){		
        swap(vectorPuzzleTmp[zeroPositionTmp], vectorPuzzleTmp[zeroPositionTmp-1]);
        zeroPositionTmp = zeroPositionTmp-1;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);			
    }
	// Up	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize > 0)){			
        swap(vectorPuzzleTmp[zeroPositionTmp],vectorPuzzleTmp[zeroPositionTmp-problemSize]);
        zeroPositionTmp = zeroPositionTmp-problemSize;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }	
	// Right 	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if (( zeroPositionTmp % problemSize < problemSize-1)){			
        swap(vectorPuzzleTmp[zeroPositionTmp],vectorPuzzleTmp[zeroPositionTmp+1]);
        zeroPositionTmp = zeroPositionTmp+1;			
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_front(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }
	// Down	
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