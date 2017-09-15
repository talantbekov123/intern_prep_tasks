#include<iostream>
#include<vector>
#include<utility>
using namespace std;

class Turtle {
private:
	pair <int, int> currPosition;
	vector< vector<int> > board;
	int size;
	/* true right, false left*/
	bool direction;
	int axilary[2] = {-1,1};

public:
	Turtle(): size(0)
	{
		board.resize(20, vector<int>(20));
		currPosition = make_pair(0,0);
		direction = true;
	}

	// get current board size
	pair<int, int> getSize() {
		if(board.size()) 
		{
			return make_pair(board.size(),board[0].size());
		}
		return make_pair(0,0);		
	}

	// set direction rigth
	void setRight() {
		direction = true;
	}

	// set direction left
	void setLeft() {
		direction = false;
	}

	// move forvard
	void move(int n) {
		if(currPosition.first + (axilary[direction] * n) <= board.size() && currPosition.first + (axilary[direction] * n) >= 0)
			currPosition.first += (axilary[direction] * n);
	}

	pair<int, int> getCurr() {
		return currPosition;
	}

};

int main() {
	Turtle t;
	pair <int, int > pos = t.getCurr();
	cout<<pos.first<<endl;
	

	t.move(5);
	pos = t.getCurr();
	cout<<pos.first<<endl;

	t.setLeft();
	t.move(3);
	pos = t.getCurr();
	cout<<pos.first<<endl;

	return 0;
}