// Apporach 1 
// Time Complexity : O(n) ...... N is total number of emplpoyees
// Space Complexity : O(n) .....
// Did this code successfully run on Leetcode : Yes
// Any problem you faced while coding this :
//
/*
Leetcode : https://leetcode.com/problems/employee-importance/description/

You have a data structure of employee information, including the employee's unique ID, importance value, and direct subordinates' IDs.

You are given an array of employees employees where:

employees[i].id is the ID of the ith employee.
employees[i].importance is the importance value of the ith employee.
employees[i].subordinates is a list of the IDs of the direct subordinates of the ith employee.
Given an integer id that represents an employee's ID, return the total importance value of this employee and all their direct and indirect subordinates.

*/


/**
 * Approach 1 : BFS
 * 
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int, Employee*>hMap;

        //Store id ---> employee pointer in hash map, so that
        // pointer can be accessed easily using id.
        for(auto employee : employees){
            hMap[employee->id] = employee;
        }

        // Queue is used to store the 
        queue<Employee*>q;
        q.push(hMap[id]);
        int result = 0;

        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < q.size(); i++){
                Employee* temp = q.front();
                q.pop();
                result += temp->importance;

                for(int j=0; j<temp->subordinates.size(); j++){
                    q.push(hMap[temp->subordinates[j]]);
                }
            }
        }
        return result;
    }
};