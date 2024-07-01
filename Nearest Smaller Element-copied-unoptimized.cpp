// taken reference from ChatGPT and CSE 525 Introduction to Graduate Algorithms Homework Question 4, Monsoon Semester 2023, done by Shaina Mehta at IIIT Delhi
void helper(vector<int> nums2, int si, int ei, vector<int> &nge){
    if(si>=ei){
        return;
    }
    int mid = (si+ei)/2;
    helper(nums2,si,mid,nge);
    helper(nums2,mid+1,ei,nge);
    int i=mid, j=mid+1;
    while(i>=si && j<=ei){
        if(nge[j]==-1){
            if(nums2[j]>nums2[i]){
                nge[j] = nums2[i];
                j++;
            }
            else{
                i--;
            }
        }
        else{
            j++;
        }
    }
    return;
}
vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> nse;
    if(A.size()==1){
        nse.push_back(-1);
        return nse;
    }
    for(int i=0;i<A.size();i++){
        nse.push_back(-1);
    }
    helper(A,0,A.size()-1,nse);
    return nse;
}
