#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <ctime>
#include <sys/time.h>
//#define NDEBUG    //when all assert statements have to be disabled
#include <cassert>
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++) 
#define present(c,x) ((c).find(x) != (c).end()) 
#define ARRAY_SIZE(arr) (1[&arr]-arr)      
#define lld long long int
#define MOD 1000000007
#define PATTERN_LENGTH 3
#define TEXT_LENGTH 10000
using namespace std;




void failure_function(int *failure, string pattern)
{
    int len=pattern.length(),j=0,i;
	 failure[0]=0;
	 for(i=1;i<len;i++){
		 if(pattern[i]==pattern[j]){
			 j++;
			 failure[i]=j;
		 }
		 else if(j>0){
			 i--;
			 j=failure[j-1];
		 }
		 else 
			 failure[i] = 0;
	 }
	 for(i=0;i<len;i++)
		 cout<<i<<" "<<failure[i]<<endl;
}

void kmp(string text, string pattern)
{

    int tlen=text.length(), plen=pattern.length(),i,failure[plen],j;
    failure_function(failure, pattern);
    j=0;
    int count=0;
    for(i=0;i<tlen;i++)
    {
        count++;
        if(text[i]==pattern[j])
        {
            if(j==plen-1)
            {
                cout<<"pattern found at:"<<(i-j)<<endl;
                i=i-failure[j];
                j=0;
            }
			else
				j++; //continue forward with the pattern search
        }
        else
        {
            i=i-failure[j];
            j=0;
        }
    }
    cout<<"number of executions:"<<count<<endl;
}

int main()
{
    srand((unsigned int)time(NULL));
    string text="", pattern="";
    int i;/*
    for(i=0;i<TEXT_LENGTH;i++)
        text=text+char(rand()%10+'0');
    for(i=0;i<PATTERN_LENGTH;i++)
        pattern=pattern+char(rand()%10+'0');*/
    cin>>text>>pattern;
    cout<<text<<endl<<endl<<pattern<<endl;
    kmp(text, pattern);
}
