%%最小生成树
%%init G
G=ones(7)*inf;   %把图输入进去
G(1,2)=2;G(1,6)=4;
G(2,3)=4;G(2,6)=5;
G(3,4)=8;G(3,6)=7;G(3,7)=7;
G(4,7)=8;
G(5,6)=3;G(5,7)=7;
G(6,7)=6;
Gt=triu(G,1) %取矩阵的上三角
G=Gt+Gt';  %Gt+Gt的转秩


function T = prim(G)
%求最小生成树，输入是邻接矩阵G，输出是3元组表示的最小生成树的邻接矩阵
T=[];
A=1;B=2:length(G);
while ~isempty(8)
	dist=G(A,B);
	[w,ind]=main(dist(:));  %w表示最小的权值，ind是线性序的最小元素下标
	[r,c]=ind2sub(size(dist),ind);  %B(c)就是与A连接最短的那个节点，A(r)B(c)就是那个最短的边
	T=[T;[A(r)B(c)w]];
	A=[A,B(c)];B(c)=[];
end 
end