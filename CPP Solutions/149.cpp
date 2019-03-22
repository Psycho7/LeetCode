/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        if (points.size() <= 2) return points.size();
        
        sort(points.begin(), points.end(), [](Point a, Point b) {
            if (a.x < b.x) return true;
            if (a.x > b.x) return false;
            return (a.y <= b.y);   
        });
        
        int ans = 0;
        
        for (int i = 0; i < points.size(); i++) {
            if (i > 0) {
                if (points[i - 1].x == points[i].x && points[i - 1].y == points[i].y) {
                    continue;
                }
            }
            if (ans >= points.size() - i) break;
            
            int overlap = 0;
            int local_max = 0;
            unordered_map<int, unordered_map<int, int>> dict;
            
            for (int j = i + 1; j < points.size(); j++) {
                int dx = points[i].x - points[j].x;
                int dy = points[i].y - points[j].y;
                
                if (dx == 0 && dy == 0) {
                    overlap++;
                    continue;
                }
                
                int g = gcd(dx, dy);
                dx = dx / g;
                dy = dy / g;
                
                if (dict.count(dx) == 0) dict[dx] = unordered_map<int, int>();
                dict[dx][dy] = 1 + dict[dx][dy];
                
                local_max = max(local_max, dict[dx][dy]);
            }
            
            ans = max(ans, local_max + overlap + 1);
        }
        
        return ans;
    }
    
    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
};