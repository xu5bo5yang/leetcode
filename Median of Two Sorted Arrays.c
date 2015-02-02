class Solution {
public:
    int even(int x){
        if(2*(x/2)==x) return 1;
        else return 0;
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n) {
	    int ai=0,bj=0;
	    int temp=0;
	    if(m==0&&n==0) return 0;
	    else if(m==0){
    	    if(even(n)) return (B[n/2]+B[n/2-1])/2.0;
    	    else return B[n/2];
    	}
    	else if(n==0){
    	    if(even(m)) return (A[m/2]+A[m/2-1])/2.0;
    	    else return A[m/2];
    	}
    	if(even(m+n)){
    		while((ai+bj)<=((m+n)/2-1)){
    			if(ai==m){
    			    temp=B[bj];
    			    bj++;
    			}
    			else if(bj==n){
    			    temp=A[ai];
    			    ai++;
    			}
    			else{
    				if(A[ai]>=B[bj]){
    					temp=B[bj];
    					bj++;
    				}
    				else{
    					temp=A[ai];
    					ai++;
    				}
    			}
    		}
    		if(ai==m) return (B[bj]+temp)/2.0;
    		else if(bj==n) return (A[ai]+temp)/2.0;
    		else if(A[ai]<=B[bj]) return (A[ai]+temp)/2.0;
    		else return (B[bj]+temp)/2.0;
    	}
    	else{
    		while((ai+bj)<((m+n-1)/2)){
    			if(ai==m){
    			    temp=B[bj];
    			    bj++;
    			}
    			else if(bj==n){
    			    temp=A[ai];
    			    ai++;
    			}
    			else{
    				if(A[ai]>=B[bj]){
    					temp=B[bj];
    					bj++;
    				}
    				else{
    					temp=A[ai];
    					ai++;
    				}
    			}
    		}
    		if(ai==m) return B[bj];
    		else if(bj==n) return A[ai];
    		else if(A[ai]<=B[bj]) return A[ai];
    		else return B[bj];
    	}
    }
};