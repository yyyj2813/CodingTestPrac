using namespace std;

long long mul(int count){
    return (long long)count*(count+1)/2; 
}
long long solution(int price, int money, int count)
{
    long long answer = 0 ;
    long long needed= (long long) price*mul(count);
    answer = needed-money;
    if(answer <= 0) return 0; 
    return answer;
}