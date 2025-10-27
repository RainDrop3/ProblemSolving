/*
 * -1000 <= point <= 1000
 * 1 <= r <= 1000
 * 1 <= n <= 50
 * 각각의 상위원 개수 구하고, 공통상위원은 제외.
 */
#include <iostream>
using namespace std;

bool is_in_circle(int x, int y, int px, int py, int r) {
    return (x-px)*(x-px) + (y-py)*(y-py) <= r*r;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x1, y1, x2, y2, n, cnt = 0;
        cin >> x1 >> y1 >> x2 >> y2 >> n;

        while (n--) {
            int planet_x, planet_y, r;
            cin >> planet_x >> planet_y >> r;
            bool prince = is_in_circle(x1, y1, planet_x, planet_y, r);
            bool flower = is_in_circle(x2, y2, planet_x, planet_y, r);

            if (prince && flower) continue;
            if (prince) cnt++;
            else if (flower) cnt++;
        }
        cout << cnt << '\n';
    }
}