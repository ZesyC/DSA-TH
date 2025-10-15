#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// Hash function cho pair<int, int>
struct PairHash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

int main() {
    int n;
    cin >> n;
    
    // Kiểm tra input hợp lệ
    if (n < 4) {
        cout << 0 << endl;
        return 0;
    }
    
    vector<pair<int, int>> diem(n);
    unordered_set<pair<int, int>, PairHash> coTonTai;
    
    for (int i = 0; i < n; i++) {
        cin >> diem[i].first >> diem[i].second;
        coTonTai.insert(diem[i]);
    }
    
    int dem = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int x1 = diem[i].first;
            int y1 = diem[i].second;
            int x2 = diem[j].first;
            int y2 = diem[j].second;
            
            // Kiểm tra tâm có phải số nguyên không
            if ((x1 + x2) % 2 != 0 || (y1 + y2) % 2 != 0) {
                continue;
            }
            
            int tamX = (x1 + x2) / 2;
            int tamY = (y1 + y2) / 2;
            
            int dx = x1 - tamX;
            int dy = y1 - tamY;
            
            // Tính 2 điểm còn lại bằng phép quay 90 độ
            int x3 = tamX - dy;
            int y3 = tamY + dx;
            int x4 = tamX + dy;
            int y4 = tamY - dx;
            
            // Kiểm tra 2 điểm còn lại có tồn tại không
            if (coTonTai.count({x3, y3}) && coTonTai.count({x4, y4})) {
                dem++;
            }
        }
    }
    
    cout << dem / 2 << endl;
    
    return 0;
}