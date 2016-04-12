#define problemSize 3
using namespace std;

//Here are the vector that reffers the goal state, the set of visited states and a list of 
//states to visit. Here also is the current state. This means the state that will change
//when the algorithm runs. 
vector<int> goalState = {1,2,3,4,5,6,7,8,0};
set<vector<int> > visitedStates;
list<vector<int> > toVisitStates;
vector<int> currentState;
vector <int> initial;

//Here we have the depht factor and the child depth factor
int depthFactor = 0;
int childDepht = 0;

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

//This procedure just show the state passed by parameter
void showState(vector<int> state){
	cout << endl;
	for(int i = 0; i < state.size(); i++){
		cout << state[i] << " ";
	}
}

//This procedure put the first state into the visitedStates set for being used 
//when the algorithm starts
void initialize(vector<int> state){	
	initial = state;
	visitedStates.insert(state);	
}

//This procedure put the first state into the visitedStates set again. For being
//used when the depth factor is incremented
void reinItialize(){
	visitedStates.insert(initial);	
}

//The move function recieve two parameters, the current state and the zero 
//position of that state. The function also has 4 if statement which generate
//the children nodes.
//Pay attention, because in this function we have an aditional IF that controls
//depth factor's flow 
void moveFunction(vector<int> vectorPuzzle, int zeroPosition){  
	if(childDepht != depthFactor){
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
		childDepht++;
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
void iterativeDephtSearch(){
	int numberOfIterations = 0;
	toVisitStates.push_back(*visitedStates.begin());
// && currentDepth < maxDepth
	while(!toVisitStates.empty()){				
		currentState = *toVisitStates.crbegin();
		toVisitStates.pop_back();		
		sleep(1);
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
		//this if just increase the depth factor and clear the list and set
		if(childDepht == depthFactor){
			toVisitStates.clear();
			visitedStates.clear();
			reinItialize();
			toVisitStates.push_back(*visitedStates.begin());
			depthFactor++;
			childDepht = 0;
			numberOfIterations = 0;
			cout << endl;
		}
		numberOfIterations++;
	}		
}