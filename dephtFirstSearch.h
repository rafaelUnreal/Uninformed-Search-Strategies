#define problemSize 3
using namespace std;

//Here are the vector that reffers the goal state, the set of visited states and a list of 
//states to visit. Here also is the current state. This means the state that will change
//when the algorithm runs.
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

//This procedure shows the state passed by parameter
void showState(vector<int> state){
	cout << endl;
	for(int i = 0; i < state.size(); i++){
		cout << state[i] << " ";
	}
}

//This procedure put the first state into the visitedStates set for being used 
//when the algorithm starts
void initialize(vector<int> state){	
	visitedStates.insert(state);	
}

//The move function recieve two parameters, the current state and the zero 
//position of that state. The function also has 4 if statement which generate
//the children nodes.
void moveFunction(vector<int> vectorPuzzle, int zeroPosition){  		
	// Left	
	vector<int> vectorPuzzleTmp = vectorPuzzle;
	int zeroPositionTmp = zeroPosition;
    if ((zeroPositionTmp % problemSize > 0)){		
        swap(vectorPuzzleTmp[zeroPositionTmp], vectorPuzzleTmp[zeroPositionTmp-1]);
        zeroPositionTmp = zeroPositionTmp-1;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_back(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);			
    }
	// Up	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize > 0)){			
        swap(vectorPuzzleTmp[zeroPositionTmp],vectorPuzzleTmp[zeroPositionTmp-problemSize]);
        zeroPositionTmp = zeroPositionTmp-problemSize;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_back(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }	
	// Right 	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if (( zeroPositionTmp % problemSize < problemSize-1)){			
        swap(vectorPuzzleTmp[zeroPositionTmp],vectorPuzzleTmp[zeroPositionTmp+1]);
        zeroPositionTmp = zeroPositionTmp+1;			
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_back(vectorPuzzleTmp);	
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }
	// Down	
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize < problemSize-1)){
        swap(vectorPuzzleTmp[zeroPositionTmp], vectorPuzzleTmp[zeroPositionTmp+problemSize]);
        zeroPositionTmp = zeroPositionTmp + problemSize; 
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end()))
			toVisitStates.push_back(vectorPuzzleTmp);		
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);
    }  
}

//This function returns a boolean that answers if it's or not
bool isGoalState(vector<int> state){
	for(int i = 0; i < state.size(); i++){
		if (state[i] != goalState[i])
			return false;
	}
	return true;
}

//This function returns the zero element's position
int getZeroPosition(vector<int> state){
	for(int i = 0; i < state.size(); i++){
		if(state[i] == 0)
			return i;
	}
	return 1;
}

//This procedure just execute a while loop till the visit states
//being empty or the goal state being found.
void dephtSearch(){
	int numberOfIterations = 0;
	toVisitStates.push_back(*visitedStates.begin());
// && currentDepth < maxDepth
	while(!toVisitStates.empty()){		
		currentState = *toVisitStates.crbegin();
		toVisitStates.pop_back();		
		if(isGoalState(currentState)){
			cout << endl;
			showState(currentState);
			printf("\nGoal State\n");			
			return;
		}else{					
			cout << endl;
			cout << numberOfIterations;			
			//showState(currentState);			
			moveFunction(currentState, getZeroPosition(currentState));					
		}
		numberOfIterations++;
	}		
}