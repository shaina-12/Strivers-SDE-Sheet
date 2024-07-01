// taken reference from https://www.interviewbit.com/problems/nearest-smaller-element/discussion/p/easy-c-solution-using-stack-simple-explanation/515307/993/
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> sol;
    stack<int> s;
    for(int i=0;i<A.size();i++){
        while(!s.empty() && s.top()>=A[i]){
            s.pop();
        }
        sol.push_back(s.empty() ? -1 : s.top());
        s.push(A[i]);
    }
    return sol;
}
