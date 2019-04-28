#pragma once

template<class K, class V>
struct BSTreeNode
{
	BSTreeNode<K, V>* _left;
	BSTreeNode<K, V>* _right;
	std::pair<K, V> _kv;

	BSTreeNode(const std::pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _kv(kv)
	{}
};

template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}

	Node* Find(const K& k)
	{
		if (_root == nullptr)
			return NULL;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < k)
				cur = cur->_right;
			else if (cur->_kv.first>k)
				cur = cur->_left;
			else
			{
				cout << cur->_kv.first << endl;
				return cur;
			}
		}
		return NULL;
	}

	bool Insert(const std::pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = _root;
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
			else if (cur->_kv == kv)
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
			parent->_left = cur;
		else
			parent->_right = cur;
		return true;
	}

	bool Erase(const K& k)
	{
		if (_root == nullptr)
			return false;
		Node* cur = _root;
		Node* parent = _root;
		while (cur)
		{

			if (cur->_kv.first > k)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < k)
			{
				parent = cur;
				cur = cur->_right;
			}
			else           //找到删除节点
			{
				Node* del = cur;
				if (!cur->_left)                    //左节点为空
				{
					if (parent == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{

							parent->_right = cur->_right;
						}
					}
				}
				else if (!cur->_right)             //右节点为空
				{
					if (parent == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}

				}
				else                       //左右节点都不为空
				{
					Node* prereplace = cur;
					Node* replace = cur->_right;
					while (replace->_left)
					{
						prereplace = replace;
						replace = replace->_left;
					}
					cur->_kv = replace->_kv;
					del = replace;

					//删除替代的最左节点
					if (prereplace->_left == replace)
					{
						prereplace->_left = replace->_right;
					}
					else
					{
						prereplace->_right = replace->_right;
					}
				}
				delete del;
				return true;
			}
		}
		return false;
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

void TestBSTree()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9, 0 };
	BSTree<int, int> t;
	for (auto e : a)
	{
		t.Insert(std::make_pair(e, e));
	}
	t.Inorder();
	std::cout << std::endl;

	t.Erase(2);
	t.Erase(8);
	t.Erase(1);
	t.Erase(7);
	//t.Erase(2);
	t.Inorder();
}