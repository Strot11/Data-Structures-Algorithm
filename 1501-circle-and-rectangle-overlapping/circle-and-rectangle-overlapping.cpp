class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int px = 0;
        int py = 0;
        if(xCenter<x1) px = x1;
        else if(xCenter>x2) px = x2;
        else px = xCenter;
        if(yCenter<y1) py = y1;
        else if(yCenter>y2) py = y2;
        else py = yCenter;

        return pow(abs(px-xCenter),2) + pow(abs(py-yCenter),2) <= (radius*radius);
    }
};