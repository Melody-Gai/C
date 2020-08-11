//好多数据，一列代表一类数据，一列都是同一类数据



//主成分分析
x = [数据];
x = x';
stdr = std(x);  %求各变量标准差
[n,m] = size(x);
sddata = x./stdr(ones(n,1),:);  %标准化变换
[p,princ,egenvalue] = princomp(sddata)   %调用主成分分析程序
p3 = p(:,1:3)      %输出前三个主成分系数
sc = princ(:,1:3)     %输出前三个主成分得分
egenvalue    %输出特征根
per = 100*egenvalue/sum(egenvalue)    %输出各个主成分贡献率

//聚类分析
x = [数据];
[n,m] = size(x);
stdr = std(x);
xx = x./stdr(ones(n,1),:);  %标准化变换
y = pdist(xx);  %计算各样本间距离（这里为欧氏距离）
z = linkage(y);  %进行聚类（这里为最短距离法）
h = dendrogram(z);   %画聚类谱系图
t = cluster(z,3)  %将全部样本分为3类
find(t == 2);   %找出属于第2类的样品编号


//判别分析
training = [数据];
group = [数据];   %给出训练样本training的分类结果
sample = [数据];   %给出待判别样本
oldclass = classify(training,training,group)   %给出训练样本training的回代结果
newclass = classify(sample,training,training,group)  %给出待判样本分类结果
gplotmatrix = (training,[ ],group);   %绘图看分类情况

