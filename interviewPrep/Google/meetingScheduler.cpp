vector <int> meetingScheduler(vector <vector <int>> &slot1,vector <vector <int>> &slot2, int duration){
    map <int,int> M;
    for(auto i:slot1){
        M[i[0]]++;
        M[i[1]]--;
    }
    for(auto i:slot2){
        M[i[0]]++;
        M[i[1]]--;
    }
    vector <int> ans;
    int count = 0,l=-1;
    for(auto i:M){
        count+=i.second;
        if(l!=-1){
            int diff = i.first-l;
            if(diff>=duration){
                ans.push_back(l);
                ans.push_back(l+duration);
                return ans;
            }else{
                l = -1;
            }
        }
        if(count==2){
            l = i.first;
        }
    }
    return ans;
}
void print(vector <int>& ans){
    for(auto i:ans)
        cout << i << " ";
    cout << endl;
}
int main() {
    vector <vector <int>> slots1 = {{10,50},{60,120},{140,210}}, slots2 = {{0,15},{60,70}}; int duration1 = 8;
    vector <int> ans1 = meetingScheduler(slots1,slots2,duration1);
    print(ans1);
    vector <vector <int>> slots3 = {{10,50},{60,120},{140,210}}, slots4 = {{0,15},{60,70}}; int duration2 = 12;
    vector <int> ans2 = meetingScheduler(slots3,slots4,duration2);
    print(ans2);
    
}