#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <unistd.h>
#include <unordered_set>
#include <breadthFirstSearch.h>


int main() {	
	vector<int> initialState = {6,3,8,0,2,4,1,5,7};	
	initialize(initialState);
	breadthSearch();	
	return 0;
}