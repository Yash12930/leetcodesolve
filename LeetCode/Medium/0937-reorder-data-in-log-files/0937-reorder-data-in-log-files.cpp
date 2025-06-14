class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(), logs.end(), [](const string& a, const string& b){
            size_t space_pos_a = a.find(' ');
            size_t space_pos_b = b.find(' ');

            string id_a = a.substr(0, space_pos_a);
            string content_a = a.substr(space_pos_a + 1);

            string id_b = b.substr(0, space_pos_b);
            string content_b = b.substr(space_pos_b + 1);

            bool is_a_letter_log = isalpha(content_a[0]);
            bool is_b_letter_log = isalpha(content_b[0]);
            
            if (is_a_letter_log && is_b_letter_log) {
                if (content_a != content_b) return content_a < content_b;
                return id_a < id_b;
            }

            if (is_a_letter_log && !is_b_letter_log) return true;
            if (!is_a_letter_log && is_b_letter_log) return false;
            return false;
        });

        return logs;
    }
};