#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



typedef long long ll;



struct Edge {

    ll to, id;



    Edge(ll to, ll id) : to(to), id(id) {}

};



ll n, m;

vector<vector<Edge>> graph;

vector<bool> deleted;

vector<ll> degree;

vector<ll> mark;

vector<ll> way;



void euler(ll from) {

    while (mark[from] < ll(graph[from].size())) {

        Edge edge = graph[from][mark[from]++];

        if (!deleted[edge.id]) {

            deleted[edge.id] = true;

            euler(edge.to);

        }

    }



    way.push_back(from);

}



bool createWay(ll start) {

    way.clear();

    vector<ll> odd;

    for (ll i = 0; i < n; ++i) {

        if (degree[i] & 1) {

            odd.push_back(i);

        }

    }



    if (odd.size() > 2) {

        return false;

    }



    if (!odd.empty()) {

        if (!count(odd.begin(), odd.end(), start)) {

            return false;

        }

    }



    euler(start);

    if (odd.empty()) {

        ll cycleBegin = 0;

        for (ll i = 0; i < ll(way.size()); ++i) {

            if (way[i] == start) {

                cycleBegin = i;

                break;

            }

        }



        vector<ll> newWay;

        for (ll i = cycleBegin; i < ll(way.size()); ++i) {

            newWay.push_back(way[i]);

        }



        for (ll i = 0; i < cycleBegin; ++i) {

            newWay.push_back(way[i]);

        }



        way = newWay;

    }



    for (auto &item: mark) {

        item = 0;

    }



    return true;

}



void resolve() {

    cin >> n >> m;

    graph.resize(n);

    mark.resize(n);

    degree.resize(n);

    deleted.resize(m);

    for (ll i = 0; i < m; ++i) {

        ll v, u;

        cin >> v >> u;

        --v;

        --u;

        graph[v].emplace_back(u, i);

        graph[u].emplace_back(v, i);

        ++degree[v];

        ++degree[u];

    }



    for (ll start = 0; start < n; ++start) {

        vector<ll> usedNei;

        vector<Edge> mayDelete;

        for (auto &edge: graph[start]) {

            if (degree[edge.to] & 1) {

                --degree[edge.to];

                --degree[start];

                deleted[edge.id] = true;

                usedNei.push_back(edge.to);

                mayDelete.push_back(edge);

            }

        }



        if (createWay(start)) {

            bool found = true;

            for (int i = 0; i < m; ++i) {

                if (!deleted[i]) {

                    found = false;

                }

            }



            if (found) {

                vector<ll> res;

                for (const auto &item: way) {

                    res.push_back(item);

                }



                if (!usedNei.empty()) {

                    res.push_back(-2);



                    for (const auto &item: usedNei) {

                        res.push_back(item);

                        res.push_back(start);

                    }

                }



                cout << res.size() << '\n';

                for (const auto &item: res) {

                    cout << item + 1 << ' ';

                }



                cout << '\n';

                return;

            }

        }



        for (const auto &may: mayDelete) {

            usedNei.clear();

            for (ll i = 0; i < n; ++i) {

                deleted[i] = false;

            }



            for (const auto &e: mayDelete) {

                if (e.id != may.id) {

                    usedNei.push_back(e.to);

                    deleted[e.id] = true;

                }

            }



            ++degree[start];

            ++degree[may.to];



            if (createWay(start)) {

                bool found = true;

                for (int i = 0; i < m; ++i) {

                    if (!deleted[i]) {

                        found = false;

                    }

                }



                if (found) {

                    vector<ll> res;

                    for (const auto &item: way) {

                        res.push_back(item);

                    }



                    if (!usedNei.empty()) {

                        res.push_back(-2);



                        for (const auto &item: usedNei) {

                            res.push_back(item);

                            res.push_back(start);

                        }

                    }



                    cout << res.size() << '\n';

                    for (const auto &item: res) {

                        cout << item + 1 << ' ';

                    }



                    cout << '\n';

                    return;

                }

            }



            --degree[start];

            --degree[may.to];

        }



        for (auto &edge: mayDelete) {

            ++degree[edge.to];

            ++degree[start];

            deleted[edge.id] = false;

        }



        for (ll i = 0; i < n; ++i) {

            deleted[i] = false;

        }

    }



    cout << "0\n";

}



int32_t main() {

    ios_base::sync_with_stdio(false);

    cin.tie(nullptr);

    cout.tie(nullptr);



    resolve();



    return 0;

}