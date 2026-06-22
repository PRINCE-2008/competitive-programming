#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

const int INF = 1e9;

// Directions: 0=Right, 1=Down, 2=Left, 3=Up
int dr[] = {0, 1, 0, -1};
int dc[] = {1, 0, -1, 0};

struct State {
    int r, c, dir;
};

int N, M, T;
vector<string> v;
vector<string> h;

struct Target {
    int br, bc, dr, dc;
    bool completed = false;
};
vector<Target> targets;

// Check if moving forward is possible without hitting a grid edge or wall
bool can_move(int r, int c, int dir) {
    if (dir == 0) { // Right
        return c < N - 1 && v[r][c] == '0';
    } else if (dir == 1) { // Down
        return r < N - 1 && h[r][c] == '0';
    } else if (dir == 2) { // Left
        return c > 0 && v[r][c - 1] == '0';
    } else if (dir == 3) { // Up
        return r > 0 && h[r - 1][c] == '0';
    }
    return false;
}

// BFS to find the shortest string of basic operations to get from start to end coordinates
string get_path(int sr, int sc, int sdir, int er, int ec, int &final_dir) {
    if (sr == er && sc == ec) {
        final_dir = sdir;
        return "";
    }

    vector<vector<vector<int>>> dist(N, vector<vector<int>>(N, vector<int>(4, INF)));
    vector<vector<vector<tuple<int, int, int, char>>>> parent(N, vector<vector<tuple<int, int, int, char>>>(N, vector<tuple<int, int, int, char>>(4)));
    
    queue<State> q;
    q.push({sr, sc, sdir});
    dist[sr][sc][sdir] = 0;

    bool found = false;
    int end_dir = -1;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();

        if (curr.r == er && curr.c == ec) {
            found = true;
            end_dir = curr.dir;
            break; 
        }

        // Action: Move Forward (F)
        if (can_move(curr.r, curr.c, curr.dir)) {
            int nr = curr.r + dr[curr.dir];
            int nc = curr.c + dc[curr.dir];
            if (dist[nr][nc][curr.dir] > dist[curr.r][curr.c][curr.dir] + 1) {
                dist[nr][nc][curr.dir] = dist[curr.r][curr.c][curr.dir] + 1;
                parent[nr][nc][curr.dir] = {curr.r, curr.c, curr.dir, 'F'};
                q.push({nr, nc, curr.dir});
            }
        }

        // Action: Turn Right (R)
        int ndir_R = (curr.dir + 1) % 4;
        if (dist[curr.r][curr.c][ndir_R] > dist[curr.r][curr.c][curr.dir] + 1) {
            dist[curr.r][curr.c][ndir_R] = dist[curr.r][curr.c][curr.dir] + 1;
            parent[curr.r][curr.c][ndir_R] = {curr.r, curr.c, curr.dir, 'R'};
            q.push({curr.r, curr.c, ndir_R});
        }

        // Action: Turn Left (L)
        int ndir_L = (curr.dir + 3) % 4;
        if (dist[curr.r][curr.c][ndir_L] > dist[curr.r][curr.c][curr.dir] + 1) {
            dist[curr.r][curr.c][ndir_L] = dist[curr.r][curr.c][curr.dir] + 1;
            parent[curr.r][curr.c][ndir_L] = {curr.r, curr.c, curr.dir, 'L'};
            q.push({curr.r, curr.c, ndir_L});
        }
    }

    // Reconstruct path
    string path = "";
    int cr = er, cc = ec, cdir = end_dir;
    final_dir = end_dir;

    while (cr != sr || cc != sc || cdir != sdir) {
        auto p = parent[cr][cc][cdir];
        path += get<3>(p);
        cr = get<0>(p);
        cc = get<1>(p);
        cdir = get<2>(p);
    }
    
    reverse(path.begin(), path.end());
    return path;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> M >> T)) return 0;

    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];

    h.resize(N - 1);
    for (int i = 0; i < N - 1; ++i) cin >> h[i];

    targets.resize(M);
    for (int i = 0; i < M; ++i) {
        cin >> targets[i].br >> targets[i].bc >> targets[i].dr >> targets[i].dc;
    }

    string total_operations = "";
    int curr_r = 0, curr_c = 0, curr_dir = 0;

    // Greedy Delivery Loop
    for (int step = 0; step < M; ++step) {
        int best_target = -1;
        int min_dist = INF;
        string best_path_to_ball = "";
        int dir_at_ball = -1;

        // Find the closest unpicked ball
        for (int i = 0; i < M; ++i) {
            if (!targets[i].completed) {
                int temp_dir;
                string path = get_path(curr_r, curr_c, curr_dir, targets[i].br, targets[i].bc, temp_dir);
                if (path.length() < min_dist) {
                    min_dist = path.length();
                    best_target = i;
                    best_path_to_ball = path;
                    dir_at_ball = temp_dir;
                }
            }
        }

        if (best_target == -1) break; 

        // Execute route to ball
        total_operations += best_path_to_ball;
        total_operations += "S"; // Pick up ball
        curr_r = targets[best_target].br;
        curr_c = targets[best_target].bc;
        curr_dir = dir_at_ball;

        // Route from ball to its respective basket
        int dir_at_basket;
        string path_to_basket = get_path(curr_r, curr_c, curr_dir, targets[best_target].dr, targets[best_target].dc, dir_at_basket);
        
        total_operations += path_to_basket;
        total_operations += "S"; // Drop off ball
        curr_r = targets[best_target].dr;
        curr_c = targets[best_target].dc;
        curr_dir = dir_at_basket;

        targets[best_target].completed = true;
    }

    // Output trimming to respect maximum basic operations limit T
    if (total_operations.length() > T) {
        total_operations = total_operations.substr(0, T);
    }

    cout << total_operations << "\n";

    return 0;
}