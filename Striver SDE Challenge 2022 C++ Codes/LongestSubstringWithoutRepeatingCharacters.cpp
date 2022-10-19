set<char> st;
int i=0,j=0,MS=0;
if(s.size()==0)
	return 0;
while(j<s.size()){
	if(st.count(s[j])==0){
		st.insert(s[j]);
		MS=max(MS, (int)st.size());
		j++;
                
	}
	else{
		st.erase(s[i]);
		i++;
	}
}
return MS;