/*
https://www.youtube.com/watch?v=KNVPFVG49Oc&ab_channel=FamTrinli

*/

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <list>

using namespace std;

class Node {
public:
	int a;
	char c;
	Node* left, * right;

	Node() {}

	Node(Node* L, Node* R)
	{
		left = L;
		right = R;
		a = L->a + R->a;
	}
};

struct MyCompare 
{
	bool operator()(const Node* l, const Node* r) const 
	{ return l->a < r->a; }
};

vector<bool> code;
map<char, vector<bool> > table;

void BuildTable(Node* root)
{
	if (root->left != NULL)
	{
		code.push_back(0);
		BuildTable(root->left);
	}

	if (root->right != NULL)
	{
		code.push_back(1);
		BuildTable(root->right);
	}

	if (root->left == NULL && root->right == NULL) table[root->c] = code;

	if (code.size() != 0) {
		code.pop_back();
	}
}

int main() {

	int k, size = 0;
	string s, answer, cd;
	char temp;
	map <char, int> sym_and_val;
	map <char, string> sym_and_cd;
	set <char> l;

	getline(cin, s);
	//список символов и их приоритет
	for (int i = 0; i < s.size(); i++) {
		temp = s[i];
		sym_and_val[temp] = sym_and_val[temp] + 1;
		l.insert(s[i]);
	}

	k = sym_and_val.size();
	list <Node*> t;

	for (auto now : sym_and_val) {
		Node *p = new Node;
		p->c = now.first;
		p->a = now.second;
		t.push_back(p);
	}

	while (t.size() != 1) {
		t.sort(MyCompare());

		Node* L = t.front();
		t.pop_front();
		Node* R = t.front();
		t.pop_front();

		Node* L_plus_R = new Node(L, R);
		t.push_back(L_plus_R);
	}

	Node* root = t.front();

	BuildTable(root);

	
	for (int i = 0; i < s.size(); i++) {
		temp = s[i];
		code = table[temp];
		size = size + code.size();
	}

	if (size == 0) {
		size = s.size();
	}
	cout << k << " " << size << endl;

	
	for (int i = 0; i < s.size(); i++) {
		temp = s[i];
		code = table[temp];
		for (int j = 0; j < code.size(); j++) {
			if (code[j]) {
				answer = answer + "1";
				cd = cd + "1";
			}
			else {
				answer = answer + "0";
				cd = cd + "0";
			}
		}
		if (code.size() == 0) {
			cd = "0";
		}
		sym_and_cd[temp] = cd;
		cd = "";
	}
	
	for (auto now : sym_and_cd) {
		cout << now.first << ": " << now.second << endl;
	}

	if (l.size() < 3) {
		for (int i = 0; i < s.size(); i++) {
			if(s[i] == s[0])
			cout << "0";
			else {
				cout << "1";
			}
		}
	}
	else {
		cout << answer << endl;
	}
}