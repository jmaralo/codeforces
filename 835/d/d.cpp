#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    size_t answer{0};

    // Tells if a substring of length i starting at index j is a palindrome
    vector<vector<bool>> palindromes(s.length(),
                                     vector<bool>(s.length(), false));

    // Find all k = 1 palindromes
    for (size_t length{0}; length < s.length(); ++length) {
        for (size_t offset{0}; offset + length < s.length(); ++offset) {
            size_t l{offset}, r{offset + length};
            bool palindrome{true};
            while (r > l) {
                if (s[r] != s[l]) {
                    palindrome = false;
                    break;
                }
                ++l;
                --r;
            }

            if (palindrome) {
                ++answer;
                palindromes[length][offset] = true;
            }
        }
    }
    cout << answer << " ";

    // Changes to the original palindromes might affect the next step
    vector<vector<bool>> next_palindromes(s.length(),
                                          vector<bool>(s.length(), false));

    // Compute k > 1 palindromes
    for (size_t k{1}; k < s.length(); ++k) {
        answer = 0;
        for (size_t length{k}; length < s.length(); ++length) {
            for (size_t offset{0}; offset + length < s.length(); ++offset) {
                size_t h_length{((length + 1) / 2) - 1};
                if (!(palindromes[h_length][offset] &&
                      palindromes[h_length][offset + length - h_length]))
                    continue;
    
                string_view l{s}, r{s};
                if (l.substr(offset, h_length + 1) ==
                    r.substr(offset + length - h_length, h_length + 1)) {
                    ++answer;
                    next_palindromes[length][offset] = true;
                }
            }
        }
        palindromes = next_palindromes;
        for (auto &v : next_palindromes) {
            fill(v.begin(), v.end(), false);
        }
        cout << answer << " ";
    }

    cout << "\n";

    return 0;
}