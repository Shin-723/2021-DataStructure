#include <iostream>
#include <cstring>

using namespace std;

char prec[4][2] = { '*',2,'/',2,'+',1,'-',1 };

struct Node
{
	char data;
	int prio;
	struct Node *left;
	struct Node *right;
	Node(char value)
	{
		data = value;
		prio = 4;
		left = NULL;
		right = NULL;
	}
};

class Tree
{
public:
	Tree();
	~Tree();
	bool isDigit(int value);
	bool isEmpty();
	void buildTree(char value);
	void insertOperand(Node *ptr);
	void insertOperator(Node *ptr);
	void inorder(Node *ptr);
	void callInorder();
	void preorder(Node *ptr);
	void callPreorder();
	void postorder(Node *ptr);
	void callPostorder();
	void expression(Node *ptr);
	void callExpression();
	int evaluation(Node *ptr);
	int callEvaluation();
    void drawTree(Node* ptr,int level);
    void callDrawTree();
private:
	Node *root;
};

Tree::Tree()
{
	root = NULL;
}

Tree::~Tree()
{
	delete root;
}

bool Tree::isDigit(int value)
{
	if (value == 4)
		return true;
	else
		return false;
}

bool Tree::isEmpty()
{
	if (root == NULL)
		return true;
	else
		return false;
}

void Tree::buildTree(char value)
{
	Node *temp = new Node(value);

	for (int i = 0; i < 4; i++){

		if (temp->data == prec[i][0]){
			temp->prio = prec[i][1] - '0';
			break;
		}

		else{
			temp->prio = 4;
		}
	}
	
	if (isDigit(temp->prio)){
		insertOperand(temp);
	}

	else{
		insertOperator(temp);
	}
}

void Tree::insertOperand(Node *ptr)
{
	if (isEmpty())
		root = ptr;
	else
	{
		Node *p = root;
		while (p->right != NULL)
			p = p->right;
		p->right = ptr;
	}
}

void Tree::insertOperator(Node *ptr)
{
	if (root->prio >= ptr->prio)
	{
		ptr->left = root;
		root = ptr;
	}
	else
	{
		ptr->left = root->right;
		root->right = ptr;
	}
}

void Tree::inorder(Node *ptr)
{
	if (ptr)
	{
		inorder(ptr->left);
		cout << ptr->data << " ";
		inorder(ptr->right);
	}
}

void Tree::callInorder()
{
	inorder(root);
}

void Tree::preorder(Node *ptr)
{
	if (ptr)
	{
		cout << ptr->data << " ";
		preorder(ptr->left);
		preorder(ptr->right);
	}
}

void Tree::callPreorder()
{
	preorder(root);
}

void Tree::postorder(Node *ptr)
{
	if (ptr)
	{
		postorder(ptr->left);
		postorder(ptr->right);
		cout << ptr->data << " ";
	}
}

void Tree::callPostorder()
{
	postorder(root);
}

void Tree::expression(Node *ptr)
{
	if (ptr)
	{
		if (!isDigit(ptr->prio))
			cout << "( ";

		expression(ptr->left);
		cout << ptr->data << " ";
		expression(ptr->right);

		if (!isDigit(ptr->prio))
			cout << ") ";
	}
}

void Tree::callExpression()
{
	expression(root);
}

int Tree::evaluation(Node *ptr)
{
	int value, left, right;
	if (ptr)
	{
		if (isDigit(ptr->prio))
			value = ptr->data - '0';
		else
		{
			left = evaluation(ptr->left);
			right = evaluation(ptr->right);
			switch (ptr->data)
			{
			case '+':
				value = left + right;
				break;
			case '-':
				value = left - right;
				break;
			case '*':
				value = left * right;
				break;
			case '/':
				value = left / right;
				break;
			}
		}
	}
	else
	{
		cout << "Tree is empty" << endl;
		return 0;
	}
	return value;
}

int Tree::callEvaluation()
{
	return evaluation(root);
}

void Tree::drawTree(Node* ptr,int level)
{
	if ((ptr != NULL) && level <= 7)
	{
		drawTree(ptr->right, level + 1);
		for (int i = 1; i <= (level - 1); i++)
			cout << "    ";
		cout << ptr->data;
		if ((ptr->left != NULL) && (ptr->right != NULL))
			cout << " < " << endl;
		else if (ptr->right != NULL)
			cout << " / " << endl;
		else if (ptr->left != NULL)
			cout << " \\ " << endl;
		else
			cout << endl;
		drawTree(ptr->left, level + 1);
	}
}

void Tree::callDrawTree()
{
	drawTree(root, 1);
}

int main()
{
	Tree t1;
    int len1;
    char exp1[100];
    cout << "1. Infix Expression 1 : ";
    cin >> exp1;
    len1 = strlen(exp1);

    for (int i = 0; i < len1; i++) {
        t1.buildTree(exp1[i]);
    }

    cout <<endl<< "InOrder : ";
    t1.callInorder();
    cout << endl;

    cout << "PostOrder : ";
    t1.callPostorder();
    cout << endl;
	
    cout << "PreOrder : ";
    t1.callPreorder();
    cout << endl;

	if(isdigit(exp1[0])){
		cout << "Evaluation : ";
		cout << t1.callEvaluation()<<endl;
	}
    t1.callDrawTree();
	
    cout << endl;

    Tree t2;
    int len2;
    char exp2[100];
    cout << "2. Infix Expression 2 : ";
    cin >> exp2;
    len2 = strlen(exp2);

    for (int i = 0; i < len2; i++) {
        t2.buildTree(exp2[i]);
    }

    cout <<endl<< "InOrder : ";
    t2.callInorder();
    cout << endl;

    cout << "PostOrder : ";
    t2.callPostorder();
    cout << endl;

    cout << "PreOrder : ";
    t2.callPreorder();
	cout << endl;

	if(isdigit(exp2[0])){
		cout << "Evaluation : ";
		cout << t2.callEvaluation();
	}

    cout << endl;
    t2.callDrawTree();

	return 0;
}
