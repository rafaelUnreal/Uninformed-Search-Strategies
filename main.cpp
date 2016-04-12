#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <unistd.h>
#include <unordered_set>
#include <Node.h>
#include <iterativeDephtFirstSearch.h>
#include <list>


//void createParent(Node * childNode, Node * parentNode){
//	childNode->parent = parentNode;
//}


int main() {	
	//You can call any algorithm just including the respective file
	//for example, include the breadthFirstSearch.h
	//then you have to create the initialState, that is a vector;
	/*
	 * 	 
		vector<int> initialState = {6,8,5,2,7,0,1,4,3};	
	 * 
	after that, you have to  call the initialize procedure;
		initialize(initialState);
	 *
	 and finally you must call the procedure that makes refference to the algorithm
	 it can be:
	  * breadthSearch();
	  * dephtSearch();
	  * iterativeDephtSearch();
	  
	  * or
	  
	  * dephtSearchNode();
	*/
	
	/*
	 * For using the algorithm with node you have to:
	 * 
	 * 1. Create a node and initialize it.
	 * Node initialState.
	 * initialState.initializeState({8,1,6,0,2,5,4,3,7});
	 * 2. Initialize the algorithm.
	 * initialize(initialState);
	 * 3. Call the procedure that makes refference to the algorithm
	 * dephtSearchNode();
	 * */
		
	//Example using the iterativeDephtSearch;
	vector<int> initialState = {6,8,5,2,7,0,1,4,3};	
	initialize(initialState);
	iterativeDephtSearch();
	
	
	
	
	
	
	
		
	return 0;
}