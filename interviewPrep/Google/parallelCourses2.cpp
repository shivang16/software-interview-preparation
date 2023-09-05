// https://leetcode.com/problems/parallel-courses-ii/
/**
this is a really good problem !!

	in one semester we can do at most k courses, and for each course we have picked, we should
	have completed its prerequisites in the previous semesters
	so we need to find the minimum semesters in which we can complete all the courses

	currently, we can chose those courses whose indegree is 0 (because its prerequisites have been completed)

	so this might seem like topological sorting

	but it is not the case

	currently in the queue, lets say have M courses (M > k), and the number of semesters required would actually depend
	upon which k courses we chose to do in this semester, so we need dp for this
	our dp state will be a single bitMask, which would tell us which all courses have been taken till now

	first job is to identify which all courses are available to us

	A course i will be available only if :
		-> the i'th bit in the bitMask, is 0 (means this course is not taken before)
		-> all the prerequisites of this course are done

	how do we check for the second condition ?
	a course's prerequisites are complete only if its indegree is 0 (indegree will be calculated, ignoring the
	edges from those nodes which are already taken). means while calculating the indegree array, we will only
	consider those nodes which have not been taken in any of the previous semesters (means i'th bit in the bitMask is 0)

	so now our job is to figure out which courses are available to us (we again make some kind of bitMask for this 😅)

	for each node (or course) which has not been taken, visit all its neighbours and do indegree[nbr]++;
	so all those untouched nodes whose indegree is 0, can be taken now

	in case the number of available courses are less than k, we take all of them
	(it is quite obvious, there are some courses all of which we are allowed to take this semester, it would really not make sense not
	to take all of them)

	in case the number of available courses, (call it M) are more than k, there are  options McK options and we need to consider all of them
	we generate all the submasks, and take those who have k set bits

*/
class Solution {
public:
	int N , K;
	// vector<int> graph[15];
	vector<vector<int>> graph;
	int indegree[15];
	int finalBitMask;
	int dp[(1 << 15) + 1];

	int solve(int bitMask) {
		// cout << "something here" ;
		if (bitMask == finalBitMask) return 0;
		if (dp[bitMask] != -1) return dp[bitMask];

		memset(indegree, 0, sizeof(indegree));

		for (int i = 0; i < N; i++) {

		// if that guy is not taken till now, then this will contribute to the indegree
		if (!(bitMask & (1 << i))) {
			for (int v : graph[i]) {
				indegree[v]++;
			}
		}
	}

	int availMask = 0;

	for (int i = 0; i < N; i++) {
		if (!(bitMask & (1 << i)) && indegree[i] == 0) availMask |= (1 << i);
	}


	// before doing this check for the case where number of available courses are  <= K
	int curAns = N + 1;
	if (__builtin_popcount(availMask) < K) {
		curAns = min(curAns, 1 + solve(bitMask | availMask));
	}

	// else if the number of available courses are greater than k, do this
	else {


		// generating the submasks of a given bitMask 
		for (int subMask = availMask; subMask > 0; subMask = (subMask - 1) & availMask) {
			if (__builtin_popcount(subMask) == K) {
				curAns = min(curAns, 1 + solve(bitMask | subMask));
			}

		}

	}

	return dp[bitMask] = curAns;


}



int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
	N = n;
	K = k;
	graph.resize(N);

	for (auto &e : relations) {
		e[0]--;
		e[1]--;
		graph[e[0]].push_back(e[1]);
	}

	memset(dp, -1, sizeof(dp));
	finalBitMask = ((1 << N) - 1);
	return solve(0);

	}
};