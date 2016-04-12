
using namespace std;
 
class Node
{
private:		
			
			
public:
		vector<int> state;	
		
		Node * parent;
		void displayState() {
			for(int i = 0; i < state.size(); i++){
				cout << state[i] << " ";
			}
			cout << endl;
		}
		
		void initializeState(vector<int> tmp){
			state = tmp;
		}
		
	friend bool operator< (const Node &left, const Node &right);

};	

bool operator< (const Node &left, const Node &right)
{
    return left.state < right.state;
}

bool operator==(const Node& left, const Node& right)
{
    return left.state == right.state;
}