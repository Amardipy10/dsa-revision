class Robot {
    int w, h, p, pos;
    bool moved;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        p = 2 * (w + h - 2);
        pos = 0;
        moved = false;
    }

    void step(int num) {
        moved = true;
        pos = (pos + num) % p;
    }

    vector<int> getPos() {
        if (pos < w) return {pos, 0};
        if (pos < w + h - 1) return {w - 1, pos - (w - 1)};
        if (pos < 2 * w + h - 2) return {w - 1 - (pos - (w + h - 2)), h - 1};
        return {0, h - 1 - (pos - (2 * w + h - 3))};
    }

    string getDir() {
        if (!moved || pos == 0) return moved ? "South" : "East";
        if (pos < w) return "East";
        if (pos < w + h - 1) return "North";
        if (pos < 2 * w + h - 2) return "West";
        return "South";
    }
};