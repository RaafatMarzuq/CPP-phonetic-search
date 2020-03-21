#include "PhoneticFinder.hpp"
#include <iostream>

namespace phonetic
{
int isMixed(char t, char w)
{
    t = tolower(t);
    w = tolower(w);

    if (t == w)
        return 1;
    if ((t == 'w' && w == 'v') || (t == 'v' && w == 'w'))
        return 1;
    if ((t == 'g' && w == 'j') || (t == 'j' && w == 'g'))
        return 1;
    if ((t == 's' && w == 'z') || (t == 'z' && w == 's'))
        return 1;
    if ((t == 'd' && w == 't') || (t == 't' && w == 'd'))
        return 1;
    if ((t == 'o' && w == 'u') || (t == 'u' && w == 'o'))
        return 1;
    if ((t == 'i' && w == 'y') || (t == 'y' && w == 'i'))
        return 1;
    if ((t == 'b' && w == 'f') || (t == 'f' && w == 'b'))
        return 1;
    if ((t == 'b' && w == 'p') || (t == 'p' && w == 'b'))
        return 1;
    if ((t == 'p' && w == 'f') || (t == 'f' && w == 'p'))
        return 1;
    if ((t == 'c' && w == 'k') || (t == 'k' && w == 'c'))
        return 1;
    if ((t == 'c' && w == 'q') || (t == 'q' && w == 'c'))
        return 1;
    if ((t == 'q' && w == 'k') || (t == 'k' && w == 'q'))
        return 1;

    return 0;
}

string find(string text, string word)
{
    string str = "";
    int j = 0;
    size_t i = 0;
    for (i = 0; i < text.length(); i++)
    {
        if (text[i] == ' ')
        {
            if (str.length() != word.length())
            {
                str = "";
                i++;
                j = 0;
            }
            else
                return str;
        }

        else if (( word.length() != j) && (text[i], word[j]))
        {
            str += text[i];
            j++;
            cout << j << endl;
        }
        else
        {
            j = 0;
            str = "";
            while (text[i] != ' ')
            {
                i++;
            }
        }
    }
  if ((text.length() == i) && (word.length() != str.length()))
        {
            {
                throw string("Word not found");
            }
        }
    return str;
}
} // namespace phonetic