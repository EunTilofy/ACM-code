//	int cnt=0;
//	int i,j;
//	tot=0;
//	for(i=1; i<=n; i++)h[i]=deg[i]=0;
//	ll=1,rr=0;
//	printf("!%d\n",n);
//	for(i=1; i<=t&&w[i].a<=n; i++)
//		if(w[i].b<=n)adds(w[i].a,w[i].b),deg[w[i].a]++,deg[w[i].b]++;
//		else que[++rr]=w[i].a;
//	while(ll<=rr) {
//		if(cnt==n)return 1;
//		int x=que[ll];
//		ll++;
//		for(i=h[x]; i; i=nx[i]) {
//			int y=r[i];
//			deg[x]--,deg[y]--;
//			if(!mk[y])que[++rr]=y,mk[y]=1,cnt++;
//		}
//	}
//	ll=1,rr=0;
//	for(i=1; i<=n; i++)
//		if(deg[i]==1)que[++rr]=i,cnt++,deg[i]--;
//	while(ll<=rr) {
//		if(cnt==n)return 1;
//		int x=que[ll];
//		ll++;
//		for(i=h[x]; i; i=nx[i]) {
//			int y=r[i];
//			deg[y]--;
//			if(deg[y]<=0)return 0;
//			if(deg[y]==1)que[++rr]=i,cnt++;
//		}
//	}
//	return 1;