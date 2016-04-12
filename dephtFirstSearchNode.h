#define problemSize 3
using namespace std;

//Here are the nodes that reffers the goal state, the set of visited nodes and a list of 
//nodes to visit. Here also is the current node. This means the state that will change
//when the algorithm runs.
Node goalState;
set<Node> visitedStates;
list<Node> toVisitStates;
Node currentState;


//We don't need to implement the showState. I put a displayState into the Node.
void showState(){}

//The initialize procedure put the first state into the visited states list and also 
//feeds the goalState node.
void initialize(Node state){	
	visitedStates.insert(state);	
	goalState.initializeState({1,2,3,4,5,6,7,8,0});
}

//This procedure just returns a boolean that answer if it's or not a goal state.
bool isGoalState(Node current){
	for(int i = 0; i < current.state.size(); i++){
		if (current.state[i] != goalState.state[i])
			return false;
	}
	return true;
}

//This function returns the zero element's position
int getZeroPosition(Node current){
	for(int i = 0; i < current.state.size(); i++){
		if(current.state[i] == 0){
			return i;
		}
	}
	return 0;
}

//This procedure point the childNode to his Parent
void pointParent(Node * childNode, Node * parentNode){
	childNode->parent = parentNode;
}

//The move function recieve two parameters, the current state(a node) and the zero 
//position of that state. The function also has 4 if statement which generate
//the children nodes.
void moveFunction(Node vectorPuzzle, int zeroPosition){ 


	// Left
	Node vectorPuzzleTmp = vectorPuzzle;
	int zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp % problemSize > 0)){						
        swap(vectorPuzzleTmp.state[zeroPositionTmp], vectorPuzzleTmp.state[zeroPositionTmp-1]);		
        zeroPositionTmp = zeroPositionTmp-1;
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end())){			
			toVisitStates.push_back(vectorPuzzleTmp);
			pointParent(&vectorPuzzleTmp, &vectorPuzzle);
		}				
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);			
    }	

	// Up
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize > 0)){		
        swap(vectorPuzzleTmp.state[zeroPositionTmp],vectorPuzzleTmp.state[zeroPositionTmp-problemSize]);
        zeroPositionTmp = zeroPositionTmp-problemSize;		
		
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end())){			
			toVisitStates.push_back(vectorPuzzleTmp);
			pointParent(&vectorPuzzleTmp, &vectorPuzzle);
		}						
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }	
		
	// Right
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if (( zeroPositionTmp % problemSize < problemSize-1)){			
        swap(vectorPuzzleTmp.state[zeroPositionTmp],vectorPuzzleTmp.state[zeroPositionTmp+1]);
        zeroPositionTmp = zeroPositionTmp+1;					
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end())){			
			toVisitStates.push_back(vectorPuzzleTmp);
			pointParent(&vectorPuzzleTmp, &vectorPuzzle);
		}				
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);	
    }
	// Down
	vectorPuzzleTmp = vectorPuzzle;
	zeroPositionTmp = zeroPosition;	
    if ((zeroPositionTmp/problemSize < problemSize-1)){
        swap(vectorPuzzleTmp.state[zeroPositionTmp], vectorPuzzleTmp.state[zeroPositionTmp+problemSize]);
        zeroPositionTmp = zeroPositionTmp + problemSize; 
		if(!(std::find(visitedStates.begin(), visitedStates.end(), vectorPuzzleTmp) != visitedStates.end())){			
			toVisitStates.push_back(vectorPuzzleTmp);
			pointParent(&vectorPuzzleTmp, &vectorPuzzle);
		}						
		visitedStates.insert(visitedStates.begin(),vectorPuzzleTmp);
    }  
}

//This procedure just execute a while loop till the visit states
//being empty or the goal state being found.
void dephtSearchNode(){
	int numberOfIterations = 0;
	toVisitStates.push_back(*visitedStates.begin());
// && currentDepth < maxDepth
	while(!toVisitStates.empty()){		
		currentState = *toVisitStates.crbegin();
		toVisitStates.pop_back();	
		if(isGoalState(currentState)){
			cout << endl;
			cout << numberOfIterations << endl;		
			currentState.displayState();
			printf("\nGoal State\n");			
			return;
		}else{					
			cout << endl;
			cout << numberOfIterations << endl;			
			currentState.displayState();
			moveFunction(currentState, getZeroPosition(currentState));					
		}
		numberOfIterations++;
	}		
}