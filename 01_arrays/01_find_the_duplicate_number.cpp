// problem link -> https://leetcode.com/problems/find-the-duplicate-number/

/*
1. brute -> use two loops

2. better -> sort the array and traverse and find the duplicate

3. best -> use slow and fast pointer method of linked list.
-> using slow and fast pointer
-> there is a duplicate so cycle will exist
-> slow will move one step while fast will move two steps forward
-> the moment when they first collide again move fast to starting position
-> now both fast and slow will move one step forward
-> the moment they collide again it is the duplicate number

*/

int findDuplicate(vector<int>& nums){

    int slow = nums[0];
    int fast = nums[0];

    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);

    fast = nums[0];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}



