class StockSpanner {
    stack<int> s1;
    stack<int> s2;
public:
    StockSpanner() {
    
    }
    
    int next(int price) {
        if(s1.empty()){
            s1.push(price);
            return 1;
        }
        int count = 1;
        //cout<<s1.top()<<endl;
        while(!s1.empty() && s1.top() <= price){
            //cout<<"hi"<<endl;
            s2.push(s1.top());
            s1.pop();
            count++;
        }
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        s1.push(price);
        return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
