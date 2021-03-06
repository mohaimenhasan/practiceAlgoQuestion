#include <iostream>
#include <string>
#include <vector>
#include <bitset>

/*
 * Basic Idea: Given array [a,b,c,d]
 * Iterate twice. First time, store all the values [1, a, ab, abc].
 * Second Time, reverse order and find values [1, d, cd, bcd]. 
 * For output array output[end-n], it will be first_list[begin+n] * second_list[end-n]
 * This is a good method for anything that requires calculating everything other than itself in an array
 */

using namespace std;

vector<int> prod_except_self(vector<int> &nums){
    vector<int> left_prods;
    int leftProd = 1;
    left_prods.push_back(leftProd);
    for (unsigned i = 0; i<nums.size()-1; i++){
        leftProd *= nums[i];
        left_prods.push_back(leftProd);
    }
    vector<int> output(nums.size());
    int rightProd = 1;
    for (unsigned i = nums.size(); i-- > 0; ){
        output[i] = (rightProd * left_prods[i]);
        rightProd *= nums[i];
    }
    return output;
}

int main(){
        vector<int> nums = {1,2,3,4};
        vector<int> out = prod_except_self(nums);
        for (auto val: out){
            cout<<val<<endl;
        }
        return 0;
}

