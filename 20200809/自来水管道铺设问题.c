G=xlsread('一.xlsx');
T=prim(G);

p=xlsread('p1.1.xlsx');  %画点
x=p(:,1);
y=p(:,2);
plot(x,y,'o','markersize',5) 

for i=1:length(p)      %画字标
if i==1
         text(x(i),y(i),'A','color','red','FontSize',20)
else
        text(x(i),y(i),num2str(i-1),'color','blue','Fontsize',15)
end
end

for i=1:length(T)        %连线
    x1=[x(T(i,1)),x(T(i,2))];
    y1=[y(T(i,1)),y(T(i,2))];
    line(x1,y1,'Color','red','LineStyle','--','linewidth',3)
end
hold on

G=xlsread('二.xlsx');
T=prim1(G);

p=xlsread('p1.2.xlsx');  %画点
x=p(:,1);
y=p(:,2);
plot(x,y,'o','markersize',5) 

for i=1:length(p)      %画字标
        text(x(i),y(i),num2str(i-1),'color','blue','Fontsize',10)
end

for i=1:length(T)        %连线
    x1=[x(T(i,1)),x(T(i,2))];
    y1=[y(T(i,1)),y(T(i,2))];
    line(x1,y1,'Color','blue','LineStyle','-','linewidth',1)
end




    //二

function T=prim(G)
%求最小生成树，输入是邻接矩阵G输出是3元组表示的最小生成树的邻接矩阵
T=[];
A=1;B=2:length(G);
while ~isempty(B)
    dist=G(A,B);
    [w,ind]=min(dist(:));
    [r,c]=ind2sub(size(dist),ind);
    T=[T;[A(r) B(c) w]];
    A=[A,B(c)];B(c)=[];
end 
end

//
function T=prim1(G)
%求最小生成树，输入是邻接矩阵G输出是3元组表示的最小生成树的邻接矩阵
T=[];
A=1:12;B=13:length(G);
while ~isempty(B)
    dist=G(A,B);
    [w,ind]=min(dist(:));
    [r,c]=ind2sub(size(dist),ind);
    T=[T;[A(r) B(c) w]];
    A=[A,B(c)];B(c)=[];
end 
end

