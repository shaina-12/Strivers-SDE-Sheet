#include <bits/stdc++.h>
// taken reference from discussion forums of Code 360 by Coding Ninjas
void helper(stack<int> &s, stack<int> &s2, stack<int> &s3){
	if(s.empty()){
		return;
	}
	while(!s2.empty() && s2.top() < s.top()){
		s3.push(s2.top());
        s2.pop();
    }
    if(s2.empty() || s2.top() >= s.top()){
		s2.push(s.top());
        s.pop();
    }
    while(!s3.empty()){
		s2.push(s3.top());
        s3.pop();
    }
	helper(s,s2,s3);
} 
void sortStack(stack<int> &stack)
{
	// Write your code here
	std::stack<int> s2, s3;
	helper(stack,s2,s3);
   	// while(!s.empty()){
	// 	while(!s2.empty() && s2.top() < s.top()){
	// 		s3.push(s2.top());
    //        	s2.pop();
    // 	}
    // 	if(s2.empty() || s2.top() >= s.top()){
	// 		s2.push(s.top());
    //     	s.pop();
    // 	}
    // 	while(!s3.empty()){
	// 		s2.push(s3.top());
    //     	s3.pop();
    // 	}
   	// }
   	while(!s2.empty()){
		stack.push(s2.top());
       	s2.pop();
   	}
}
