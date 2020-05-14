#include <stdio.h>
#include <malloc.h>

#define MAX_TREENODE_NUM 100 			// "���������ʾ��" �ж����������ڵ���� 
										// "���������ʾ��" �к�������ڵ�ṹ�����Ͷ��� 
typedef struct ChildNode { 
  	int Child;           				// ���ӽڵ��λ�� 
  	struct ChildNode *Next; 			// ָ����һ�����ӵ�ָ�� 
} ChildNode;
										// "���������ʾ��" �ж������ڵ�ṹ�����Ͷ��� 
typedef struct DataNode { 
  	char   Data;                  		// �������нڵ���������� 
  	struct ChildNode *FirstChild; 		// ָ��������нڵ�ĵ�һ�����ӵ�ָ�� 
} DataNode;	
										// "���������ʾ��" �ж������ṹ�����Ͷ��� 
typedef struct ChildTree { 
  	DataNode Nodes[MAX_TREENODE_NUM]; 	// ��������"���������ʾ��" 
  	int Root;                           // �����ڵ���α� - ��ָ̬��ֵ 
  	int TreeNodeNum;                    // ��������ʵ�ʵĽڵ���Ŀ 
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

	printf("�����������˳�����������������ÿ���ڵ㣺������@������\n");
	ch = getchar();
	getchar();
	while (ch != '@') {
		tree->Nodes[i++].Data = ch;
		printf("�����������˳�����������������ÿ���ڵ㣺������@������\n");
		ch = getchar();
		getchar();
	}
	tree->TreeNodeNum = i;
	tree->Root = 0;
	showNode(*tree);
	printf("�ڵ���±��Ӧ������ʾ\n");
	for (i = 0; i < tree->TreeNodeNum; i++) {
		printf("������%c�ڵ�������±꣨��û�о�����-1��\n", tree->Nodes[i].Data);
		scanf("%d", &index);
		tree->Nodes[i].FirstChild = (ChildNode *)malloc(sizeof(ChildNode));
		tree->Nodes[i].FirstChild->Child = index;
		tree->Nodes[i].FirstChild->Next = NULL;
		printf("������%c�ڵ���Һ����±꣨��û�о�����-1��\n", tree->Nodes[i].Data);
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
	printf("Ҷ�ӽڵ�ĸ���Ϊ%d\n", leafNodeCount(tree));
	printf("����һ���ڵ㣬�ж��Ƿ�ΪҶ�ӽڵ�\n");
	getchar();
	ch = getchar();
	if (isLeadNode(tree, ch)) {
		printf("%c��Ҷ�ӽڵ㣬·������\n", ch);
		leafPath(tree, ch);
	} else {
		printf("%c����Ҷ�ӽڵ�\n", ch);
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