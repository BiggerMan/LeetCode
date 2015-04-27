#include <iostream>
#include <stack>
#include <stdint.h>
#include <math.h>

using namespace std;

class Solution {
	public:
		uint32_t reverseBits(uint32_t n) {
			stack<int> stk;
			int i=32;
			while(i>0)
			{
				stk.push(n&1);
				n >>= 1;
				i--;
			}
			int count=0;
			uint32_t result=0;
			while(!stk.empty())
			{
				int i = stk.top();
				stk.pop();
				if(i)
					result += pow(2,count);
				count++;
			}

			return result;
		}
};

int main()
{
	int n=1; 
	Solution s;
	cout << "result:" <<s.reverseBits(n) <<endl;
}
