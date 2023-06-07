#include <iostream>
using namespace std;

int main() {
	int i;
	cin>>i;
	while(i--){
	    int r,c,k,s,p;
	    cin>>r>>c;
	    int a[r][c];
	    for(int x=0;x<r;x++){
	        for(int j=0;j<c;j++){
	            cin>>a[r][c];
	        }
	    }
	    k=a[r-1][0];
	    s=r-1;
	    p=0;
	    int count=a[r-1][0];
	    while(s!=0 & p!=c-1){
	        if(a[s-1][p]<a[s][p+1]){
	            k=a[s-1][p];
	            count+=k;
	            s--;
	        }if(a[s][p+1]<a[s-1][p]){
	            k=a[s][p+1];
	            count+=k;
	            p++;
	        }if(a[s][p+1]==-1 & a[s-1][p]==-1){
	            cout<<-1<<endl;
	            break;
	        }
	    }
	    cout<<count<<endl;
	    
	    
	}
	return 0;
}