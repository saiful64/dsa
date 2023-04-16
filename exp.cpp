#include <bits/stdc++.h>
using namespace std;

double evaluatePrefix(string exp)
{
	stack<double> Stack;

	for (int j = exp.size() - 1; j >= 0; j--) {  //Traversing right to left 
	
		// if jth character is the delimiter ( which is
		// space in this case) then skip it
		if (exp[j] == ' ')
			continue;

		// Push operand to Stack
		// To convert exp[j] to digit subtract
		// '0' from exp[j].
		if (isdigit(exp[j])) {

            //if number are in singke digit directly "Stack.push(exprsn[j] - '0');"
		
			// there may be more than
			// one digits in a number
			double num = 0, i = j;
			while (j < exp.size() && isdigit(exp[j]))
				j--;
			j++;

			// from [j, i] exp contains a number
			for (int k = j; k <= i; k++)
				num = num * 10 + double(exp[k] - '0');

			Stack.push(num);
		}
		else {
			double o1 = Stack.top();
			Stack.pop();
			double o2 = Stack.top();
			Stack.pop();

			switch (exp[j]) {
			case '+':
				Stack.push(o1 + o2);
				break;
			case '-':
				Stack.push(o1 - o2);
				break;
			case '*':
				Stack.push(o1 * o2);
				break;
			case '/':
				Stack.push(o1 / o2);
				break;
			}
		}
	}

	return Stack.top();
}

int main()
{
	string exp = "+ 9 * 12 6";
	cout << evaluatePrefix(exp) << endl;
	return 0;

}
