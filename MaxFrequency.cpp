/*You are given an array nums consisting of positive integers.

Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

The frequency of an element is the number of occurrences of that element in the array.

 */
#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto i : nums) {
            mp[i]++;
        }
        int z = 0;
        for (auto i : mp) {
            z = max(z, i.second);
        }
        int x=0;
        for (auto i : mp) {
            if(z==i.second) x++;
        }
        return x * z;
    }
};
