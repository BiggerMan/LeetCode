#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
	public:
		int maxProfit1(vector<int>& prices)//dp[i] = max{dp[i-1],dp[i]-minprices},minprice = min{prices[0],prices[1]...prices[i-1]}
		{
			int i,j,k;
			int oldLen = prices.size();
			if(oldLen<=1)
				return 0;
			int minPrice = prices[0];//start from lastest day
			int ret=0;

			for(i=1;i<oldLen;i++)
			{
				minPrice = min(minPrice, prices[i]);
				ret = max(ret, prices[i]-minPrice);
			}
			return ret;
		}

		int maxProfit2(vector<int>& prices)//prices[3]-prices[1] = prices[3]-prices[2]+prices[2]-prices[1];
		{
			int ret=0;
			int cursum=0;
			int oldLen = prices.size();
			if(oldLen<=1)
				return 0;
			for(int i=1;i<oldLen;i++)
			{
				if(cursum <=0)
					cursum = prices[i] - prices[i-1];
				else
					cursum += prices[i] - prices[i-1];//record max cursum
				ret = max(cursum,ret);
			}

			return ret;
		}
};

int main()
{
	Solution s;
	vector<int> prices;
	prices.push_back(1);
	prices.push_back(3);
	prices.push_back(20);
	prices.push_back(-1);
	prices.push_back(7);
	prices.push_back(8);
	cout<< "result:" << s.maxProfit1(prices) <<endl;
	cout<< "result:" << s.maxProfit2(prices) <<endl;

	return 0;
}
