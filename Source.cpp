#include<iostream>
#include<list>
using namespace std;

class Graph
{
	int V;

	list<int>* adj;
	list<int>* weight;

	bool DLS(int v, int target, int limit);

public:
	int depth;
	Graph(int V); 
	void addEdge(int v, int w, int weight);
	int arr[18], arr2[18];
	int count = 0;
	bool IDDFS(int v, int target, int max_depth);
	int total=0;
};

Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int>[V];
	weight = new list<int>[V];
}

void Graph::addEdge(int v, int w, int we)
{
	weight[v].push_back(we);
	adj[v].push_back(w); // Add w to v’s list. 
}

bool Graph::DLS(int src, int target, int limit)
{		
	if (src == target) {
		return true;
	}

	// 達到指定深度，沒找到目標
	if (limit <= 0)
		return false;
	// 找到跟起點相鄰的線
	auto j = weight[src].begin();
	for (auto i = adj[src].begin(); i != adj[src].end(); ++i) {
		//cout << *i<<" ";
		if (DLS(*i, target, limit - 1) == true) {
			int a = 1;
			arr[count] = *i;
			arr2[count] = *j;
			total += *j;
			
			/*if (*i == 0) {
				cout << "Path 'Brest', weight is " << *j << endl;
			}
			if (*i == 1) {
				cout << "Path 'Rennes', weight is " << *j << endl;
			}
			if (*i == 2) {
				cout << "Path 'Nantes', weight is " << *j << endl;
			}
			if (*i == 3) {
				cout << "Path 'Bordeaux', weight is " << *j << endl;
			}
			if (*i == 4) {
				cout << "Path 'Caen', weight is " << *j << endl;
			}
			if (*i == 5) {
				cout << "Path 'Limoges', weight is " << *j << endl;
			}
			if (*i == 6) {
				cout << "Path 'Toulouse', weight is " << *j << endl;
			}
			if (*i == 7) {
				cout << "Path 'Calais', weight is " << *j << endl;
			}
			if (*i == 8) {
				cout << "Path 'Paris', weight is " << *j << endl;
			}
			if (*i == 9) {
				cout << "Path 'Montpellier', weight is " << *j << endl;
			}
			if (*i == 10) {
				cout << "Path 'Nancy', weight is " << *j << endl;
			}
			if (*i == 11) {
				cout << "Path 'Dijon', weight is " << *j << endl;
			}
			if (*i == 12) {
				cout << "Path 'Lyon', weight is " << *j << endl;
			}
			if (*i == 13) {
				cout << "Path 'Avignon', weight is " << *j << endl;
			}
			if (*i == 14) {
				cout << "Path 'Marseille', weight is " << *j << endl;
			}
			if (*i == 15) {
				cout << "Path 'Strasbourg', weight is " << *j << endl;
			}
			if (*i == 16) {
				cout << "Path 'Grenoble', weight is " << *j << endl;
			}
			if (*i == 17) {
				cout << "Path 'Nice', weight is " << *j << endl;
			}*/
			count++;
			return true;
		}
		++j;
	}
	//cout << endl;

	return false;
}

bool Graph::IDDFS(int src, int target, int max_depth)
{
	// 重複深度找
	for (int i = 0; i <= max_depth; i++)
		if (DLS(src, target, i) == true) {
			depth = i;
			return true;
		}
	return false;
}

int main()
{
	int start, end;
	Graph g(18);
	g.addEdge(0, 1, 244);	g.addEdge(1, 0, 244);	g.addEdge(1, 2, 107);	g.addEdge(1, 8, 348);	g.addEdge(1, 4, 176);	g.addEdge(2, 1, 107);	g.addEdge(2, 5, 329);
	g.addEdge(2, 3, 329);	g.addEdge(3, 2, 329);	g.addEdge(3, 5, 220);	g.addEdge(3, 6, 253);	g.addEdge(4, 1, 176);	g.addEdge(4, 7, 120);	g.addEdge(4, 8, 241);
	g.addEdge(5, 2, 329);	g.addEdge(5, 3, 220);	g.addEdge(5, 12, 389);	g.addEdge(5, 6, 313);	g.addEdge(5, 8, 396);	g.addEdge(6, 3, 253);	g.addEdge(6, 5, 313);
	g.addEdge(6, 9, 240);	g.addEdge(7, 4, 120);	g.addEdge(7, 8, 297);	g.addEdge(7, 10, 534);	g.addEdge(8, 1, 348);	g.addEdge(8, 4, 241);	g.addEdge(8, 5, 396);
	g.addEdge(8, 7, 297);	g.addEdge(8, 11, 313);	g.addEdge(8, 10, 372);	g.addEdge(9, 6, 240);	g.addEdge(9, 13, 121);	g.addEdge(10, 7, 534);	g.addEdge(10, 8, 372);
	g.addEdge(10, 15, 145);	g.addEdge(10, 11, 201);	g.addEdge(11, 8, 313);	g.addEdge(11, 10, 201);	g.addEdge(11, 12, 192);	g.addEdge(11, 15, 335);	g.addEdge(12, 5, 389);
	g.addEdge(12, 11, 192);	g.addEdge(12, 13, 216);	g.addEdge(12, 16, 104);	g.addEdge(13, 9, 121);	g.addEdge(13, 12, 216);	g.addEdge(13, 14, 99);	g.addEdge(13, 16, 227);
	g.addEdge(14, 13, 99);	g.addEdge(14, 17, 188);	g.addEdge(17, 14, 188);

	cout << "請輸入開始城市0~17 0)Brest 1)Rennes 2)Nantes 3)Bordeaux 4)Caen 5)Limoges 6)Toulouse 7)Calais 8)Paris 9)Montpellier 10)Strasbourg 11)Dijon 12)Lyon 13)Avignon 14)Marseille 15)Strasbourg 16)Grenoble 17)Nice:";
	cin >> start;
	cout << "請輸入結束城市0~17 0)Brest 1)Rennes 2)Nantes 3)Bordeaux 4)Caen 5)Limoges 6)Toulouse 7)Calais 8)Paris 9)Montpellier 10)Strasbourg 11)Dijon 12)Lyon 13)Avignon 14)Marseille 15)Strasbourg 16)Grenoble 17)Nice:";
	cin >> end;
	int target = end, maxDepth = 7, src = start;
	cout << "點:" <<src<<" values:0"<<endl;
	
	if (g.IDDFS(src, target, maxDepth) == true) {	//是否找到目標
		for (int i = 17; i >=0; i--) {
			if(g.arr[i]>0)
			printf("點:%d values:%d\n", g.arr[i], g.arr2[i]);
		}
		cout << "total cost:" <<g.total << endl;
		/*if (src == 0) {
			cout << "Path 'Brest', weight is 0" << endl;
		}
		if (src == 1) {
			cout << "Path 'Rennes', weight is 0" << endl;
		}
		if (src == 2) {
			cout << "Path 'Nantes', weight is 0" << endl;
		}
		if (src == 3) {
			cout << "Path 'Bordeaux', weight is 0" << endl;
		}
		if (src == 4) {
			cout << "Path 'Caen', weight is 0" << endl;
		}
		if (src == 5) {
			cout << "Path 'Limoges', weight is 0" << endl;
		}
		if (src == 6) {
			cout << "Path 'Toulouse', weight is 0" << endl;
		}
		if (src == 7) {
			cout << "Path 'Calais', weight is 0" << endl;
		}
		if (src == 8) {
			cout << "Path 'Paris', weight is 0" << endl;
		}
		if (src == 9) {
			cout << "Path 'Montpellier', weight is 0" << endl;
		}
		if (src == 10) {
			cout << "Path 'Nancy', weight is 0" << endl;
		}
		if (src == 11) {
			cout << "Path 'Dijon', weight is 0" << endl;
		}
		if (src == 12) {
			cout << "Path 'Lyon', weight is 0" << endl;
		}
		if (src == 13) {
			cout << "Path 'Avignon', weight is 0" << endl;
		}
		if (src == 14) {
			cout << "Path 'Marseille', weight is 0" << endl;
		}
		if (src == 15) {
			cout << "Path 'Strasbourg', weight is 0" << endl;
		}
		if (src == 16) {
			cout << "Path 'Grenoble', weight is 0" << endl;
		}
		if (src == 17) {
			cout << "Path 'Nice', weight is 0" << endl;
		}*/
		cout << "The depth is " << g.depth;
	}
	else
		cout << "No answer!!";
	return 0;
}
