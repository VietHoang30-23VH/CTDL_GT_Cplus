#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


bool compareByPrice(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

int main() {
    int N, X;
    cin >> N >> X;

    vector<pair<int, int>> items;
    for (int i = 0; i < N; ++i) {
        int price;
        cin >> price;
        items.push_back(make_pair(i + 1, price));
    }

    sort(items.begin(), items.end(), compareByPrice);

    vector<int> chosenItems;
    int totalCost = 0;
    for (int i = 0; i < N; ++i) {
        if (totalCost + items[i].second > X) {
            continue;
        }

        for (int j = i + 1; j < N; ++j) {
            if (totalCost + items[i].second + items[j].second > X) {
                continue;
            }

            for (int k = j + 1; k < N; ++k) {
                if (totalCost + items[i].second + items[j].second + items[k].second > X) {
                    continue;
                }

                for (int l = k + 1; l < N; ++l) {
                    if (totalCost + items[i].second + items[j].second + items[k].second + items[l].second <= X) {
                        chosenItems.push_back(items[i].first);
                        chosenItems.push_back(items[j].first);
                        chosenItems.push_back(items[k].first);
                        chosenItems.push_back(items[l].first);
                        totalCost += items[i].second + items[j].second + items[k].second + items[l].second;
                        break;
                    }
                }

                if (chosenItems.size() == 4) {
                    break;
                }
            }

            if (chosenItems.size() == 4) {
                break;
            }
        }

        if (chosenItems.size() == 4) {
            break;
        }
    }

    if (chosenItems.size() < 4) {
        cout << "Impossible" << endl;
    } else {
        cout << totalCost << endl;
        sort(chosenItems.begin(), chosenItems.end());
        for (int i = 0; i < 4; ++i) {
            cout << chosenItems[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
