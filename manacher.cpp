#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Hàm Manacher để tính bán kính đối xứng của các xâu đối xứng có độ dài lẻ
vector<int> manacher_odd(string s) {
    int n = s.size();
    s = "$" + s + "^";  // Thêm ký tự bảo vệ để tránh lỗi chỉ số ngoài biên
    vector<int> p(n + 2);  // Mảng lưu bán kính đối xứng tại mỗi vị trí
    int l = 0, r = -1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));  // Tận dụng tính chất đối xứng
        while (s[i - p[i]] == s[i + p[i]]) {  // Mở rộng bán kính đối xứng nếu có thể
            p[i]++;
        }
        if (i + p[i] > r) {  // Cập nhật lại biên trái và phải nếu cần
            l = i - p[i];
            r = i + p[i];
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);  // Bỏ các ký tự bảo vệ
}

// Hàm Manacher để tính bán kính đối xứng của các xâu đối xứng có độ dài chẵn
vector<int> manacher_even(string s) {
    int n = s.size();
    s = "$" + s + "^";  // Thêm ký tự bảo vệ
    vector<int> p(n + 1);  // Mảng lưu bán kính đối xứng cho các xâu có độ dài chẵn
    int l = 0, r = -1;
    for (int i = 1; i <= n; i++) {
        p[i] = max(0, min(r - i + 1, p[l + (r - i + 1)]));  // Tận dụng tính chất đối xứng
        while (s[i - p[i] - 1] == s[i + p[i]]) {  // Mở rộng bán kính đối xứng nếu có thể
            p[i]++;
        }
        if (i + p[i] - 1 > r) {  // Cập nhật lại biên trái và phải nếu cần
            l = i - p[i] - 1;
            r = i + p[i] - 1;
        }
    }
    return vector<int>(begin(p) + 1, end(p) - 1);
}

// Hàm tìm tất cả các xâu con đối xứng (cả chẵn và lẻ)
vector<string> findAllPalindromes(const string& s) {
    vector<int> p_odd = manacher_odd(s);  // Tính bán kính đối xứng lẻ
    vector<int> p_even = manacher_even(s);  // Tính bán kính đối xứng chẵn
    vector<string> result;
    int n = s.size();

    // Duyệt qua mỗi vị trí cho xâu đối xứng độ dài lẻ
    for (int i = 0; i < n; i++) {
        // Duyệt qua các bán kính từ 1 đến p_odd[i]
        for (int len = 1; len <= p_odd[i]; len++) {
            int start = i - (len - 1);  // Vị trí bắt đầu của xâu con đối xứng
            result.push_back(s.substr(start, 2 * len - 1));  // Thêm xâu đối xứng độ dài lẻ
        }
    }

    // Duyệt qua mỗi vị trí cho xâu đối xứng độ dài chẵn
    for (int i = 0; i < n; i++) {
        // Duyệt qua các bán kính từ 1 đến p_even[i]
        for (int len = 1; len <= p_even[i]; len++) {
            int start = i - len;  // Vị trí bắt đầu của xâu con đối xứng chẵn
            result.push_back(s.substr(start, 2 * len));  // Thêm xâu đối xứng độ dài chẵn
        }
    }

    return result;
}

int main() {
    string s = "asaaabbrcaacw";
    vector<string> palindromes = findAllPalindromes(s);

    cout << "All Palindromic Substrings (both odd and even lengths):" << endl;
    for (const string& palindrome : palindromes) {
        cout << palindrome << endl;
    }

    return 0;
}
