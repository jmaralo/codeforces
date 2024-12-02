#include <bits/stdc++.h>

using namespace std;

class SparseTable {
   private:
    const string_view s;
    const size_t k;
    vector<vector<size_t>> table_open_bracket;
    vector<vector<size_t>> table_close_bracket;

    void fill_table(vector<vector<size_t>> &table, const char c) {
        for (size_t i{0}; i < s.length(); ++i) table[0][i] = s[i] == c ? 1 : 0;

        for (size_t i{1}; i <= k; ++i)
            for (size_t j{0}; j + (1 << i) < s.length(); ++j)
                table[i][j] =
                    table[i - 1][j] + table[i - 1][j + (1 << (i - 1))];
    }

    size_t answer_table(const vector<vector<size_t>> &table, const char c,
                        size_t left, size_t right) {
        size_t sum{0};
        size_t i;
        for (i = k; i > 0; --i) {
            if ((1 << i) <= right - left + 1) {
                sum += table[i][left];
                left += 1 << i;
            }
        }
        if ((1 << i) <= right - left + 1) sum += table[i][left];
        return sum;
    }

   public:
    SparseTable(const string_view s)
        : s(s),
          k(static_cast<size_t>(log2(s.length()))),
          table_open_bracket(k + 1, vector<size_t>(s.length(), 0)),
          table_close_bracket(k + 1, vector<size_t>(s.length(), 0)) {
        fill_table(table_open_bracket, '(');
        fill_table(table_close_bracket, ')');
    }

    SparseTable(const string &s) : SparseTable(string_view(s)) {}

    size_t answer(size_t left, size_t right) {
        while (left < s.length() && left < right && s[left] == ')') ++left;
        while (right > 0 && left < right && s[right] == '(') --right;

        if (left == right) return 0;

        return min(answer_table(table_open_bracket, '(', left, right),
                   answer_table(table_close_bracket, ')', left, right)) *
               2;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string brackets;
    cin >> brackets;
    SparseTable brackets_range(brackets);

    size_t queries;
    cin >> queries;

    for (size_t i{0}; i < queries; i++) {
        size_t left, right;
        cin >> left >> right;
        --left;
        --right;

        cout << brackets_range.answer(left, right) << "\n";
    }

    return 0;
}