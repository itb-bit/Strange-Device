#include <stack>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <set>



using namespace std;



long  Gcd(long a, long  b) {
	if (b == 0) {
		return a;
	}
	return Gcd(b, a % b);
}
int main()
{
	long a;
	long b;
	int n;
	long le;
	cin >> n >> a >> b;

	long la = a /  Gcd(a, b + 1);

	le = la*b;

	priority_queue<pair<long, long>, vector<pair<long, long>>, greater<pair<long, long>>> num;
	

	long li;
	long ri;
 


	for (int i = 0; i < n; i++)
	{
		cin >> li >> ri;
		if (1 + ri - li <= le)
		{
			if (li%le>(ri) % le)
			{
				num.push(pair<long, long>(li%le, le - 1));
				num.push(pair<long, long>(0, ri % le));
			}
			else
			{
				num.push(pair<long, long>(li%le, ri % le));
			}
		}
		else
		{
			num.push(pair<long, long>(0, le - 1));
		}

	}

	long last = -1;
	long counter = 0;
	while (!num.empty())
	{

		if (last < num.top().second)
		{
			if (num.top().first - 1>last)
			{
				last = num.top().first - 1;
			}
			counter += num.top().second - last;
			last = num.top().second;


		}
		num.pop();
	}
	cout << counter;


	return 0;
}
