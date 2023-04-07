void multiply(int mulval,vector<int> &nums){
        long long int carry=0;
        for(auto i=nums.rbegin();i!=nums.rend();i++){
            long long int mul= mulval * (*i) +carry;
            carry=mul/10;
            *i = mul%10;
        }
        while(carry!=0){
            nums.insert(nums.begin(),carry);
            carry/=10;
        }
    }
    vector<int> factorial(int N){
        vector<int>res;
        res.push_back(1);
        for(int i=2;i<=N;i++)
            multiply(i,res);
        return res;
    }