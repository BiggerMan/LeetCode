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
		int maxProfit3(vector<int>& prices)//buy and sell as many as you can
		{
			int ret=0;
			int oldLen = prices.size();
			if(oldLen<=1)
				return 0;
			for(int i=1;i<oldLen;i++)
			{
				if(prices[i]-prices[i-1]>0)
					ret += prices[i]-prices[i-1];
			}

			return ret;
		}
		int maxProfit4(vector<int>& prices)//buy and sell two stocks and maxprofit
		{
			const int len = prices.size();
			if( len <= 1)
				return 0;
			int minPrice = prices[0];
			int maxProfit = prices[1] - prices[0]; 
			int *maxFromHead=new int[len];
			maxFromHead[0]=0;
			//from left to right
			for(int i=1;i<len;i++)
			{
				minPrice = min(minPrice, prices[i]);
				maxProfit = max(maxProfit, prices[i]-minPrice);
				maxFromHead[i] = maxProfit;
			}
			int maxPrice = prices[len-1];
			maxProfit = 0;
			int res=0;//return sum
			for(int i=len-2;i>=0;i--)
			{
				maxPrice = max(maxPrice, prices[i]);
				maxProfit = max(maxProfit, maxPrice-prices[i]);
				res = max(res, maxProfit+maxFromHead[i]);
			}

			return res;
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
	cout<< "result1:" << s.maxProfit1(prices) <<endl;
	cout<< "result2:" << s.maxProfit2(prices) <<endl;
	cout<< "result3:" << s.maxProfit3(prices) <<endl;
	cout<< "result4:" << s.maxProfit4(prices) <<endl;

	return 0;
}
