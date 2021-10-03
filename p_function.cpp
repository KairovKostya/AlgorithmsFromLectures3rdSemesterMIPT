#include <iostream>
#include <vector>
 
std::vector<int> p_function(const std::string &text) {
    int n = text.size();
    std::vector<int> p(n);
    for (int i = 1; i < n; ++i) {
        int j = p[i - 1];
        while (j > 0 && text[j] != text[i]) {
            j = p[j - 1];
        }
        if (text[j] == text[i]) ++j;
        p[i] = j;
    }
    return p;
}
