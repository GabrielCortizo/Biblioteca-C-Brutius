int gcd(int a,int b){
	if(b==0) return a;
	return gcd(b,a%b);
}
int getCount(PT a, PT b){
	int ax=a.x,bx=b.x,ay=a.y,by=b.y;
	
	if(ax==bx) return abs(ay-by)+1;
	if(ay==by) return abs(ax-bx)+1;
	return gcd(abs(ax-bx),abs(ay-by))+1; 
}
