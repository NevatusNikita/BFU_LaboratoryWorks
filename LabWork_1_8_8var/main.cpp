#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

bool is_vowel(char letter)
{
    char vowels[12] = {'A', 'a', 'E', 'e', 'I', 'i', 'O', 'o', 'U', 'u', 'Y', 'y'};
    for (int i = 0; i < 12; ++i)
    {
        if (letter == vowels[i])
            return true;
    }
    return false;
}

int count_adjacent_vowels(std::string &word)
{
    int c = 0;
    for (int i = 0; i < word.length() - 1; ++i)
    {
        if (is_vowel(word[i]) && is_vowel(word[i + 1]))
            c += 1;
    }
   return c;
}

bool same_vowels(std::string &wrd)
{
    int a_c = 0, e_c = 0, u_c = 0, i_c = 0, o_c = 0, y_c = 0;
    for (int i = 0; i < wrd.length(); ++i)
    {
        switch (wrd[i])
        {
            case 'a': 
                a_c++;
                continue;
            case 'e': 
                e_c++;
                continue;
            case 'i': 
                i_c++;
                continue;
            case 'o': 
                o_c++;
                continue;
            case 'u': 
                u_c++;
                continue;
            case 'y': 
                y_c++;
                continue;
            default:
                continue;
        }
    }
    if (a_c == 2 || e_c == 2 || i_c == 2 || o_c == 2 || u_c == 2 || y_c == 2)
        return true;
    return false;
}

int count_vowels(std::string &word)
{
    int a_c = 0, e_c = 0, u_c = 0, i_c = 0, o_c = 0, y_c = 0;
    for (int i = 0; i < word.length(); ++i)
    {
        switch (word[i])
        {
            case 'a': 
                a_c++;
            case 'e': 
                e_c++;
            case 'i': 
                i_c++;
            case 'o': 
                o_c++;
            case 'u': 
                u_c++;
            case 'y': 
                y_c++;
            default:
                continue;
        }
    }
    return (a_c + e_c + u_c + i_c + y_c + o_c);
}

std::string duplicate_vowels(std::string &word)
{
    std::string new_word = "";
    for (int i = 0; i < word.length(); ++i)
    {
        new_word += word[i];
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' || word[i] == 'o' || 
            word[i] == 'u' || word[i] == 'y')
        {
            new_word += word[i];
        }
    }
    return new_word;
}

std::string remove_conconants(std::string &word)
{
    std::string new_word = "";
    for (int i = 0; i < word.length(); ++i)
    {
        if (word[i] != 's' && word[i] != 'k' && word[i] != 'p' && word[i] != 't' &&
            word[i] != 'f')
        {
            new_word += word[i];
        }
    }
    return new_word;
}

std::vector<std::string> text_to_words(std::vector<std::string> &lines)
{
    std::vector<std::string> cur_words;
    std::string cur_word;
    for (int i = 0; i < lines.size(); ++i)
    {
        cur_word = "";
        for (int j = 0; j < lines[i].size(); ++j)
        {
            if (lines[i][j] != ',' && lines[i][j] != '.' && lines[i][j] != ' ' &&
                lines[i][j] != '!' && lines[i][j] != '?' && lines[i][j] != '"')
                {
                    if (j > 0 && j < lines[i].size())
                    {
                        if (lines[i][j] == '-' && lines[i][j - 1] == ' ' && lines[i][j + 1] == ' ')
                        {
                            j += 2;
                            continue;
                        }
                        else
                            cur_word += lines[i][j];
                    }
                    else
                        cur_word += lines[i][j];
                }
            else
            {
                if (cur_word.length() > 0)
                {
                    cur_words.push_back(cur_word);
                    cur_word = "";
                }
            }
        }
    }
    return cur_words;
}

bool is_letter_in_string(char check_letter, std::string &letters)
{
    for (int i = 0; i < letters.length(); ++i)
    {
        if (check_letter == (char)letters[i])
            return true;
    }
    return false;
}

std::string suitable_word(std::string &word, std::string &letters_in_word)
{
    std::string letters = "";
    for (int i = 0; i < word.length(); ++i)
    {
        if (!is_letter_in_string(word[i], letters_in_word))
        {
            letters += word[i];
        }
    }
    return letters;
}

void word_to_upper(std::string &word)
{
    for (int i = 0; i < word.length(); ++i)
        word[i] = std::toupper(word[i]);
    return;
}

bool is_needed_word(std::string &text_line, int s_i, int e_i, std::string &word)
{
    if ((e_i - s_i + 1) != word.length())
        return false;
    else
    {
        for (int i = 0; i < word.length(); ++i)
        {
            if (word[i] != text_line[s_i + i])
                return false;
        }
        return true;
    }
}

int main()
{
    setlocale(0, "");
    //1
    /*std::string input_path = "C:\\Git\\BFU_LaboratoryWorks\\LabWork_1_8_8var\\input1.txt";
    std::vector<std::string> words;
    std::set<std::string> different_words;
    std::ifstream input(input_path);
    if (input)
    {
        std::string word;
        while (std::getline(input, word))
        {
            words.push_back(word);
        }
    }
    input.close();
    words = text_to_words(words);
    int cur_count = 0;
    std::vector<std::string> suitable_words;
    std::vector<int> counts;
    int N = 1000;
    for (int i = 0; i < words.size(); ++i)
    {
        cur_count = count_adjacent_vowels(words[i]);
        if (cur_count > 0 && different_words.count(words[i]) == 0)
        {
            counts.push_back(cur_count);
            suitable_words.push_back(words[i]);
            different_words.insert(words[i]);
        }
    }
    for (int i = 0; i < suitable_words.size() - 1; ++i)
    {
        for (int j = i + 1; j < suitable_words.size(); ++j)
        {
            if (counts[i] < counts[j])
            {
                std::swap(counts[i], counts[j]);
                std::swap(suitable_words[i], suitable_words[j]);
            }
        }
    }
    std::ofstream out("C:\\Git\\BFU_LaboratoryWorks\\LabWork_1_8_8var\\output1.txt");
    if (out)
    {
        for (int i = 0; i < std::min((int)suitable_words.size(), N); ++i)
        {
            out << suitable_words[i] << '\t' << counts[i] << std::endl;
        }
    }
    out.close();
    words.clear();*/
    //2
    /*
    std::vector<std::string> words;
    std::string input_path = "C:\\Git\\BFU_LaboratoryWorks\\LabWork_1_8_8var\\input2.txt";
    std::ifstream input2(input_path);
    if (input2)
    {
        std::string word;
        while (std::getline(input2, word, ' '))
        {
            words.push_back(word);
        }
    }
    input2.close();
    bool suitablee_word = false;
    for (int i = 0; i < words.size(); ++i)
    {
        if (same_vowels(words[i]))
        {
            suitablee_word = true;
            break;
        }
    }
    for (int i = 0; i < words.size(); ++i)
    {
        if (suitablee_word)
        {
            words[i] = remove_conconants(words[i]);
        }
        else
        {
            if (count_vowels(words[i]) >= 3)
            {
                words[i] = duplicate_vowels(words[i]);
            }
        }
    }
    std::sort(words.begin(), words.end());
    std::ofstream out2("C:\\Git\\BFU_LaboratoryWorks\\LabWork_1_8_8var\\output2.txt");
    if (out2)
    {
        for (int i = 0; i < words.size(); ++i)
        {
            out2 << words[i] << std::endl;
        }
    }
    out2.close();
    words.clear();*/
    //3
    std::vector<std::string> cur_lines;
    std::string input_path = "C:\\Git\\BFU_LaboratoryWorks\\LabWork_1_8_8var\\input3.txt";
    std::ifstream input3(input_path);
    if (input3)
    {
        std::string line;
        while (std::getline(input3, line))
        {
            cur_lines.push_back(line);
        }
    }
    std::vector<std::string> text = cur_lines;
    cur_lines = text_to_words(cur_lines);
    std::vector<std::string> start_cur_lines = cur_lines;
    int max_length = 0;
    for (int i = 0; i < cur_lines.size(); ++i)
    {
        if (max_length < cur_lines[i].length())
        {
            max_length = cur_lines[i].length();
        }
    }
    std::vector<std::string> max_length_words;
    for (int i = 0; i < cur_lines.size(); ++i)
    {
        if (max_length == cur_lines[i].length())
            max_length_words.push_back(cur_lines[i]);
    }
    for (int i=0; i < max_length_words.size(); ++i)
        std::cout << max_length_words[i] << std::endl;
    std::string letters_in_word = "";
    for (int i = 0; i < max_length_words.size(); ++i)
    {
        for (int j = 0; j < max_length; ++j)
        {
            if (!is_letter_in_string(max_length_words[i][j], letters_in_word))
            {
                letters_in_word += max_length_words[i][j];
            }
        }
    }
    std::string suitable_word_letters = "";
    for (int i = 0; i < cur_lines.size(); ++i)
    {
        suitable_word_letters = suitable_word(cur_lines[i], letters_in_word);
        if (suitable_word_letters.length() > 0)
        {
            word_to_upper(cur_lines[i]);
            cur_lines[i] += ("(" + suitable_word_letters + ")");
        }
    }
    std::vector<std::string> new_text;
    std::string word = "";
    unsigned int start_ind = 0;
    unsigned int end_ind = 0;
    int c = 0;
    for (int i = 0; i < text.size(); ++i)
    {
        start_ind = 0;
        end_ind = 0;
        std::string cur_str = "";
        for (int j = 0; j < text[i].length(); ++j)
        {
            if (is_needed_word(text[i], start_ind, end_ind, start_cur_lines[c]))
            {
                cur_str += cur_lines[c];
                if ((c + 1) < start_cur_lines.size())
                    c++;
            }
            if (text[i][j] == ' ' || text[i][j] == '"' || text[i][j] == '.' || text[i][j] == ',' || 
                text[i][j] == '!' || text[i][j] == '?')
            {
                cur_str += text[i][j];
                start_ind = j + 1;
                end_ind = j + 1;
            }
            else
                end_ind++;
        }
        new_text.push_back(cur_str);
    }
    std::ofstream out3("C:\\Git\\BFU_LaboratoryWorks\\LabWork_1_8_8var\\output3.txt");
    if (out3)
    {
        for (int i = 0; i < new_text.size(); ++i)
        {
            out3 << new_text[i] << std::endl;
        }
    }
    out3.close();
}