/**
* @author Hansheng Zhang
*/
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
	int n = words.size();
	int i =0;
	vector<vector<string> > rlts;
	vector<int> lens;
	while (i<n){
	    vector<string> vs;
	    vs.push_back(words[i]);
	    int curLen = words[i].length();
	    i++;
	    while (i<n){
		int tryLen = curLen + words[i].length() + 1; 
		if ( tryLen <= L ){
		    vs.push_back(words[i]);
		    curLen = tryLen;
		    i++;
		}
		else break;
	    }
	    lens.push_back(curLen);
	    rlts.push_back(vs);
	}
	vector<string> rlt;
	int size = rlts.size();
	for (i=0; i<size-1; i++){
	    vector<string> & vs = rlts[i];
	    int num = vs.size();
	    string str = "";
	    if (num==1){
		str = vs[0];
		for (int j=lens[i]; j<L; j++)
		    str += " ";
	    }
	    else {
		int moreBlanks = L-lens[i];
		int allAdd = moreBlanks / (num-1);
		int offset = moreBlanks % (num-1);
		for (int k=0; k<num; k++){
		    int numBlacks = 1+allAdd;
		    if (k==num-1)
			numBlacks=0;
		    else if (k<=offset-1)
			numBlacks++;
		    str += vs[k];
		    for (int j=0; j<numBlacks; j++)
			str+= ' ';
		}
	    }
	    lens[i] = L;
	    rlt.push_back(str);
	}
	if (size>0){
	    string str="";
	    for (int j=0; j<rlts[size-1].size(); j++){
		str += rlts[size-1][j];
		if (j<rlts[size-1].size()-1)
		    str += ' ';
	    }
	    for (int j=lens[size-1]; j<L; j++)
		str += ' ';
	    rlt.push_back(str);
	}
	return rlt;
    }
};
