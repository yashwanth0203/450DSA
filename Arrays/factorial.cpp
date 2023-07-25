void multiply(int mulval,vector<int> &nums){
        long long int carry=0;
        for(auto i=nums.rbegin();i!=nums.rend();i++){
            long long int mul= mulval * (*i) +carry;
            carry=mul/10;
            *i = mul%10;
        }
        while(carry!=0){
            nums.insert(nums.begin(),carry);
            carry/=10;
        }
    }
    vector<int> factorial(int N){
        vector<int>res;
        res.push_back(1);
        for(int i=2;i<=N;i++)
            multiply(i,res);
        return res;
    }

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = a; i <= b; i++)

using namespace std;
// Made a class node containing data and previous pointer as
// we are using tail pointer
class Node {
public:
	int data;
	Node* prev;
	Node(int n)
	{
		data = n;
		prev = NULL;
	}
};

void Multiply(Node* tail, int n)
{
	Node *temp = tail,
		*prevNode = tail; // Temp variable for keeping tail
	int carry = 0;
	while (temp != NULL) {
		int data = temp->data * n + carry;
		temp->data = data % 10; // stores the last digit
		carry = data / 10;
		prevNode = temp;
		temp = temp->prev; // Moving temp by 1 prevNode will
						// now denote temp
	}
	// If carry is greater than 0 then we create another
	// node for it.
	while (carry != 0) {
		prevNode->prev = new Node((int)(carry % 10));
		carry /= 10;
		prevNode = prevNode->prev;
	}
}

void print(Node* tail)
{
	if (tail == NULL) // Using tail recursion
		return;
	print(tail->prev);
	cout
		<< tail->data; // Print linked list in reverse order
}

// Driver code
int main()
{
	int n = 20;
	Node tail(1); // Create a node and initialise it by 1
	rep(i, 2, n)
		Multiply(&tail, i); // Run a loop from 2 to n and
							// multiply with tail's i
	print(&tail); // Print the linked list
	cout << endl;
	return 0;
}
