// ...    for king's moves direction array will be
// ...    int fx[]={1,-1,0,0};
// ...    int fy[]={0,0,1,-1};


#include<bits/stdc++.h>
#define X first
#define Y second
#define pii pair<int,int>
#define inf 1000000000
using namespace std;
int r ;
int c ;
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
int dis[1001][1001],bombb[1001][1001];

int bfs(int x,int y,int desx,int desy)
{
	for(int i=1;i<=1000;i++) for(int j =1;j<=1000;j++) dis[i][j] = inf;
	dis[x][y] = 0;
	queue<pii>q;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		pii top = q.front();
		q.pop();
		for(int k=0;k<4;k++)
		{
			int tx = top.X + fx[k];
			int ty = top.Y + fy[k];
			if(tx>=1 && tx<=r && ty>=1 && ty<=c && dis[tx][ty] == inf&&bombb[tx][ty]==0)
			{
				dis[tx][ty] = dis[top.X][top.Y] + 1;
				q.push(make_pair(tx,ty));
			}
		}
	}
	return dis[desx][desy];
}

int main()
{
  while(scanf("%d %d",&r,&c)==2){
  if(r==0 && c==0) break;
  int bomb;
  scanf("%d",&bomb);
  for(int i=0;i<bomb;i++){
    int rr;
    scanf("%d",&rr);
    rr+=1;
    int num; scanf("%d",&num);
    for(int j=0;j<num;j++){
        int cc; scanf("%d",&cc);
        cc+=1;
        bombb[rr][cc]=1;
    }
  }
  int stt1,dess1,stt2,dess2;
  scanf("%d %d",&stt1,&dess1); scanf("%d %d",&stt2,&dess2);
  stt1+=1,dess1+=1,stt2+=1,dess2+=1;
  bfs(stt1,dess1,stt2,dess2);
  printf("%d\n",dis[stt2][dess2]);
  memset(bombb,0,sizeof(bombb));
  }
  return 0;
}

