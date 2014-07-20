/*
this version of code is hard to understand.
but the solution is straightforward
1. use depth first search
2. preprocessing: find all pairs of i<j which s[i...j] is palindromic
3. you may need to store the partial result
@author Hansheng Zhang (http://zhanghs.com)
*/
class Solution {
public:
	bool isPal(const char * p, const char * q){
		while (p<q){
			if (*p != *q)
				return false;
			p++; q--;
		}
		return true;
	}
    vector<vector<string> > partition(string s) {
		int n = s.length();
		if (n<=0)
			return vector<vector<string>>(1,vector<string>(1,""));
		const char * head = s.c_str();
		const char * end = head + n-1;
		const char * p = head;
		// the idea is to store the ends of each part instead of substrings
		vector<vector<vector<const char *> > > ePos(n+1, vector<vector<const char*> >());
		ePos[0].push_back(vector<const char*>());
		while ((*p) != '\0'){
			const char * q = head;
			vector<vector<const char*> >& cur = ePos[p-head+1];
			while (q<=p){
				if (! isPal(q,p)){
					q++;
					continue;
				}
				vector<vector<const char*> >& before = ePos[q-head];
				vector<vector<const char*> >::iterator vvci;
				for (vvci = before.begin(); vvci != before.end(); vvci++){
					vector<const char*> vc = *vvci;
					vc.push_back(p);
					cur.push_back(vc);
				}
				q++;
			}
			p++;
		}
		vector<vector<string>> rlt;
		for (vector<vector<const char*> >::iterator vvci = ePos[n].begin(); vvci!=ePos[n].end();vvci++){
			vector<string> sol;
			const char * cItr = head;
			for (vector<const char*>::iterator vci=(*vvci).begin(); vci!=(*vvci).end(); vci++){
				string tmp = "";
				while (true){
					tmp += *cItr;
					if (cItr == *vci)
						break;
					cItr++;
				}
				cItr++;
				sol.push_back(tmp);
			}
			rlt.push_back(sol);
		}
		return rlt;
    }
};
