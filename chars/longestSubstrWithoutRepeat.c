#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return a>b?a:b;
}
int lenOfLongestSubStr(char *s)
{
	int map[256];
	int len = strlen(s);
	memset(map,0,sizeof(int)*256);
	if(len<=1)
		return len;

	int i=0;
	int maxLen=0;
	int head=0;
	while(i<len)
	{
		if(map[s[i]]==1)
		{
			maxLen=max(maxLen,i-head);
			while(s[head]!=s[i])//find last s[i] == current_s[i],and restart from its next char
			{
				map[s[head]]=0;
				head++;
			}
			head++;//try from its next char
			i++;//i always forward
		}
		else
		{
			map[s[i]]=1;
			i++;
		}
	}
	maxLen=max(maxLen,i-head);
	return (maxLen);
}
	
int main()
{
	char str[]="abcabcdef";//expected 6
	char str2[]="aa";//expected 1
	char *str3="dvdf";//expected 3:vdf
	char *str4="pwwkew";//expected 3:wke
	printf("result:%d\n",lenOfLongestSubStr(str));
	printf("result:%d\n",lenOfLongestSubStr(str2));
	printf("result:%d\n",lenOfLongestSubStr(str3));
	printf("result:%d\n",lenOfLongestSubStr(str4));

	return 0;
}
