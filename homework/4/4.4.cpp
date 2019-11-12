#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <limits>
#include <iomanip>

struct point {
    float x, y;
    int init_num;
};

bool compare_of_pair(int x_1, int y_1, int x_2, int y_2) {
    if (x_1 < x_2)
        return true;
    else if ((y_1 < y_2) && (x_1 == x_2))
        return true;
    return false;
}

float distance(point p_1, point p_2) {
    return std::sqrt(std::pow(p_1.x - p_2.x, 2) + std::pow(p_1.y - p_2.y, 2));       
}

std::tuple<float, int, int> brute_force(std::vector<point> points) {
    float min = std::numeric_limits<float>::max();
    int p_1 = std::numeric_limits<int>::max(), p_2 = std::numeric_limits<int>::max();
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            int min_num = std::min(points[i].init_num, points[j].init_num);
            int max_num = std::max(points[i].init_num, points[j].init_num);
            if (distance(points[i], points[j]) < min) {
                min = distance(points[i], points[j]);
                p_1 = min_num;
                p_2 = max_num;            }
            else if ((distance(points[i], points[j]) == min) && 
                    (compare_of_pair(min_num, max_num, p_1, p_2))) {
                p_1 = min_num;
                p_2 = max_num;
            }
        }
    }
    return std::make_tuple(min, p_1, p_2);
}

bool x_comparer(point p_1, point p_2) {
    if (p_1.x < p_2.x)
        return true;
    return false;
}

bool y_comparer(point p_1, point p_2) {
    if (p_1.y < p_2.y)
        return true;
    return false;
}

std::tuple<float, int, int> strip_closest(std::vector<point> strip, float dist) {
    float min = dist;
    int p_1 = std::numeric_limits<int>::max(), p_2 = std::numeric_limits<int>::max();
    std::sort(strip.begin(), strip.end(), y_comparer);
    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) <= min; j++) {
            int min_num = std::min(strip[i].init_num, strip[j].init_num);
            int max_num = std::max(strip[i].init_num, strip[j].init_num);
            if (distance(strip[i], strip[j]) < min) {
                min = distance(strip[i], strip[j]);
                p_1 = min_num;
                p_2 = max_num;
            }
            else if ((distance(strip[i], strip[j]) == min) && 
                    (compare_of_pair(min_num, max_num, p_1, p_2))) {
                p_1 = min_num;
                p_2 = max_num;
            }
        }
    }
    return std::make_tuple(min, p_1, p_2);
}


std::tuple<float, int, int> closest_points(std::vector<point> points) {
    if (points.size() <= 3)
        return brute_force(points);
    int mid = points.size() / 2;
    int p_1, p_2;
    point mid_point = points[mid];
    std::vector<point> dl_vec(points.begin(), points.begin() + mid);
    std::vector<point> dr_vec(points.begin() + mid, points.end());
    std::tuple<float, int, int> dl = closest_points(dl_vec);
    std::tuple<float, int, int> dr = closest_points(dr_vec);
    float dist;
    int min_num_dl = std::min(std::get<1>(dl), std::get<2>(dl));
    int max_num_dl = std::max(std::get<1>(dl), std::get<2>(dl));
    int min_num_dr = std::min(std::get<1>(dr), std::get<2>(dr));
    int max_num_dr = std::max(std::get<1>(dr), std::get<2>(dr));
    if (std::get<0>(dr) < std::get<0>(dl)) {
        dist = std::get<0>(dr);
        p_1 = min_num_dr;
        p_2 = max_num_dr;
    }
    else if (std::get<0>(dr) > std::get<0>(dl)) {
        dist = std::get<0>(dl);
        p_1 = min_num_dl;
        p_2 = max_num_dl;
    }
    if (std::get<0>(dr) == std::get<0>(dl)) {
        if (compare_of_pair(min_num_dr, max_num_dr, min_num_dl, max_num_dl)) {
            dist = std::get<0>(dr);
            p_1 = min_num_dr;
            p_2 = max_num_dr;
        }
        else {
            dist = std::get<0>(dl);
            p_1 = min_num_dl;
            p_2 = max_num_dl;
        } 
    }
    std::vector<point> strip;
    for (int i = 0; i < points.size(); i++)
        if (std::abs(points[i].x - mid_point.x) <= dist)
            strip.push_back(points[i]);
    std::tuple<float, int, int> strip_closest_res = strip_closest(strip, dist);
    bool res_of_comp = compare_of_pair(std::get<1>(strip_closest_res), std::get<2>(strip_closest_res), p_1, p_2);
    if (std::get<0>(strip_closest_res) < dist) {
        dist = std::get<0>(strip_closest_res);
        p_1 = std::min(std::get<1>(strip_closest_res), std::get<2>(strip_closest_res));
        p_2 = std::max(std::get<1>(strip_closest_res), std::get<2>(strip_closest_res));
    }
    else if ((std::get<0>(strip_closest_res) == dist) && (res_of_comp)) {
        p_1 = std::min(std::get<1>(strip_closest_res), std::get<2>(strip_closest_res));
        p_2 = std::max(std::get<1>(strip_closest_res), std::get<2>(strip_closest_res));
    }
    return std::make_tuple(dist, p_1, p_2);
}
 

int main() {
    int N;
    double input_1, input_2;
    std::vector<point> points;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> input_1 >> input_2;
        point my_point;
        my_point.x = input_1;
        my_point.y = input_2;
        my_point.init_num = i;
        points.push_back(my_point);
    }
    std::sort(points.begin(), points.end(), x_comparer);
    std::tuple<float, int, int> result = closest_points(points);
    std::cout << std::fixed << std::setprecision(5) << std::get<0>(result) << ' ' 
            << std::get<1>(result) + 1 << ' ' << std::get<2>(result) + 1 << '\n';
    return 0;
}