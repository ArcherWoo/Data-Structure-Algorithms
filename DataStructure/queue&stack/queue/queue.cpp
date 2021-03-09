#include <iostream>

class MyQueue
{
	private:
		// store elements
		vector<int> data;
		// a pointer to indicate the start position
		int p_start;

	public:
		MyQueue() {p_start = 0;}

		bool enQueue(int x){
			data.push_back(x);
			return true;
		}

}