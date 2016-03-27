#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <list>
#include <unistd.h>
#include <unordered_set>
#include <dephtFirstSearch.h>
#include <list>


int main() {	
	vector<int> initialState = {1,5,0,7,6,3,4,2,8};	
	initialize(initialState);
	dephtSearch();	
	return 0;
}