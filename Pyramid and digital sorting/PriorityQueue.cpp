#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<pair<int, int>> queue;

void sift_up(int i) {
	if (i > 0) {
		int parent = (i - 1) / 2;

		if (queue[i].second < queue[parent].second) {
			swap(queue[i], queue[parent]);
			sift_up(parent);
		}
	}
}

void sift_down(int i) {
	int left_child = 2 * i + 1;
	int right_child = 2 * i + 2;
	int min;

	if (left_child < queue.size() && right_child < queue.size()) {
		if (queue[left_child].second < queue[right_child].second) {
			min = left_child;
		}
		else {
			min = right_child;
		}
	}
	else {
		if (left_child < queue.size()) {
			min = left_child;
		}
		else {
			if (right_child < queue.size()) {
				min = right_child;
			}
			else {
				return;
			}
		}
	}

	if (queue[i].second > queue[min].second) {
		swap(queue[i], queue[min]);
		sift_down(min);
	}
}

void push(pair<int, int> a) {
	queue.push_back(a);
	sift_up(queue.size() - 1);
}

int extract_min() {

	if (queue.size() == 0) {
		return INT_MAX;
	}

	int min = queue[0].second;

	queue[0].second = INT_MAX;
	sift_down(0);

	return min;
}

void decrease_key(pair <int, int> a) {
	for (int i = 0; i < queue.size(); i++) {
		if (queue[i].first == a.first) {
			queue[i] = a;
			sift_up(i);
			break;
		}
	}
}


int main() {
	//freopen("priorityqueue.in","r", stdin);
	//freopen("priorityqueue.out","w", stdout);

	string s;
	int count = 0;
	int temp, num1, num2;

	while (cin >> s) {
		count++;
		if (s == "push") {
			cin >> temp;
			push(make_pair(count, temp));
		}
		
		if (s == "extract-min") {
			temp = extract_min();
			
			if (temp == INT_MAX) {
				cout << '*' << endl;
			}
			else {
				cout << temp << endl;
			}
		}
			
		if (s == "decrease-key") {
			cin >> num1 >> num2;
			decrease_key(make_pair(num1, num2));
		}
			
	}

	return 0;
}
