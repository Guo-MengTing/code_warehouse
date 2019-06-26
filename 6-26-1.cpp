//https://www.nowcoder.com/practice/bd7f978302044eee894445e244c7eee6?tpId=13&tqId=11184&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int i=1;
        int count=0;
        int high=0,cur=0,low=0;
        while((n/i)!=0)
        {
            cur=(n/i)%10;
            high=n/(i*10);
            low=n-(n/i)*i;
            if(cur==0)
                count+=high*i;
            else if(cur==1)
                count+=high*i+low+1;
            else
                count+=(high+1)*i;
            i=i*10;
        }
        return count;
    }
};