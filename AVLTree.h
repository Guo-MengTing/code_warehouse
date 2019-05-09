#pragma once
#include<assert.h>
#include<iostream>
using namespace std;
template<class K,class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	std::pair<K, V> _kv;
	int _bf;

	AVLTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
		, _kv(kv)
	{}
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{}
	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_bf = 0;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first<kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first>kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//更新平衡因子
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				break;
			}
			else if (abs(parent->_bf) == 1)
			{
				//2.高度变了，继续更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (abs(parent->_bf) == 2)
			{
				//不平衡旋转
				if (parent->_bf == 2)
				{
					if (cur->_bf == -1)
						RotateRL(parent);
					else if (cur->_bf == 1)
						RotateL(parent);
				}
				else if (parent->_bf==-2)
				{
					if (cur->_bf == 1)
						RotateLR(parent);
					else if (cur->_bf == -1)
						RotateR(parent);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pparent = parent->_parent;
		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;
		subL->_right = parent;
		parent->_parent = subL;
		if (parent == _root)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subL;
			else
				pparent->_right = subL;
			subL->_parent = pparent;
		}
		subL->_bf = parent->_bf = 0;
	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pparent = parent->_parent;
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;
		subR->_left = parent;
		parent->_parent = subR;
		if (parent == _root)
		{
			_root = subR;
			_root->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
				pparent->_left = subR;
			else
				pparent->_right = subR;
			subR->_parent = pparent;
		}
		subR->_bf = parent->_bf = 0;
	}

	void RotateLR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		
		int bf = subLR->_bf;
		RotateL(parent->_left);
		RotateR(parent);
		if (bf == 1)
		{
			subL->_bf = 0;
			parent->_bf = 1;
		}
		else if (bf == -1)
		{
			subL->_bf = -1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subL->_bf = parent->_bf = 0;
		}
		subLR->_bf = 0;
	}

	void RotateRL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);
		if (bf == 1)
		{
			subR->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			subR->_bf = 1;
			parent->_bf = 0;
		}
		else if (bf == 0)
		{
			subR->_bf = parent->_bf = 0;
		}
		subRL->_bf = 0;
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
	}
	bool isBalanceTree()
	{
		return _isBalanceTree(_root);
	}
	bool _isBalanceTree(Node* root)
	{
		if (root == nullptr)
			return true;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);
		int gap = rightHeight - leftHeight;

		if (gap != root->_bf)
		{
			cout << "平衡因子异常：" << root->_kv.first << endl;
			return false;
		}
		return _isBalanceTree(root->_left) && _isBalanceTree(root->_right);
	}

	void Inorder()
	{
		return _Inorder(_root);
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_kv.first << ' ';
		_Inorder(root->_right);
	}
private:
	Node* _root;
};

void TestAVLTree()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	AVLTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
		cout << t.isBalanceTree() << "->" << e << endl;
	}
	t.Inorder();
}
