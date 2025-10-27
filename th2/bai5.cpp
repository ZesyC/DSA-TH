#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Point {
    int x, y;
};

struct BoundingBox {
    Point points[4];
    
    int getMinX() {
        int minX = points[0].x;
        for (int i = 1; i < 4; i++) {
            minX = min(minX, points[i].x);
        }
        return minX;
    }
    
    int getMaxX() {
        int maxX = points[0].x;
        for (int i = 1; i < 4; i++) {
            maxX = max(maxX, points[i].x);
        }
        return maxX;
    }
    
    int getMinY() {
        int minY = points[0].y;
        for (int i = 1; i < 4; i++) {
            minY = min(minY, points[i].y);
        }
        return minY;
    }
    
    int getMaxY() {
        int maxY = points[0].y;
        for (int i = 1; i < 4; i++) {
            maxY = max(maxY, points[i].y);
        }
        return maxY;
    }
};

double calculateIOU(BoundingBox& box1, BoundingBox& box2) {
    int x1_min = box1.getMinX();
    int x1_max = box1.getMaxX();
    int y1_min = box1.getMinY();
    int y1_max = box1.getMaxY();
    
    int x2_min = box2.getMinX();
    int x2_max = box2.getMaxX();
    int y2_min = box2.getMinY();
    int y2_max = box2.getMaxY();
    
    int x_inter_min = max(x1_min, x2_min);
    int x_inter_max = min(x1_max, x2_max);
    int y_inter_min = max(y1_min, y2_min);
    int y_inter_max = min(y1_max, y2_max);
    
    if (x_inter_min >= x_inter_max || y_inter_min >= y_inter_max) {
        return 0.0;
    }
    
    int intersection = (x_inter_max - x_inter_min) * (y_inter_max - y_inter_min);
    
    int area1 = (x1_max - x1_min) * (y1_max - y1_min);
    int area2 = (x2_max - x2_min) * (y2_max - y2_min);
    
    int unionArea = area1 + area2 - intersection;
    
    double iou = (double)intersection / unionArea;
    return iou;
}

int main() {
    int T;
    cin >> T;
    
    for (int t = 0; t < T; t++) {
        BoundingBox groundTruth, predicted;
        
        for (int i = 0; i < 4; i++) {
            cin >> groundTruth.points[i].x >> groundTruth.points[i].y;
        }
        
        for (int i = 0; i < 4; i++) {
            cin >> predicted.points[i].x >> predicted.points[i].y;
        }
        
        double iou = calculateIOU(groundTruth, predicted);
        cout << fixed << setprecision(5) << iou << endl;
    }
    
    return 0;
}