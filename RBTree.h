#pragma once

enum Colour
{
	RED,
	BLACK,
};

template<class V>
struct RBTreeNode
{
	RBTreeNode<V>* _left;
	RBTreeNode<V>* _right;
	RBTreeNode<V>* _parent;

	V _value_filed;
	Colour _col;

	RBTreeNode(const V& v)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _value_filed(v)
		, _col(RED)
	{}
};

template<class V>
struct RBTreeIterator
{
	typedef RBTreeNode<V> Node;
	typedef RBTreeIterator<V> Self;
	Node* _node;

	RBTreeIterator(Node* node)
		:_node(node)
	{}

	V& operator*()
	{
		return _node->_value_filed;
	}

	V* operator->()
	{
		return &_node->_value_filed;
	}

	// it++  it->operator++(&it, 0);
	Self operator++(int)
	{
		Self ret(*this);

		++(*this);

		return ret;
	}

	// ++it  it->operator++(&it);
	Self& operator++()
	{
		if (_node->_right != nullptr)
		{
			// 找右子树的最左节点就是中序的下一个
			Node* subright = _node->_right;
			while (subright->_left)
			{
				subright = subright->_left;
			}

			_node = subright;
		}
		else
		{
			// 沿着路径往上，孩纸是父亲的左的那个父亲
			Node* cur = _node;
			Node* parent = _node->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = parent->_parent;
			}

			_node = parent;
		}

		return *this;
	}

	bool operator!= (const Self& s)
	{
		return _node != s._node;
	}

};

//Map->RBTree<K, pair<K, V>>
//Set->RBTree<K, K>

template<class K, class V, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<V> Node;
public:
	typedef RBTreeIterator<V> iterator;

	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}

		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}

	std::pair<iterator, bool> Insert(const V& v)
	{
		if (_root == nullptr)
		{
			_root = new Node(v);
			_root->_col = BLACK;
			return std::make_pair(iterator(_root), true);
		}

		KeyOfValue kov;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (kov(cur->_value_filed) < kov(v))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kov(cur->_value_filed) > kov(v))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return std::make_pair(iterator(cur), false);
			}
		}

		cur = new Node(v);
		Node* newnode = cur;
		cur->_col = RED;
		if (kov(parent->_value_filed) < kov(v))
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		
		// 平衡
		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					// 第一种情况：变色
					parent->_col = BLACK;
					uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					// 第三中情况：双旋->单旋
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}

					// 第二中情况：单旋+变色
					RotateR(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
			else // parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						std::swap(parent, cur);
					}
					
					RotateL(grandfather);
					parent->_col = BLACK;
					grandfather->_col = RED;
				}
			}
		}

		_root->_col = BLACK;

		return std::make_pair(iterator(newnode), true);

	}

	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subR;

		if (parent == _root)
		{
			_root = subR;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subR;
			else
				ppnode->_right = subR;
		}

		subR->_parent = ppnode;
	}

	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		Node* ppnode = parent->_parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
		}
		else
		{
			if (ppnode->_left == parent)
				ppnode->_left = subL;
			else
				ppnode->_right = subL;
		}

		subL->_parent = ppnode;
	}

	void Inorder()
	{
		_Inorder(_root);
		cout << endl;
	}

	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;

		_Inorder(root->_left);
		cout << root->_value_filed<< " ";
		_Inorder(root->_right);
	}
private:
	Node* _root = nullptr;
};

//void TestRBTree()
//{
//	RBTree<int, int> t;
//	int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
//	for (auto e : a)
//	{
//		t.Insert(std::make_pair(e, e));
//	}
//
//	t.Inorder();
//}
