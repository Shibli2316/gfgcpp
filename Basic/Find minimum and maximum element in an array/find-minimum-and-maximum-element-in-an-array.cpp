pair<long long, long long> getMinMax(long long a[], int n) {
    pair<long long, long long> answer;
        long maxNum = a[0];
        long minNum = a[0];
    for(int i = 0; i < n; i++){
        if(a[i] < minNum){
            minNum = a[i];
        }else if(a[i] > maxNum){
            maxNum = a[i];
        }
        answer.first = minNum;
        answer.second = maxNum;
    }
    
    
    return answer;
    
}
