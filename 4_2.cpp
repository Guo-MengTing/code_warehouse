//矩形覆盖
class Solution {
public:
	int rectCover(int number) {
		if (number == 0)
			return 0;
		if (number == 1)
			return 1;
		int f1 = 0;
		int f2 = 1;
		int f3;
		for (int i = 0; i<number; ++i)
		{
			f3 = f1 + f2;
			f1 = f2;
			f2 = f3;
		}
		return f3;
	}
};

//旋转数组的最小数字
lass Solution{
public:
	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() == 0)
			return 0;
		int len = rotateArray.size();
		int i;
		int min = rotateArray[0];
		for (i = 0; i<len; ++i)
		{
			if (min>rotateArray[i])
			{
				min = rotateArray[i];
			}
		}
		return min;
	}
};

//用两个栈实现队列
class Solution
{
public:
	void push(int node) {
		if (stack2.empty())
			stack1.push(node);
		else
		{
			while (!stack2.empty())
			{
				stack1.push(stack2.top());
				stack2.pop();
			}
			stack1.push(node);
		}
	}

	int pop() {
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
		int result = stack2.top();
		stack2.pop();
		return result;
	}

private:
	stack<int> stack1;
	stack<int> stack2;
};

//重建二叉树
class Solution {
public:
	TreeNode* reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		if (pre.size() == 0 || vin.size() == 0 || (pre.size() != vin.size()))
			return NULL;
		int value = pre[0];
		TreeNode* node = new TreeNode(value);
		std::vector<int> pre_left, pre_right, vin_left, vin_right;
		int i;
		for (i = 0; i<vin.size(); ++i)
		{
			if (vin[i] == value)
				break;
		}
		int j;
		for (j = 0; j<vin.size(); ++j)
		{
			if (j<i)
			{
				vin_left.push_back(vin[j]);
				pre_left.push_back(pre[j + 1]);
			}
			if (j>i)
			{
				vin_right.push_back(vin[j]);
				pre_right.push_back(pre[j]);
			}
		}
		node->left = reConstructBinaryTree(pre_left, vin_left);
		node->right = reConstructBinaryTree(pre_right, vin_right);
		return node;
	}
};

//替换空格
class Solution {
public:
	void replaceSpace(char *str, int length) {
		int count = 0;
		for (int i = 0; i<length; ++i)
		{
			if (str[i] == ' ')
				++count;
		}
		for (int j = length - 1; j >= 0; --j)
		{
			if (str[j] != ' ')
			{
				str[2 * count + j] = str[j];
			}
			else{
				--count;
				str[2 * count + j] = '%';
				str[2 * count + j + 1] = '2';
				str[2 * count + j + 2] = '0';
			}
		}
	}
};

//二维数组中的查找
class Solution {
public:
	bool Find(int target, vector<vector<int> > array) {
		int row = array.size();
		int col = array[0].size();
		int i, j;
		for (i = row - 1, j = 0; i >= 0 && j<col;)
		{
			if (target == array[i][j])
				return true;
			if (target>array[i][j])
			{
				++j;
				continue;
			}
			if (target<array[i][j])
			{
				--i;
				continue;
			}
		}
		return false;
	}
};