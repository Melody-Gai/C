#include <stdio.h>
#include <malloc.h>

#define MAX_TREENODE_NUM 100 			// "孩子链表表示法" 中二叉树的最大节点个数 
										// "孩子链表表示法" 中孩子链表节点结构体类型定义 
typedef struct ChildNode { 
  	int Child;           				// 孩子节点的位置 
  	struct ChildNode *Next; 			// 指向下一个孩子的指针 
} ChildNode;
										// "孩子链表表示法" 中二叉树节点结构体类型定义 
typedef struct DataNode { 
  	char   Data;                  		// 二叉树中节点的数据类型 
  	struct ChildNode *FirstChild; 		// 指向二叉树中节点的第一个孩子的指针 
} DataNode;	
										// "孩子链表表示法" 中二叉树结构体类型定义 
typedef struct ChildTree { 
  	DataNode Nodes[MAX_TREENODE_NUM]; 	// 二叉树的"孩子链表表示法" 
  	int Root;                           // 树根节点的游标 - 静态指针值 
  	int TreeNodeNum;                    // 二叉树中实际的节点数目 
} ChildTree; 

void inputNode(ChildTree *tree);
void showTree(ChildTree tree);
void showOneList(DataNode node);
void showNode(ChildTree tree);
void nodeCount(ChildTree tree);
int leafNodeCount(ChildTree tree);
unsigned char isLeadNode(ChildTree tree, char ch);
void leafPath(ChildTree tree, char ch);
void showPath(char *arr, int arrIndex);

void showPath(char *arr, int arrIndex) {
	int i;

	for (i = arrIndex - 1; i >= 0; i--) {
		printf("%c ", arr[i]);
	}
}

void leafPath(ChildTree tree, char ch) {
	int i;
	int index;
	char arr[7];
	int arrIndex = 0;

	for (i = 0; i < tree.TreeNodeNum; i++) {
		if (tree.Nodes[i].Data == ch) {
			break;
		}
	}
	arr[arrIndex++] = ch;
	while (tree.Nodes[i].Data != 'A') {
		for (index = 0; index < i; index++) {
			if (tree.Nodes[tree.Nodes[index].FirstChild->Child].Data == ch || 
				tree.Nodes[tree.Nodes[index].FirstChild->Next->Child].Data == ch) {
				arr[arrIndex++] = tree.Nodes[index].Data;
				i = index;
				ch = tree.Nodes[index].Data;
				break;
			}
		}
	}
	showPath(arr, arrIndex);
}

unsigned char isLeadNode(ChildTree tree,char ch) {
	int i;

	for (i = 0; i < tree.TreeNodeNum; i++) {
		if (tree.Nodes[i].Data == ch) {
			break;
		}
	}

	if (tree.Nodes[i].FirstChild->Child == -1 && tree.Nodes[i].FirstChild->Next->Child == -1) {
		return 1;
	}

	return 0;
}

int leafNodeCount(ChildTree tree) {
	int i;
	int count = 0;

	for (i = 0; i < tree.TreeNodeNum; i++) {
		if (tree.Nodes[i].FirstChild->Child == -1 && tree.Nodes[i].FirstChild->Next->Child == -1) {
			count++;
		}
	}

	return count;
}


void showNode(ChildTree tree) {
	int i;

	for (i = 0; i < tree.TreeNodeNum; i++) {
		printf("%c ", tree.Nodes[i].Data);
	}
	printf("\n");
	for (i = 0; i < tree.TreeNodeNum; i++) {
		printf("%d ", i);
	}
	printf("\n");
}

void showOneList(DataNode node) {
	ChildNode *p = node.FirstChild;

	printf("%c ", node.Data);
	while (p) {
		printf("%d ", p->Child);
		p = p->Next;
	}
	printf("\n");
}

void showTree(ChildTree tree) {
	int i = 0;

	for (i = 0; i < tree.TreeNodeNum; i++) {
		showOneList(tree.Nodes[i]);
	}
	printf("\n");
}

void inputNode(ChildTree *tree) {
	int ch;
	int i = 0;
	ChildNode *rightChild = NULL;
	int index = 0;

	printf("按层序遍历的顺序，依次输入二叉树的每个节点：（输入@结束）\n");
	ch = getchar();
	getchar();
	while (ch != '@') {
		tree->Nodes[i++].Data = ch;
		printf("按层序遍历的顺序，依次输入二叉树的每个节点：（输入@结束）\n");
		ch = getchar();
		getchar();
	}
	tree->TreeNodeNum = i;
	tree->Root = 0;
	showNode(*tree);
	printf("节点的下标对应如上所示\n");
	for (i = 0; i < tree->TreeNodeNum; i++) {
		printf("请输入%c节点的左孩子下标（若没有就输入-1）\n", tree->Nodes[i].Data);
		scanf("%d", &index);
		tree->Nodes[i].FirstChild = (ChildNode *)malloc(sizeof(ChildNode));
		tree->Nodes[i].FirstChild->Child = index;
		tree->Nodes[i].FirstChild->Next = NULL;
		printf("请输入%c节点的右孩子下标（若没有就输入-1）\n", tree->Nodes[i].Data);
		scanf("%d", &index);
		rightChild = (ChildNode *)malloc(sizeof(ChildNode));
		rightChild->Child = index;
		tree->Nodes[i].FirstChild->Next = rightChild;
		rightChild->Next = NULL;
	}
}

int main() {
	ChildTree tree;
	char ch;

	inputNode(&tree);
	showTree(tree);
	printf("叶子节点的个数为%d\n", leafNodeCount(tree));
	printf("输入一个节点，判断是否为叶子节点\n");
	getchar();
	ch = getchar();
	if (isLeadNode(tree, ch)) {
		printf("%c是叶子节点，路径如下\n", ch);
		leafPath(tree, ch);
	} else {
		printf("%c不是叶子节点\n", ch);
	}

	return 0;
}

/*
A
B
C
D
E
F
G
H
I
@
1
2
3
4
-1
5
6
-1
-1
-1
7
8
-1
-1
-1
-1
-1
-1

 */