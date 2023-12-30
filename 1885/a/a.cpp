#include <bits/stdc++.h>

using namespace std;
class user
{
private:
    // 1st vector: resource block group
    // 2nd vector: cell
    // 3rd vector: time interval
    vector<vector<vector<float>>> sinr0;

    // 1st vector: user
    // 2nd vector: resource block group
    // 3rd vector: cell
    vector<vector<vector<float>>> interference;

    size_t id;

public:
    user(size_t user_n, size_t cell_n, size_t tti_n, size_t rbg_n)
    {
        this->sinr0 = vector<vector<vector<float>>>(rbg_n, vector<vector<float>>(cell_n, vector<float>(tti_n, .0f)));
        this->interference = vector<vector<vector<float>>>(user_n, vector<vector<float>>(rbg_n, vector<float>(cell_n, .0f)));
    }

    inline void set_id(size_t id)
    {
        this->id = id;
    }

    inline size_t get_id()
    {
        return this->id;
    }

    inline void set_sinr0(size_t rbg, size_t cell, size_t tti, float sinr0)
    {
        this->sinr0[rbg][cell][tti] = sinr0;
    }

    inline void set_interference(size_t user, size_t rbg, size_t cell, float interference)
    {
        this->interference[user][rbg][cell] = interference;
    }

    inline const float get_sinr0(size_t rbg, size_t cell, size_t tti)
    {
        return this->sinr0[rbg][cell][tti];
    }

    inline const float get_interference(size_t user, size_t rbg, size_t cell)
    {
        return this->interference[user][rbg][cell];
    }

    static vector<user> load_all(size_t user_n, size_t cell_n, size_t tti_n, size_t rbg_n)
    {
        vector<user> users(user_n, user(user_n, cell_n, tti_n, rbg_n));
        for (size_t user = 0; user < user_n; user++)
        {
            users[user].set_id(user);
        }

        float sinr;
        for (size_t tti = 0; tti < tti_n; tti++)
        {
            for (size_t cell = 0; cell < cell_n; cell++)
            {
                for (size_t rbg = 0; rbg < rbg_n; rbg++)
                {
                    for (size_t user = 0; user < user_n; user++)
                    {
                        cin >> sinr;
                        users[user].set_sinr0(rbg, cell, tti, sinr);
                    }
                }
            }
        }

        float interf;
        for (size_t cell = 0; cell < cell_n; cell++)
        {
            for (size_t rbg = 0; rbg < rbg_n; rbg++)
            {
                for (size_t user_m = 0; user_m < user_n; user_m++)
                {
                    for (size_t user = 0; user < user_n; user++)
                    {
                        cin >> interf;
                        users[user].set_interference(user_m, rbg, cell, interf);
                    }
                }
            }
        }

        return users;
    }
};

class frame
{
private:
    ushort id;
    ushort transportBlockSize; // tbs

    size_t user_id;
    size_t t0;
    size_t td;
    size_t t1;

    // 1st vector: resource block group
    // 2nd vector: cell
    // 3rd vector: time interval
    vector<vector<vector<float>>> sinr0;

public:
    frame(vector<user> &users, size_t user_n, size_t rbg_n, size_t cell_n);
    {
        cin >> this->id >> this->transportBlockSize >> this->user_id >> this->t0;
        cin >> this->td;
        this->t1 = this->t0 + this->td - 1;

        for (size_t tti = this->t0; tti <= this->t1; tti++) {
            for (size_t)
        }
    }

    inline ushort get_id()
    {
        return this->id;
    }

    inline ushort get_tbs()
    {
        return this->transportBlockSize;
    }

    inline size_t get_user_id()
    {
        return this->user_id;
    }

    inline size_t get_t0()
    {
        return this->t0;
    }

    inline size_t get_t1()
    {
        return this->t1;
    }

    static vector<frame> load_all(size_t frame_n, vector<user> &users, size_t user_n)
    {
        vector<frame> frames(frame_n);
        for (size_t f; f < frame_n; f++)
        {
            frames[f] = frame(users, user_n);
        }
        return frames;
    }

    static unordered_map<size_t, frame *> get_in_tti(vector<frame> &frames, size_t frame_n, size_t tti)
    {
        unordered_map<size_t, frame *> output;
        for (size_t i = 0; i < frame_n; i++)
        {
            if (frames[i].get_t0() <= tti && frames[i].get_t1() >= tti)
            {
                output[frames[i].get_user_id()] = &frames[i];
            }
        }
        return output;
    }
};

void solve()
{
    size_t user_n, cell_n, tti_n, rbg_n;
    cin >> user_n >> cell_n >> tti_n >> rbg_n;

    vector<user> users = user::load_all(user_n, cell_n, tti_n, rbg_n);

    size_t frame_n;
    cin >> frame_n;

    vector<frame> frames = frame::load_all(frame_n, users, user_n);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
    return 0;
}