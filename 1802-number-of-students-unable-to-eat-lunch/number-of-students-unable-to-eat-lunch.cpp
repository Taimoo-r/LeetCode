class Solution {
public:
    void Delete(vector<int>& st,int i){
        st.erase(st.begin()+i);
    }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int i = 0; find(students.begin(), students.end(), sandwiches[i])!=students.end();){
            if(students[i]!=sandwiches[i]){
                // students.resize(students.size()+1);
                students.push_back(students[i]);
            }
            else
            sandwiches.erase(sandwiches.begin());
            students.erase(students.begin());
            
        }
        return students.size();
        
    }
};