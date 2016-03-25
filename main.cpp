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
#include <list>


int main() {	
	vector<int> initialState = {1,2,3,4,0,5,6,7,8};	
	initialize(initialState);
	breadthSearch();	
	return 0;
}