vector <int> ans;
void getSum(vector <int> &num,int i,int sum){
	if(i<0){
		ans.push_back(sum);
		return;
	}
	getSum(num,i-1,sum);
	getSum(num,i-1,sum+num[i]);
}
vector<int> subsetSum(vector<int> &num){
	sort(num.begin(),num.end());
	int sum = 0;
	getSum(num,num.size()-1,sum);
	sort(ans.begin(),ans.end());
	return ans;
	// Write your code here.	
}