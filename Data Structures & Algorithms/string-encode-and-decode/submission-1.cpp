class Solution {
public:

    string encode(vector<string>& strs) {
        std::string ans{};
        std::string delim{"$"};
        for (auto str : strs) {
            ans += std::to_string(str.size()) + delim + str;
        }
        return ans;
    }

    vector<string> decode(string s) {
        std::vector<std::string> words{};

        std::stringstream ss{s};

        int num_chars;
        char char_dump;
        while (ss >> num_chars) {
            std::string msg_buffer(num_chars, '\0');
            ss >> char_dump;
            ss.read(msg_buffer.data(), num_chars);
            words.push_back(msg_buffer);
        }
        return words;
    }
};
